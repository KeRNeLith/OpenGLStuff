/******************************************************************************\
*     Copyright (C) 2016 by Alexandre Rabérin                                  * 
*     Based on Copyright (C) 2016 by Rémy Malgouyres                           * 
*     http://malgouyres.org                                                    * 
*                                                                              * 
* The program is distributed under the terms of the GNU General Public License * 
*                                                                              * 
\******************************************************************************/ 

#include "view.h"

#include <iostream>

#include "Camera/cartesiancamera.h"

#include "Tools/frames.h"

#include "Transforms/transform.h"

DisplayManager::DisplayManager(GLint windowWidth, GLint windowHeigth)
    : m_windowWidth(windowWidth)
    , m_windowHeight(windowHeigth)
    , m_model()// Construction du modèle
    , m_camera(new CartesianCamera(// Perspective
                                   50.0, m_windowWidth / GLdouble(m_windowHeight),
                                   // Plans clipping
                                   0.0, 100.0,
                                   // Position
                                   0.0, 0.0, 50.0,
                                   // Focus
                                   0.0, 0.0, 0.0,
                                   // Verticale
                                   0.0, 1.0, 0.0))
{
	FramesData::init();
}

void DisplayManager::display()
{
	// Affichage des Frames par seconde (FPS)
	if (FramesData::update())
	{
		std::cout << FramesData::getFPSDescriptor() << std::endl;
	}

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // On se place dans le repère monde
    Camera::clearModelView();
    // Applique le changement de repère de la caméra dans le ModelView
    m_camera->applyCameraCoordinates();

    // Dessin
    //////////////
    /// TEST CODE
    //////////////
    //GLint nvertices = 3;
    unsigned int nfaces = 1;

    GLfloat vertices[][3] = {
        { -0.5, 1.0, 0.0 },
        { 1.0, -0.5, 0.0 },
        { -1.0, -1.0, 0.0 }
    };

    GLfloat colors[][3] = {
        { 1.0, 0.0, 0.0 },
        { 0.0, 1.0, 0.0 },
        { 0.0, 0.0, 1.0 }
    };

    GLuint faces[][3] = {
        { 0, 1, 2 }
    };

    glBegin(GL_TRIANGLES);
        for (unsigned int i = 0 ; i < nfaces ; ++i)
        {
            for (unsigned int j = 0 ; j < 3 ; ++j)
            {
                glColor3fv(colors[faces[i][j]]);
                glVertex3fv(vertices[faces[i][j]]);
            }
        }
    glEnd();
    //////////////////
    /// END TEST CODE
    //////////////////
}

void DisplayManager::resize(GLint l, GLint h)
{
	m_windowWidth = l;
    m_windowHeight = h;

    // On modifie l'aspect de la caméra au cas ou le rapport l/h aurait changé
    m_camera->setAspect(m_windowWidth / GLdouble(m_windowHeight));

    // Surface de rendu : on recadre la fenêtre centrée en (0, 0) aux bonnes dimensions
    GeometricTransform::viewport(0, 0, GLsizei(m_windowWidth), GLsizei(m_windowHeight));

    // Redéfinit la projection en perspective
    m_camera->applyPerspectiveProjection();
}

