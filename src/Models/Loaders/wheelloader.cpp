/******************************************************************************\
*     Copyright (C) 2016 by Alexandre Rabérin                                  *
*                                                                              *
* The program is distributed under the terms of the GNU General Public License *
*                                                                              *
\******************************************************************************/

#include "wheelloader.h"

#include "Tools/convert.h"

WheelLoader::WheelLoader(double width, double radius, unsigned int nbQuads)
    : BasicLoader()
    , m_width(width)
    , m_radius(radius)
    , m_nbQuads(nbQuads)
{
    // Création des sommets
    const double step = toRad(360 / double(m_nbQuads));

    GLfloat y = 0;
    GLfloat z = 0;
    for(unsigned int i = 0 ; i < m_nbQuads ; ++i)
    {
        y = GLfloat(std::cos(step * i) * radius);
        z = GLfloat(std::sin(step * i) * radius);

        GLfloat* vertex1 = new GLfloat[3] { GLfloat(-m_width/double(2)), y, z };
        GLfloat* vertex2 = new GLfloat[3] { GLfloat(m_width/double(2)), y, z };

        m_vertices.push_back(vertex1);
        m_vertices.push_back(vertex2);

        // Création de face
        std::vector< unsigned int > face(4);
        face[0] = 2 * i;
        face[1] = 2 * i + 1;
        face[2] = (i+1) == m_nbQuads ? 1 : 2 * i + 3;
        face[3] = (i+1) == m_nbQuads ? 0 : 2 * i + 2;

        m_faces.push_back(face);
    }
}

unsigned int WheelLoader::meshCount() const
{
    return 1;
}

GLenum WheelLoader::modes(int /*meshIndex*/) const
{
    return GL_QUADS;
}