/******************************************************************************\
*     Copyright (C) 2016 by Alexandre Rabérin                                  * 
*                                                                              * 
* The program is distributed under the terms of the GNU General Public License * 
*                                                                              * 
\******************************************************************************/

#include "rendermodel.h"

#include "Models/Loaders/cylinderloader.h"

RenderModel::RenderModel(RenderModel::ModelType type)
    // Read the given file with some example postprocessing
    : m_object(loadObject(type))
{
}

RenderModel::~RenderModel()
{
}

Loader* RenderModel::loadObject(RenderModel::ModelType type)
{
    switch (type)
    {
    case RenderModel::CYLINDER:
        return new CylinderLoader();
    default:
        return new CylinderLoader();
    }
}

void RenderModel::init()
{
    // Réglage de la couleur de fond
    glClearColor(0.0, 0.0, 0.0, 1.0);
}

void RenderModel::initView()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void RenderModel::drawObject() const
{
    const auto numMesh = m_object->meshCount();
    // Pour chaque objets de la scène
    for (unsigned int m = 0 ; m < numMesh ; ++m)
    {
        glBegin(m_object->mode(m));

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

        glEnd();
    }
}
