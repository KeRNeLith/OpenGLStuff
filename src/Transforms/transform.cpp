/******************************************************************************\
*     Copyright (C) 2016 by Alexandre Rabérin                                  * 
*     Based on Copyright (C) 2016 by Rémy Malgouyres                           * 
*     http://malgouyres.org                                                    * 
*                                                                              * 
* The program is distributed under the terms of the GNU General Public License * 
*                                                                              * 
\******************************************************************************/

#include "transform.h"

#include <GL/glut.h>


void GeometricTransform::viewport(int32_t viewCenterX,  int32_t viewCenterY, uint32_t viewWidth, uint32_t viewHeight)
{
    glViewport(viewCenterX, viewCenterY, viewWidth, viewHeight);
}

void GeometricTransform::applyPerspectiveProjection(double openAngleY, double aspect, double zNear, double zFar)
{
    // Réinitialisation des paramètres intrinsèques de la caméra
    clearProjection();
    gluPerspective(openAngleY, aspect, zNear, zFar);
}

void GeometricTransform::clearModelView()
{
    // Réinitialisation des paramètres de la caméra
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void GeometricTransform::clearProjection()
{
    // Réinitialisation des paramètres de projection de la caméra
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
}

void GeometricTransform::lookAt(double position[3], double targetPoint[3], double verticalVector[3])
{
    gluLookAt(  position[0], position[1], position[2],
                targetPoint[0], targetPoint[1], targetPoint[2],
                verticalVector[0], verticalVector[1], verticalVector[2]);
}

void GeometricTransform::translate(double vecX, double vecY, double vecZ)
{
    glTranslated(vecX, vecY, vecZ);
}

void GeometricTransform::rotate(double vecX, double vecY, double vecZ, double angle)
{
    glRotated(vecX, vecY, vecZ, angle);
}

void GeometricTransform::scale(double factorX, double factorY, double factorZ)
{
    glScaled(factorX, factorY, factorZ);
}

void GeometricTransform::pushMatrix()
{
    glPushMatrix();
}

void GeometricTransform::popMatrix()
{
    glPopMatrix();
}
