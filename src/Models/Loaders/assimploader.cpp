/******************************************************************************\
*     Copyright (C) 2016 by Alexandre Rabérin                                  *
*                                                                              *
* The program is distributed under the terms of the GNU General Public License *
*                                                                              *
\******************************************************************************/

#include "assimploader.h"

#include <iostream>

#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"
#pragma GCC diagnostic ignored "-Wconversion"
#pragma GCC diagnostic ignored "-Wfloat-equal"
#endif

#include <assimp/Importer.hpp>      // C++ importer interface
#include <assimp/scene.h>           // Output data structure
#include <assimp/postprocess.h>     // Post processing flags

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif

#include "Graph/drawablenode.h"
#include "Models/Renders/rendermodel.h"
#include "Shaders/shadercollection.h"

AssimpLoader::AssimpLoader(const std::string& sceneFilename)
    : Loader()
    , m_nbMesh(0)
    , m_modes()
    , m_vertices()
    , m_normals()
    , m_faces()
    , m_materials()
    , m_meshMaterials()
    , m_texCoords()
{
    loadScene(sceneFilename);
}

AssimpLoader::~AssimpLoader()
{
}

void AssimpLoader::loadScene(const std::string& sceneFilename)
{
    Assimp::Importer importer;
    const aiScene* scene = importer.ReadFile(   sceneFilename,
                                                aiProcess_FindDegenerates |
                                                aiProcess_Triangulate     |
                                                aiProcess_SortByPType     |
                                                aiProcess_GenNormals);

    // If the import succeed load scene
    if (scene)
    {
        const unsigned int numMesh = m_nbMesh = scene->mNumMeshes;
        // Pour chaque objets de la scène
        for (unsigned int m = 0 ; m < numMesh ; ++m)
        {
            const aiMesh* mesh = scene->mMeshes[m];

            /// Récupère le mode de dessin du mesh
            m_modes.push_back(getMode(mesh->mPrimitiveTypes));

            /// Traite les vertices, normales et coordonnées de texture
            std::vector< GLfloat > meshVertices;
            std::vector< GLfloat > meshNormals;
            std::vector< GLfloat > meshTexCoords;

            const unsigned int numVertices = mesh->mNumVertices;
            // Pour chaque sommet du mesh
            for (unsigned int v = 0 ; v < numVertices ; ++v)
            {
                aiVector3D& pos = mesh->mVertices[v];
                meshVertices.push_back(pos.x);
                meshVertices.push_back(pos.y);
                meshVertices.push_back(pos.z);

                aiVector3D& normal = mesh->mNormals[v];
                meshNormals.push_back(normal.x);
                meshNormals.push_back(normal.y + float(std::rand()%100));
                meshNormals.push_back(normal.z + float(std::rand()%100));
            }

            // S'il y a des coordonnées de texture
            if (mesh->mTextureCoords[0])
            {
                // Pour chaque sommet du mesh
                for (unsigned int v = 0 ; v < numVertices ; ++v)
                {
                    aiVector3D& tex = mesh->mTextureCoords[0][v];
                    meshTexCoords.push_back(tex.x);
                    meshTexCoords.push_back(tex.y);
                }
            }

            m_vertices.push_back(meshVertices);
            m_normals.push_back(meshNormals);
            m_texCoords.push_back(meshTexCoords);

            /// Traite les faces
            const unsigned int numFaces = mesh->mNumFaces;
            std::vector< unsigned int > meshFaces;

            // Pour chaque face de l'objet
            for (unsigned int f = 0 ; f < numFaces ; ++f)
            {
                const aiFace& face = mesh->mFaces[f];

                std::copy(face.mIndices, face.mIndices + face.mNumIndices, std::back_inserter(meshFaces));
            }

            m_faces.push_back(meshFaces);

            // Indice du matériau du maillage
            m_meshMaterials.push_back(mesh->mMaterialIndex);
        }

        /// Traite les matériaux
        const unsigned int numMaterials = scene->mNumMaterials;
        // Pour chaque matériau
        for (unsigned int m = 0 ; m < numMaterials ; ++m)
        {
            const aiMaterial* mat = scene->mMaterials[m];

            aiColor3D ambiant(0.0f, 0.0f, 0.0f);
            aiColor3D diffuse(0.0f, 0.0f, 0.0f);
            aiColor3D specular(0.0f, 0.0f, 0.0f);
            float shininess = 0.0f;

            // Récupère les valeurs du matériau
            if (AI_SUCCESS == mat->Get(AI_MATKEY_COLOR_AMBIENT, ambiant)
                && AI_SUCCESS == mat->Get(AI_MATKEY_COLOR_DIFFUSE, diffuse)
                && AI_SUCCESS == mat->Get(AI_MATKEY_COLOR_SPECULAR, specular)
                && AI_SUCCESS == mat->Get(AI_MATKEY_SHININESS, shininess))
            {
                // Construit le matériau correspondant
                m_materials.push_back(Material( ambiant.r, ambiant.g, ambiant.b,
                                                diffuse.r, diffuse.g, diffuse.b,
                                                specular.r, specular.g, specular.b,
                                                shininess));
            }
            // Cas où il y a eu un echec lors de la récupération des propriétés du matériau
            // Ne devrait pas arriver
            else
            {
                // Place un matériau par défaut
                m_materials.push_back(Material());
            }
        }
    }
    // Import failed => report it
    else
    {
        std::cerr << "Impossible to import scene: " << sceneFilename << std::endl << " Reason : " << importer.GetErrorString() << std::endl;
    }
}

GLenum AssimpLoader::getMode(unsigned int assimpMode)
{
    GLenum ret = GL_POINTS;

    switch (assimpMode)
    {
    case aiPrimitiveType_LINE:
        ret = GL_LINES;
        break;
    case aiPrimitiveType_TRIANGLE:
        ret = GL_TRIANGLES;
        break;
    case aiPrimitiveType_POLYGON:
        ret = GL_POLYGON;
        break;
    default:
        ret = GL_POINTS;
        break;
    }

    return ret;
}

GLenum AssimpLoader::mode(int meshIndex) const
{
    return m_modes[meshIndex];
}

unsigned int AssimpLoader::meshCount() const
{
    return m_nbMesh;
}

const std::vector< GLfloat >& AssimpLoader::vertices(int meshIndex) const
{
    return m_vertices[meshIndex];
}

const std::vector< GLfloat >& AssimpLoader::normals(int meshIndex) const
{
    return m_normals[meshIndex];
}

const std::vector< unsigned int >& AssimpLoader::faces(int meshIndex) const
{
    return m_faces[meshIndex];
}

const Material& AssimpLoader::materials(int meshIndex) const
{
    return m_materials[meshIndex];
}

const std::vector< GLfloat >& AssimpLoader::texCoords(int meshIndex) const
{
    return m_texCoords[meshIndex];
}

std::shared_ptr<Node> AssimpLoader::getGraph() const
{
    std::shared_ptr<Node> graph(new Node);

    for (unsigned int i = 0 ; i < m_vertices.size() ; ++i)
    {
        std::shared_ptr<RenderModel> model(new RenderModel(ShaderCollection::getShader("default"), *this, i));
        graph->addChild(std::shared_ptr<Node>(new DrawableNode(model)));
    }

    return graph;
}
