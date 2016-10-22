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

#include "Shaders/shaderprogram.h"

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

    myApp.doEventsLoop();

	return EXIT_SUCCESS;
}

