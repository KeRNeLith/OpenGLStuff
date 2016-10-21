/******************************************************************************\
*     Copyright (C) 2016 by Alexandre Rabérin                                  * 
*     Based on Copyright (C) 2016 by Rémy Malgouyres                           * 
*     http://malgouyres.org                                                    * 
*                                                                              * 
* The program is distributed under the terms of the GNU General Public License * 
*                                                                              * 
\******************************************************************************/

#include <cstdlib>

#include <iostream>

#include <GL/glut.h>

#include "MainApp/mainapplication.h"

#include "Shaders/shaderutils.h"

/////////////////////////////////////////////////////////////////
/// PROGRAMME PRINCIPAL                                       ///
/////////////////////////////////////////////////////////////////

int main(int argc, char** argv)
{  
	MainApplication myApp(700, 700, "Mon Application SDL/OpenGL");
	glutInit(&argc, argv);

    // Affichage des versions d'OpenGL et GLSL disponible
    std::cout << "Version OpenGL : " << glGetString(GL_VERSION) << std::endl;
    std::cout << "Version GLSL : " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;

    // Charge les shaders via un programme OpenGL
    GLuint progID, vertexID, fragID;
    ShaderUtils::createShadersProgram(progID, vertexID, fragID,
                                      "src/Shaders/src/vertexShader.vert",
                                      "src/Shaders/src/fragmentShader.frag");

    // Utilise le programme créé
    ShaderUtils::useShaderProgram(progID);

    myApp.doEventsLoop();

    // Supprime le programme OpenGL
    ShaderUtils::removeShaderProgram(progID);

	return EXIT_SUCCESS;
}

