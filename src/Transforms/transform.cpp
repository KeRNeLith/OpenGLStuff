/******************************************************************************\
*     Copyright (C) 2016 by Alexandre Rabérin                                  *
*     Based on Copyright (C) 2016 by Rémy Malgouyres                           *
*     http://malgouyres.org                                                    *
*                                                                              *
* The program is distributed under the terms of the GNU General Public License *
*                                                                              *
\******************************************************************************/

#include "transform.h"

#include <glm/gtc/matrix_transform.hpp> // Réglages perspectives, lookAt, etc.

// Static init
glm::mat4 GeometricTransform::m_currentMatrix = glm::mat4(1.0);
std::stack< glm::mat4 > GeometricTransform::m_transformsStack;

void GeometricTransform::clearModelMatrix()
{
    m_currentMatrix = glm::mat4(1.0);

    // "Clear" transform stack
    m_transformsStack = std::stack< glm::mat4 >();
}

void GeometricTransform::translate(double vecX, double vecY, double vecZ)
{
    m_currentMatrix = glm::translate(m_currentMatrix, glm::vec3(vecX, vecY, vecZ));
}

void GeometricTransform::rotate(double angle, double vecX, double vecY, double vecZ)
{
    m_currentMatrix = glm::rotate(m_currentMatrix, float(angle), glm::vec3(vecX, vecY, vecZ));
}

void GeometricTransform::scale(double factorX, double factorY, double factorZ)
{
    m_currentMatrix = glm::scale(m_currentMatrix, glm::vec3(factorX, factorY, factorZ));
}

void GeometricTransform::applyTransform(const glm::mat4& matrix)
{
    m_currentMatrix = m_currentMatrix * matrix;
}

void GeometricTransform::pushMatrix()
{
    m_transformsStack.push(m_currentMatrix);
}

void GeometricTransform::popMatrix()
{
    m_currentMatrix = m_transformsStack.top();
    m_transformsStack.pop();
}

const glm::mat4& GeometricTransform::getTransform()
{
    return m_currentMatrix;
}
