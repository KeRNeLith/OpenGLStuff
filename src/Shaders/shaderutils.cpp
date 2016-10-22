#include "shaderutils.h"

ShaderUtils::ShaderUtils()
    : m_shader(nullptr)
{

}

ShaderUtils::~ShaderUtils()
{

}

void ShaderUtils::setActiveShaderProgram(const std::shared_ptr<ShaderProgram>& shaderProg)
{
    m_shader = shaderProg;
    m_shader->useProgram();
}
