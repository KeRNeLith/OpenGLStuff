/******************************************************************************\
*     Copyright (C) 2016 by Alexandre Rabérin                                  *
*                                                                              *
* The program is distributed under the terms of the GNU General Public License *
*                                                                              *
\******************************************************************************/

#include "sphericalcamera.h"

#include "../Transforms/transform.h"

SphericalCamera::SphericalCamera(   GLdouble openAngleY, GLdouble aspect,
                                    GLdouble zNear, GLdouble zFar,
                                    GLdouble dist, GLdouble azimuth, GLdouble elevation)
    : Camera(openAngleY, aspect, zNear, zFar)
    , m_distance(dist)
    , m_azimuth(azimuth)
    , m_elevation(elevation)
{
}

void SphericalCamera::applyCameraCoordinates()
{
    // Positionnement de la caméra
    GeometricTransform::translate(0.0, 0.0, -m_distance);
    GeometricTransform::rotate(m_azimuth, 0.0, 1.0, 0.0);
    GeometricTransform::rotate(m_elevation, 1.0, 0.0, 0.0);
}
