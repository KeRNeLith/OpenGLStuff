#include "node.h"

Node::Node()
    : m_children()
{

}

Node::~Node()
{

}

void Node::apply()
{
    for (const auto& child : m_children)
    {
        child->apply();
    }
}
