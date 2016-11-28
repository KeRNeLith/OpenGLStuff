#include "drawablenode.h"

#include "Shaders/shaderutils.h"
#include "Transforms/transform.h"

DrawableNode::DrawableNode(const std::shared_ptr<ShaderProgram>& shader)
    : m_shader(shader)
{

}

void DrawableNode::apply()
{
    // Dessin du modele 3D
    m_shader->useProgram();
    // Applique la tranformation de modélisation
    ShaderUtils::sendModelisationMatrix(*m_shader, GeometricTransform::getTransform());

    // Dessin du maillage
    // TODO

    Node::apply();
}
