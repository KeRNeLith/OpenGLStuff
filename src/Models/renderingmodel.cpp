/******************************************************************************\
*     Copyright (C) 2016 by Alexandre Rabérin                                  * 
*                                                                              * 
* The program is distributed under the terms of the GNU General Public License * 
*                                                                              * 
\******************************************************************************/

#include "renderingmodel.h"

#include <iostream>

#include "Loaders/assimploader.h"

RenderingModel::RenderingModel(const std::string& sceneFilename)
    // Read the given file with some example postprocessing
    : m_object(new AssimpLoader(sceneFilename))
{
}

RenderingModel::~RenderingModel()
{
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

    const auto numMesh = m_object->meshCount();
    // Pour chaque objets de la scène
    for (unsigned int m = 0 ; m < numMesh ; ++m)
    {
        // Tableaux des vertices et des faces du mesh traité
        const auto& vertices = m_object->vertices(m);
        const auto& faces = m_object->faces(m);

        // Nombre de face du mesh
        const auto numFaces = faces.size();

        // Pour chaque face de l'objet
        for (unsigned int f = 0 ; f < numFaces ; ++f)
        {
            // Face courante
            const auto& face = faces[f];

            // Nombre de vertices de la face
            const auto numVertice = face.size();

            // Pour chaque sommet de la face place le sommet dans la scène 3D
            for (unsigned int v = 0 ; v < numVertice ; ++v)
            {
                glVertex3fv( vertices[ face[v] ] );
            }
        }
    }

    glEnd();
}
