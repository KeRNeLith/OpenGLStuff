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

#include "Graph/drawablenode.h"
#include "Graph/transformnode.h"

#include "Models/Loaders/assimploader.h"
#include "Models/Loaders/cylinderloader.h"
#include "Models/Renders/rendermodel.h"

#include "Shaders/shadercollection.h"
#include "Shaders/shaderutils.h"

#include "Tools/frames.h"

#include "Transforms/transform.h"

DisplayManager::DisplayManager(GLint windowWidth, GLint windowHeigth)
    : m_windowWidth(windowWidth)
    , m_windowHeight(windowHeigth)
    , m_model()// Construction du modèle
    , m_camera(new CartesianCamera(// Perspective
                                   50.0, m_windowWidth / GLdouble(m_windowHeight),
                                   // Plans clipping
                                   1.0, 10000.0,
                                   // Position
                                   0.0, 0.0, 3000.0,
                                   // Focus
                                   0.0, 0.0, 0.0,
                                   // Verticale
                                   0.0, 1.0, 0.0))
    , m_root(new Node())
{
    FramesData::init();
    RenderModel::init();

    ShaderCollection::addOrUpdateShader("default",
                                        "src/Shaders/src/vertexShader.vert",
                                        "src/Shaders/src/fragmentShader.frag");

    ShaderProgram::setCamera(m_camera);

    // Ajoute une voiture au graph de scène
    std::shared_ptr<Loader> loader(new AssimpLoader("data/fichiers3DS/Audi_tt.3ds"));
    m_root->addChild(loader->getGraph());
}

void DisplayManager::display()
{
    // Affichage des Frames par seconde (FPS)
    if (FramesData::update())
    {
        std::cout << FramesData::getFPSDescriptor() << std::endl;
    }

    RenderModel::resetView();

    // Calcul la matrice de visualisation
    m_camera->applyCameraTransformation();

    // Dessin
    m_root->apply();
}

void DisplayManager::resize(GLint l, GLint h)
{
    m_windowWidth = l;
    m_windowHeight = h;

    // On modifie l'aspect de la caméra au cas ou le rapport l/h aurait changé
    m_camera->setAspect(m_windowWidth / GLdouble(m_windowHeight));

    // Re-Calcul la matrice de projection
    m_camera->applyPerspectiveProjection();
}

