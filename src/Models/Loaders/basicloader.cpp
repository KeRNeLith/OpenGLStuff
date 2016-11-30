#include "basicloader.h"

#include "Graph/drawablenode.h"
#include "Models/Renders/rendermodel.h"
#include "Shaders/shadercollection.h"

BasicLoader::BasicLoader()
    : Loader()
    , m_vertices()
    , m_faces()
    , m_texCoords()
{

}

BasicLoader::~BasicLoader()
{
}

const std::vector< GLfloat >& BasicLoader::vertices(int /*meshIndex*/) const
{
    return m_vertices;
}

const std::vector< unsigned int >& BasicLoader::faces(int /*meshIndex*/) const
{
    return m_faces;
}

const std::vector< GLfloat >& BasicLoader::texCoords(int /*meshIndex*/) const
{
    return m_texCoords;
}
