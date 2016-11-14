#ifndef DRAWABLENODE_H
#define DRAWABLENODE_H

#include <memory>

#include "node.h"

#include "Shaders/shaderprogram.h"

class DrawableNode
        : public Node
{
protected:
    std::shared_ptr<ShaderProgram> m_shader;

public:
    DrawableNode();

    void apply() override;
};

#endif // DRAWABLENODE_H
