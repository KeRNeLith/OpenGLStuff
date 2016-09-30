/******************************************************************************\
*     Copyright (C) 2016 by Alexandre Rabérin                                  * 
*     Based on Copyright (C) 2016 by Rémy Malgouyres                           * 
*     http://malgouyres.org                                                    * 
*                                                                              * 
* The program is distributed under the terms of the GNU General Public License * 
*                                                                              * 
\******************************************************************************/

#include <cstdlib>

//#include <SDL2/SDL.h>
//#include <SDL2/SDL_opengl.h>
// Entraine des conflits de nommage si décommenté
//#include <GLES3/gl3.h>
#include <GL/glut.h>

#include "MainApp/mainapplication.h"

/////////////////////////////////////////////////////////////////
/// PROGRAMME PRINCIPAL                                       ///
/////////////////////////////////////////////////////////////////

int main(int argc, char** argv)
{  
	MainApplication myApp(700, 700, "Mon Application SDL/OpenGL");
	glutInit(&argc, argv);
	myApp.doEventsLoop();

	return EXIT_SUCCESS;
}

