/******************************************************************************\
*     Copyright (C) 2016 by Alexandre Rabérin                                  * 
*                                                                              * 
* The program is distributed under the terms of the GNU General Public License * 
*                                                                              * 
\******************************************************************************/ 

#include "cartesiancamera.h"

#include "../Transforms/transform.h"

CartesianCamera::CartesianCamera(   GLdouble openAngleY, GLdouble aspect,
                                    GLdouble zNear, GLdouble zFar,
                                    GLdouble posX, GLdouble posY, GLdouble posZ,
                                    GLdouble targetPointX, GLdouble targetPointY, GLdouble targetPointZ,
                                    GLdouble verticalVectorX, GLdouble verticalVectorY, GLdouble verticalVectorZ)
    : Camera(openAngleY, aspect, zNear, zFar)
    , m_position({{ posX, posY, posZ }})
    , m_targetPoint({{ targetPointX, targetPointY, targetPointZ }})
    , m_verticalVector({{ verticalVectorX, verticalVectorY, verticalVectorZ }})
{
}

void CartesianCamera::lookAt(const std::array<GLdouble, 3>& position, const std::array<GLdouble, 3>& targetPoint, const std::array<GLdouble, 3>& verticalVector)
{
    setPosition(position);
    setTargetPosition(targetPoint);
    setVerticalVector(verticalVector);
}

void CartesianCamera::applyCameraCoordinates()
{
    // Positionnement de la caméra
    GeometricTransform::lookAt(m_position.data(), m_targetPoint.data(), m_verticalVector.data());
}
