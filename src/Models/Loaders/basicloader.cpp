#include "basicloader.h"

BasicLoader::BasicLoader()
    : Loader()
    , m_vertices()
    , m_faces()
{

}

BasicLoader::~BasicLoader()
{
    for (auto it = m_vertices.begin() ; it != m_vertices.end() ; ++it)
    {
        delete[] (*it);
    }
}

const std::vector< GLfloat* >& BasicLoader::vertices(int /*meshIndex*/) const
{
    return m_vertices;
}

const std::vector< std::vector<unsigned int> >& BasicLoader::faces(int /*meshIndex*/) const
{
    return m_faces;
}
