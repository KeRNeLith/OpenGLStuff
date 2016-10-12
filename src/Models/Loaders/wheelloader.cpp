#include "wheelloader.h"

#include "Tools/convert.h"

WheelLoader::WheelLoader(double width, double radius, unsigned int nbQuads)
    : Loader()
    , m_width(width)
    , m_radius(radius)
    , m_nbQuads(nbQuads)
    , m_vertices()
    , m_faces()
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

WheelLoader::~WheelLoader()
{
    for (auto it = m_vertices.begin() ; it != m_vertices.end() ; ++it)
    {
        delete[] (*it);
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

const std::vector< GLfloat* >& WheelLoader::vertices(int /*meshIndex*/) const
{
    return m_vertices;
}

const std::vector< std::vector<unsigned int> >& WheelLoader::faces(int /*meshIndex*/) const
{
    return m_faces;
}
