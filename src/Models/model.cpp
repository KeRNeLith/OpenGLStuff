/******************************************************************************\
*     Copyright (C) 2016 by Alexandre Rabérin                                  * 
*     Based on Copyright (C) 2016 by Rémy Malgouyres                           * 
*     http://malgouyres.org                                                    * 
*                                                                              * 
* The program is distributed under the terms of the GNU General Public License * 
*                                                                              * 
\******************************************************************************/

#include "model.h"

#include "Shaders/shaderutils.h"

Model::Model()
    // Charge les shaders via un programme OpenGL
    : m_program(new ShaderProgram(  "src/Shaders/src/vertexShader.vert",
                                    "src/Shaders/src/fragmentShader.frag"))
{
    ShaderUtils::instance().setActiveShaderProgram(m_program);
}

void Model::update()
{
}

