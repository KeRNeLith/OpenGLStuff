#include "transformnode.h"

#include "Transforms/transform.h"

TransformNode::TransformNode(const glm::mat4& transform)
    : m_transform(transform)
{

}

void TransformNode::apply() const
{
    GeometricTransform::pushMatrix();
    GeometricTransform::applyTransform(m_transform);

    Node::apply();

    GeometricTransform::popMatrix();
}
