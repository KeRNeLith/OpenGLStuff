/******************************************************************************\
*     Copyright (C) 2016 by Alexandre Rabérin                                  * 
*                                                                              * 
* The program is distributed under the terms of the GNU General Public License * 
*                                                                              * 
\******************************************************************************/

#include "rendermodel.h"

#include "Models/Loaders/loader.h"
#include "Models/Loaders/assimploader.h"

RenderModel::RenderModel(const std::string& filename)
    : m_object(new AssimpLoader(filename))
{
}

RenderModel::~RenderModel()
{
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

void RenderModel::applyMaterial(const Material& material)
{
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material.getAmbient().data());
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material.getDiffuse().data());
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material.getSpecular().data());
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, material.getShininess());
}

void RenderModel::drawObject()
{
    const auto numMesh = m_object->meshCount();
    // Pour chaque objets de la scène
    for (unsigned int m = 0 ; m < numMesh ; ++m)
    {
        glBegin(m_object->mode(m));

        // Tableaux des vertices et des faces du mesh traité
        const auto& vertices = m_object->vertices(m);
        const auto& normals = m_object->normals(m);
        const auto& faces = m_object->faces(m);

        // Applique le matériau de l'objet
        RenderModel::applyMaterial(m_object->material(m));

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
                glNormal3fv( normals[ face[v] ] );
                glVertex3fv( vertices[ face[v] ] );
            }
        }

        glEnd();
    }
}
