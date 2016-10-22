/******************************************************************************\
*     Copyright (C) 2016 by Alexandre Rabérin                                  *
*                                                                              *
* The program is distributed under the terms of the GNU General Public License *
*                                                                              *
\******************************************************************************/

#include "camera.h"

#include "../Transforms/transform.h"

Camera::Camera(double openAngleY, double aspect,
               double zNear, double zFar)
    : m_openAngleY(openAngleY)
    , m_apsect(aspect)
    , m_zNear(zNear)
    , m_zFar(zFar)
    , m_projectionMatrix(1.0)
    , m_visualisationMatrix(1.0)
{
}

void Camera::applyPerspectiveProjection()
{
    m_projectionMatrix = glm::perspective(m_openAngleY, m_apsect, m_zNear, m_zFar);
}

void Camera::clearView()
{
    m_visualisationMatrix = glm::mat4(1.0);
}

void Camera::clearProjection()
{
    m_projectionMatrix = glm::mat4(1.0);
}
