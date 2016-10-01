/******************************************************************************\
*     Copyright (C) 2016 by Alexandre Rabérin                                  * 
*                                                                              * 
* The program is distributed under the terms of the GNU General Public License * 
*                                                                              * 
\******************************************************************************/

#include "renderingmodel.h"

#include <iostream>

#include <assimp/Importer.hpp>      // C++ importer interface
#include <assimp/scene.h>           // Output data structure
#include <assimp/postprocess.h>     // Post processing flags

RenderingModel::RenderingModel(const std::string& sceneFilename)
    // Read the given file with some example postprocessing
    : m_scene(loadScene(sceneFilename))
{
}

RenderingModel::~RenderingModel()
{
    delete m_scene;
}

const aiScene* RenderingModel::loadScene(const std::string& sceneFilename)
{
    Assimp::Importer importer;

    const aiScene* scene = importer.ReadFile( sceneFilename,
                                              aiProcess_FindDegenerates |
                                              aiProcess_Triangulate     |
                                              aiProcess_SortByPType);

    // If the import failed, report it
    if (!scene)
    {
        std::cerr << "Impossible to import scene: " << sceneFilename << std::endl << " Reason : " << importer.GetErrorString() << std::endl;

        return nullptr;
    }

    return importer.GetOrphanedScene();
}

void RenderingModel::init()
{
    // Réglage de la couleur de fond
    glClearColor(0.0, 0.0, 0.0, 1.0);

    // Elimination des parties cachées
    //glEnable(GL_DEPTH_TEST);
    // Active l'éclairage
    //glEnable(GL_LIGHTING);
    // Modèle local
    //glLightModelf(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
    // Lissage de Phong
    //glShadeModel(GL_SMOOTH);

    // Intensité de la lumière ambiante
    //GLfloat sceneAmbientIntensity[] = { 0.2f, 0.2f, 0.2f, 1.0f };
    //glLightModelfv(GL_LIGHT_MODEL_AMBIENT, sceneAmbientIntensity);
}

void RenderingModel::initView()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void RenderingModel::applyLightPointPosition(GLint lightId, const GLfloat position[4])
{
    glLightfv(lightId, GL_POSITION, position);
}

void RenderingModel::applyLightPointIntensity(  GLint lightId,
                                                const GLfloat diffuseIntensity[4],
                                                const GLfloat specularIntensity[4])
{
    glLightfv(lightId, GL_DIFFUSE, diffuseIntensity);
    glLightfv(lightId, GL_SPECULAR, specularIntensity);
    glEnable(lightId);
}

void RenderingModel::disableLightPoint(GLint lightId)
{
    glDisable(lightId);
}

void RenderingModel::applyMaterial(/* Material material */)
{
    // TODO later
}

void RenderingModel::drawScene()
{
    glBegin(GL_LINES);

    const unsigned int numMesh = m_scene->mNumMeshes;
    // Pour chaque objets de la scène
    for (unsigned int m = 0 ; m < numMesh ; ++m)
    {
        const aiMesh* mesh = m_scene->mMeshes[m];
        const unsigned int numFaces = mesh->mNumFaces;

        // Pour chaque face de l'objet
        for (unsigned int f = 0 ; f < numFaces ; ++f)
        {
            const aiFace& face = mesh->mFaces[f];
            const unsigned int numVertice = face.mNumIndices;

            // Pour chaque sommet de la face
            for (unsigned int v = 0 ; v < numVertice ; ++v)
            {
                aiVector3D pos = mesh->mVertices[ face.mIndices[v] ];

                glVertex3f(GLfloat(pos.x), GLfloat(pos.y), GLfloat(pos.z));
            }
        }
    }

    glEnd();
}
