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

#include "Tools/frames.h"

#include "Transforms/transform.h"

DisplayManager::DisplayManager(GLint windowWidth, GLint windowHeigth)
    : m_windowWidth(windowWidth)
    , m_windowHeight(windowHeigth)
    , m_model()// Construction du modèle
    , m_camera(// Perspective
               50.0, m_windowWidth / GLdouble(m_windowHeight),
               // Plans clipping
               0.0, 100.0,
               // Position
               0.0, 0.0, -50.0,
               // Focus
               0.0, 0.0,  0.0,
               // Verticale
               0.0, 1.0, 0.0)
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
    m_camera.applyCameraCoordinates();

    // Dessin
    GeometricTransform::pushMatrix();
    // Sun
    std::array<double, 3> posSun = m_model.getSunCoords();
    GeometricTransform::translate(posSun[0], posSun[1], posSun[2]);
    glutWireSphere(m_model.getSunSize(), 24, 24);

    GeometricTransform::popMatrix();

    // Earth
    std::array<double, 3> posEarth = m_model.getEarthCoords();
    GeometricTransform::translate(posEarth[0], posEarth[1], posEarth[2]);
    glutWireSphere(m_model.getEarthSize(), 24, 24);
}

void DisplayManager::resize(GLint l, GLint h)
{
	m_windowWidth = l;
    m_windowHeight = h;

    // On modifie l'aspect de la caméra au cas ou le rapport l/h aurait changé
    m_camera.setAspect(m_windowWidth / GLdouble(m_windowHeight));

    // Surface de rendu : on recadre la fenêtre centrée en (0, 0) aux bonnes dimensions
    GeometricTransform::viewport(0, 0, GLsizei(m_windowWidth), GLsizei(m_windowHeight));

    // Redéfinit la projection en perspective
    m_camera.applyPerspectiveProjection();
}

