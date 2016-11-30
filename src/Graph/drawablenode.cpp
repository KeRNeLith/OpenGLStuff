#include "drawablenode.h"

#include "Shaders/shaderutils.h"
#include "Transforms/transform.h"

DrawableNode::DrawableNode(const std::shared_ptr<RenderModel>& model)
    : m_object(model)
{
}

DrawableNode::~DrawableNode()
{
}

void DrawableNode::apply() const
{
    // Dessin du modele 3D
    m_object->getShader()->useProgram();
    // Applique la tranformation de modélisation
    ShaderUtils::sendModelisationMatrix(*m_object->getShader(), GeometricTransform::getTransform());

    // Dessin du maillage
    m_object->drawObject();

    Node::apply();
}
