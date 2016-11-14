#include "drawablenode.h"

DrawableNode::DrawableNode(const std::shared_ptr<ShaderProgram>& shader)
    : m_shader(shader)
{

}

void DrawableNode::apply()
{
    // Dessin du modele 3D
    if (m_shader)
    {
        m_shader->useProgram();
    }

    // TODO

    Node::apply();
}
