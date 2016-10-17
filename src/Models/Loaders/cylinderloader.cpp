/******************************************************************************\
*     Copyright (C) 2016 by Adrien Pierreval                                   *
*                                                                              *
* The program is distributed under the terms of the GNU General Public License *
*                                                                              *
\******************************************************************************/

#include "cylinderloader.h"

#include "Tools/convert.h"

CylinderLoader::CylinderLoader(double height, double radius, unsigned int nbMeridians) 
    : BasicLoader()
    , m_height(height)
    , m_radius(radius)
    , m_nbMeridians(nbMeridians)
{
    // Création des sommets
    const double step = toRad(360 / double(m_nbMeridians));

    GLfloat x = 0;
    GLfloat z = 0;
    for(unsigned int i = 0 ; i < m_nbMeridians ; ++i)
    {
        x = GLfloat(std::cos(step * i) * radius);
        z = - GLfloat(std::sin(step * i) * radius);

        GLfloat* vertex1 = new GLfloat[3] { x, 0.0, z };
        GLfloat* vertex2 = new GLfloat[3] { x, GLfloat(m_height), z };

        m_vertices.push_back(vertex1);
        m_vertices.push_back(vertex2);

        // Création de face
        std::vector< unsigned int > face(4);
        face[0] = 2 * i;
        face[1] = 2 * i + 1;
        face[2] = (i+1) == m_nbMeridians ? 1 : 2 * i + 3;
        face[3] = (i+1) == m_nbMeridians ? 0 : 2 * i + 2;

        m_faces.push_back(face);
    }
}

unsigned int CylinderLoader::meshCount() const
{
    return 1;
}

GLenum CylinderLoader::modes(int /*meshIndex*/) const
{
    return GL_QUADS;
}