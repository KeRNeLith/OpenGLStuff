/******************************************************************************\
*     Copyright (C) 2016 by Alexandre Rabérin                                  *
*                                                                              *
* The program is distributed under the terms of the GNU General Public License *
*                                                                              *
\******************************************************************************/

#include "sphericalcamera.h"

#include "../Transforms/transform.h"

SphericalCamera::SphericalCamera(   double openAngleY, double aspect,
                                    double zNear, double zFar,
                                    double dist, double azimuth, double elevation)
    : Camera(openAngleY, aspect, zNear, zFar)
    , m_distance(dist)
    , m_azimuth(azimuth)
    , m_elevation(elevation)
{
}

void SphericalCamera::applyCameraTransformation()
{
    glm::mat4 visu(1.0);
    visu = glm::translate(visu, glm::vec3(0.0, 0.0, -m_distance));
    visu = glm::rotate(visu, float(m_azimuth), glm::vec3(0.0, 1.0, 0.0));
    m_visualisationMatrix = glm::rotate(visu, float(m_elevation), glm::vec3(1.0, 0.0, 0.0));
}
