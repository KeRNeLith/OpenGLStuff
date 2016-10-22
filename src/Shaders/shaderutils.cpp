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

void ShaderUtils::sendTransformMatrix(const glm::mat4& projection, const glm::mat4& visualisation, const glm::mat4& modelisation)
{
    if (!m_shader)
        return;

    // Calcul de la matrice de Modélisation, Visualisation, Projection
    glm::mat4 matrixMVP = projection * visualisation * modelisation;

    // Envoi la matrice de Modélisation, Visualisation, Projection aux shaders
    glUniformMatrix4fv(	glGetUniformLocation(m_shader->getProgramId(), "matrixMVP"), 1, GL_FALSE, glm::value_ptr(matrixMVP) );
}
