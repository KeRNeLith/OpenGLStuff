/******************************************************************************\
*     Copyright (C) 2016 by Alexandre Rabérin                                  * 
*     Based on Copyright (C) 2016 by Rémy Malgouyres                           * 
*     http://malgouyres.org                                                    * 
*                                                                              * 
* The program is distributed under the terms of the GNU General Public License * 
*                                                                              * 
\******************************************************************************/

#include "model.h"

Model::Model()
    // Charge les shaders via un programme OpenGL
    : m_program("src/Shaders/src/vertexShader.vert",
                "src/Shaders/src/fragmentShader.frag")
{
    // Utilise le programme créé
    m_program.useProgram();
}

void Model::update()
{
}

