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

#include "Models/Renders/car.h"

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
               0.0, 0.0, 10.0,
               // Focus
               0.0, 0.0,  0.0,
               // Verticale
               0.0, 1.0, 0.0)
    , m_render(new Car(m_model))
{
    FramesData::init();
    RenderModel::init(); // Paramètres de rendu
}

void DisplayManager::display()
{
    // Affichage des Frames par seconde (FPS)
    if (FramesData::update())
    {
        std::cout << FramesData::getFPSDescriptor() << std::endl;
    }

    // Efface les buffers de profondeur et couleurs
    RenderModel::initView();

    // On se place dans le repère monde
    Camera::clearModelView();
    // Applique le changement de repère de la caméra dans le ModelView
    //m_camera.applyCameraCoordinates();
    m_camera.applyCameraPosition();

    // Dessin fil de fer
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    // Dessin
    m_render->drawScene();
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

