/******************************************************************************\
*     Copyright (C) 2016 by Alexandre Rabérin                                  * 
*                                                                              * 
* The program is distributed under the terms of the GNU General Public License * 
*                                                                              * 
\******************************************************************************/ 

#include "cartesiancamera.h"

#include "Tools/convert.h"

#include "../Transforms/transform.h"

CartesianCamera::CartesianCamera(   double openAngleY, double aspect,
                                    double zNear, double zFar,
                                    double posX, double posY, double posZ,
                                    double targetPointX, double targetPointY, double targetPointZ,
                                    double verticalVectorX, double verticalVectorY, double verticalVectorZ)
    : Camera(openAngleY, aspect, zNear, zFar)
    , m_position({{ posX, posY, posZ }})
    , m_targetPoint({{ targetPointX, targetPointY, targetPointZ }})
    , m_verticalVector({{ verticalVectorX, verticalVectorY, verticalVectorZ }})
{
}

void CartesianCamera::lookAt(const std::array<double, 3>& position, const std::array<double, 3>& targetPoint, const std::array<double, 3>& verticalVector)
{
    setPosition(position);
    setTargetPosition(targetPoint);
    setVerticalVector(verticalVector);
}

void CartesianCamera::applyCameraTransformation()
{
    m_visualisationMatrix = glm::lookAt(toGLMVec3(m_position), toGLMVec3(m_targetPoint), toGLMVec3(m_verticalVector));
}
