#ifndef NODE_H
#define NODE_H

#include <memory>
#include <vector>

class Node
{
public:
    using NodeList = std::vector< std::shared_ptr<Node> >;

protected:
    NodeList m_children;

public:
    Node();
    virtual ~Node();

    virtual void apply();

    void addChild(const std::shared_ptr<Node>& node);
};

#endif // NODE_H
