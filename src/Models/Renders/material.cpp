/******************************************************************************\
*     Copyright (C) 2016 by Alexandre Rabérin                                  *
*                                                                              *
* The program is distributed under the terms of the GNU General Public License *
*                                                                              *
\******************************************************************************/

#include "material.h"

Material::Material(GLfloat ambientR, GLfloat ambientG, GLfloat ambientB,
                   GLfloat diffuseR, GLfloat diffuseG, GLfloat diffuseB,
                   GLfloat specularR, GLfloat specularG, GLfloat specularB,
                   GLfloat shininess)
    : m_ambient({{ ambientR, ambientG, ambientB }})
    , m_diffuse({{ diffuseR, diffuseG, diffuseB }})
    , m_specular({{ specularR, specularG, specularB }})
    , m_shininess(shininess)
{

}
