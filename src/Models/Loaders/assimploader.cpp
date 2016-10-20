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
#endif

#include <assimp/scene.h>           // Output data structure
#include <assimp/postprocess.h>     // Post processing flags

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif

AssimpLoader::AssimpLoader(const std::string& sceneFilename)
    : Loader()
    , m_importer()
    , m_scene(loadScene(sceneFilename))
    , m_vertices()
    , m_normals()
    , m_faces()
    , m_materials()
    , m_meshMaterials()
{
    const unsigned int numMesh = m_scene->mNumMeshes;
    // Pour chaque objets de la scène
    for (unsigned int m = 0 ; m < numMesh ; ++m)
    {
        const aiMesh* mesh = m_scene->mMeshes[m];

        std::vector< GLfloat* > meshVertices;
        std::vector< GLfloat* > meshNormals;

        /// Traite les vertices
        const unsigned int numVertices = mesh->mNumVertices;
        // Pour chaque sommet du mesh on récupère les coordonnées du sommet et de sa normale
        for (unsigned int v = 0 ; v < numVertices ; ++v)
        {
            aiVector3D& pos = mesh->mVertices[v];
            aiVector3D& norm = mesh->mNormals[v];

            // Utilise les données d'Assimp sans copie
            // ATTENTION: Il est nécessaire que les GLfloat et les float aient la même taille
            // sur la machine utilisée pour compiler. Ce qui est généralement le cas sur les architectures
            // actuelles. En effet, on se base sur la principe qui fait
            // que les données membres d'une classe sont contigues en mémoire.
            meshVertices.push_back( (GLfloat*) &(pos.x) );
            meshNormals.push_back( (GLfloat*) &(norm.x) );
        }

        m_vertices.push_back(meshVertices);
        m_normals.push_back(meshNormals);

        /// Traite les faces
        const unsigned int numFaces = mesh->mNumFaces;
        std::vector< std::vector<unsigned int> > meshFaces;

        // Pour chaque face de l'objet
        for (unsigned int f = 0 ; f < numFaces ; ++f)
        {
            const aiFace& face = mesh->mFaces[f];

            std::vector<unsigned int> faceVertices( &(face.mIndices[0]),
                                                    &(face.mIndices[0]) + face.mNumIndices);

            meshFaces.push_back(faceVertices);
        }

        m_faces.push_back(meshFaces);

        // Indice du matériau du maillage
        m_meshMaterials.push_back(mesh->mMaterialIndex);
    }

    /// Traite les matériaux
    const unsigned int numMaterials = m_scene->mNumMaterials;
    // Pour chaque matériau
    for (unsigned int m = 0 ; m < numMaterials ; ++m)
    {
        const aiMaterial* mat = m_scene->mMaterials[m];

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

AssimpLoader::~AssimpLoader()
{
}

const aiScene* AssimpLoader::loadScene(const std::string& sceneFilename)
{
    const aiScene* scene = m_importer.ReadFile(   sceneFilename,
                                                  aiProcess_FindDegenerates |
                                                  aiProcess_Triangulate     |
                                                  aiProcess_SortByPType     |
                                                  aiProcess_GenNormals);

    // If the import failed, report it
    if (!scene)
    {
        std::cerr << "Impossible to import scene: " << sceneFilename << std::endl << " Reason : " << m_importer.GetErrorString() << std::endl;

        return nullptr;
    }

    return scene;
}

GLenum AssimpLoader::mode(int meshIndex) const
{
    GLenum ret = GL_POINTS;

    switch (m_scene->mMeshes[meshIndex]->mPrimitiveTypes)
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

unsigned int AssimpLoader::meshCount() const
{
    return m_scene->mNumMeshes;
}

const std::vector< GLfloat* >& AssimpLoader::vertices(int meshIndex) const
{
    return m_vertices[meshIndex];
}

const std::vector< GLfloat* >& AssimpLoader::normals(int meshIndex) const
{
    return m_normals[meshIndex];
}

const std::vector< std::vector<unsigned int> >& AssimpLoader::faces(int meshIndex) const
{
    return m_faces[meshIndex];
}

const Material& AssimpLoader::material(int meshIndex) const
{
    return m_materials[ m_meshMaterials[meshIndex] ];
}
