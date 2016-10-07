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
    , m_faces()
{
    const unsigned int numMesh = m_scene->mNumMeshes;
    // Pour chaque objets de la scène
    for (unsigned int m = 0 ; m < numMesh ; ++m)
    {
        const aiMesh* mesh = m_scene->mMeshes[m];

        std::vector< GLfloat* > meshVertices;

        /// Traite les vertices
        const unsigned int numVertices = mesh->mNumVertices;
        // Pour chaque sommet du mesh
        for (unsigned int v = 0 ; v < numVertices ; ++v)
        {
            aiVector3D& pos = mesh->mVertices[v];

            // Utilise les données d'Assimp sans copie
            // ATTENTION: Il est nécessaire que les GLfloat et les float aient la même taille
            // sur la machine utilisée pour compiler. Ce qui est généralement le cas sur les architectures
            // actuelles. En effet, on se base sur la principe qui fait
            // que les données membres d'une classe sont contigues en mémoire.
            meshVertices.push_back( (GLfloat*) &(pos.x) );
        }

        m_vertices.push_back(meshVertices);

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
                                                  aiProcess_SortByPType);

    // If the import failed, report it
    if (!scene)
    {
        std::cerr << "Impossible to import scene: " << sceneFilename << std::endl << " Reason : " << m_importer.GetErrorString() << std::endl;

        return nullptr;
    }

    return scene;
}

GLenum AssimpLoader::modes(int meshIndex) const
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

const std::vector< std::vector<unsigned int> >& AssimpLoader::faces(int meshIndex) const
{
    return m_faces[meshIndex];
}
