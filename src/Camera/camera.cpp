/******************************************************************************\
*     Copyright (C) 2016 by Alexandre Rabérin                                  * 
*                                                                              * 
* The program is distributed under the terms of the GNU General Public License * 
*                                                                              * 
\******************************************************************************/ 

#include "camera.h"

#include "../Transforms/transform.h"

Camera::Camera(GLdouble openAngleY, GLdouble aspect,
			   GLdouble zNear, GLdouble zFar,
			   GLdouble posX, GLdouble posY, GLdouble posZ,
			   GLdouble targetPointX, GLdouble targetPointY, GLdouble targetPointZ,
			   GLdouble verticalVectorX, GLdouble verticalVectorY, GLdouble verticalVectorZ)
    : m_openAngleY(openAngleY)
    , m_apsect(aspect)
    , m_zNear(zNear)
    , m_zFar(zFar)
    , m_distance(posZ)
    , m_azimuth(0)
    , m_elevation(0)
{
    m_position[0] = posX;
    m_position[1] = posY;
    m_position[2] = posZ;

    m_targetPoint[0] = targetPointX;
    m_targetPoint[1] = targetPointY;
    m_targetPoint[2] = targetPointZ;

    m_verticalVector[0] = verticalVectorX;
    m_verticalVector[1] = verticalVectorY;
    m_verticalVector[2] = verticalVectorZ;
}

void Camera::lookAt(GLdouble position[3], GLdouble targetPoint[3], GLdouble verticalVector[3])
{
    setPosition(position);
    setTargetPosition(targetPoint);
    setVerticalVector(verticalVector);
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

void Camera::applyCameraCoordinates()
{
    // Positionnement de la caméra
    GeometricTransform::lookAt(m_position, m_targetPoint, m_verticalVector);
}

