#include "node.h"

Node::Node()
    : m_children()
{

}

Node::~Node()
{

}

void Node::apply() const
{
    for (const auto& child : m_children)
    {
        child->apply();
    }
}

void Node::addChild(const std::shared_ptr<Node>& node)
{
    m_children.push_back(node);
}
