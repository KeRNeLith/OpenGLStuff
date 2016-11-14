#ifndef TRANSFORMNODE_H
#define TRANSFORMNODE_H

#include <glm/glm.hpp>  // Librairie Maths pour les matrices

#include "node.h"

class TransformNode
        : public Node
{
protected:
    glm::mat4 m_transform;

public:
    TransformNode();
    
    void apply() override;
};

#endif // TRANSFORMNODE_H
