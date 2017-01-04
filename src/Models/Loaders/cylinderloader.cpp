/******************************************************************************\
*     Copyright (C) 2016 by Alexandre Rabérin                                  *
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
    for(unsigned int i = 0 ; i < m_nbMeridians; ++i)
    {
        x = GLfloat(std::cos(step * i) * radius);
        z = GLfloat(std::sin(step * i) * radius);

        /// Création des vertices
        // Vertex 1
        m_vertices.push_back(x);
        m_vertices.push_back(GLfloat(m_height/double(2)));
        m_vertices.push_back(z);

        // Vertex 2
        m_vertices.push_back(x);
        m_vertices.push_back(-GLfloat(m_height/double(2)));
        m_vertices.push_back(z);

        /// Création des normales
        // TODO normales

        /// Création des faces
        // Face 1
        m_faces.push_back(2*i);
        m_faces.push_back(((i+1) == m_nbMeridians ? 0 : 2 * i + 2));
        m_faces.push_back(2*i+1);

        // Face 2
        m_faces.push_back(2*i+1);
        m_faces.push_back(((i+1) == m_nbMeridians ? 0 : 2 * i + 2));
        m_faces.push_back(((i+1) == m_nbMeridians ? 0 : 2 * i +3));

        /// Création des coordonnées de texture
        // Coordonnée texture vertex 1
        m_texCoords.push_back(GLfloat(i / double(m_nbMeridians)));
        m_texCoords.push_back(0.0);

        // Coordonnée texture vertex 2
        m_texCoords.push_back(GLfloat(i / double(m_nbMeridians)));
        m_texCoords.push_back(1.0);
    }
}

unsigned int CylinderLoader::meshCount() const
{
    return 1;
}

GLenum CylinderLoader::mode(int /*meshIndex*/) const
{
    return GL_TRIANGLES;
}
