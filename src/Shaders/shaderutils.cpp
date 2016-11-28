#include "shaderutils.h"

#include <glm/gtc/type_ptr.hpp> // Accès bas niveau au données

void ShaderUtils::sendProjectionMatrix(const ShaderProgram& program, const glm::mat4& projection)
{
    // Envoi la matrice de Projection au shader
    glUniformMatrix4fv(	glGetUniformLocation(program.getProgramId(), "matrixP"), 1, GL_FALSE, glm::value_ptr(projection) );
}

void ShaderUtils::sendVisualisationMatrix(const ShaderProgram& program, const glm::mat4& visualisation)
{
    // Envoi la matrice de Visualisation au shader
    glUniformMatrix4fv(	glGetUniformLocation(program.getProgramId(), "matrixV"), 1, GL_FALSE, glm::value_ptr(visualisation) );
}

void ShaderUtils::sendModelisationMatrix(const ShaderProgram& program, const glm::mat4& modelisation)
{
    // Envoi la matrice de Modélisation au shader
    glUniformMatrix4fv(	glGetUniformLocation(program.getProgramId(), "matrixM"), 1, GL_FALSE, glm::value_ptr(modelisation) );
}
