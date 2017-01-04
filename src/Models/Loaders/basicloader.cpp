#include "basicloader.h"

#include "Graph/drawablenode.h"
#include "Models/Renders/rendermodel.h"
#include "Shaders/shadercollection.h"

BasicLoader::BasicLoader()
    : Loader()
    , m_vertices()
    , m_normals()
    , m_faces()
    , m_material()
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

const std::vector< GLfloat >& BasicLoader::normals(int /*meshIndex*/) const
{
    return m_normals;
}

const std::vector< unsigned int >& BasicLoader::faces(int /*meshIndex*/) const
{
    return m_faces;
}

const Material& BasicLoader::materials(int /*meshIndex*/) const
{
    return m_material;
}

const std::vector< GLfloat >& BasicLoader::texCoords(int /*meshIndex*/) const
{
    return m_texCoords;
}

std::shared_ptr<Node> BasicLoader::getGraph() const
{
    std::shared_ptr<RenderModel> model(new RenderModel(ShaderCollection::getShader("default"), *this));

    return std::shared_ptr<Node>(new DrawableNode(model));
}
