/******************************************************************************\
*     Copyright (C) 2016 by Alexandre Rabérin                                  *
*                                                                              *
* The program is distributed under the terms of the GNU General Public License *
*                                                                              *
\******************************************************************************/

#include "camera.h"

#include "../Transforms/transform.h"

Camera::Camera(GLdouble openAngleY, GLdouble aspect,
               GLdouble zNear, GLdouble zFar)
    : m_openAngleY(openAngleY)
    , m_apsect(aspect)
    , m_zNear(zNear)
    , m_zFar(zFar)
{
}

void Camera::applyPerspectiveProjection()
{
    GeometricTransform::applyPerspectiveProjection(m_openAngleY, m_apsect, m_zNear, m_zFar);
}

void Camera::clearModelView()
{
    GeometricTransform::clearModelView();
}

void Camera::clearProjection()
{
    GeometricTransform::clearProjection();
}
