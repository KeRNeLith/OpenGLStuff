/******************************************************************************\
*     Copyright (C) 2016 by Alexandre Rabérin                                  * 
*     Based on Copyright (C) 2016 by Rémy Malgouyres                           * 
*     http://malgouyres.org                                                    * 
*                                                                              * 
* The program is distributed under the terms of the GNU General Public License * 
*                                                                              * 
\******************************************************************************/ 

#ifndef VIEW_H
#define VIEW_H

#include <memory>

#include <GL/glut.h>

#include "Camera/camera.h"

#include "Models/model.h"
#include "Models/Renders/renderscene.h"

/**
 * @brief The DisplayManager class Gère les paramètres d'affichage de la vue.
 */
class DisplayManager
{
private:
    GLint m_windowWidth; 	///< Largeur de la vue.
    GLint m_windowHeight; 	///< Hauteur de la vue.

    Model m_model;          ///< Modèle de données à afficher.

    std::unique_ptr<Camera> m_camera;   ///< Caméra visionnant la scène.

    RenderScene m_scene;    ///< Scène OpenGL à dessiner.

public:
    /**
     * @brief Constructeur des paramètres d'affichage.
     * Initialise les données nécessaires à l'affichage.
     * @param windowWidth Largeur de la fenêtre d'affichage.
     * @param windowHeigth Hauteur de la fenêtre d'affichage.
     */
    DisplayManager(GLint windowWidth, GLint windowHeigth);

    /**
     * @brief Réalise l'affichage de la scène 3D.
     */
	void display();

	/** 
     * Réglage du cadrage pour la vue.
     * Doit être rappelée si la taille de la vue change (SDL_WINDOWEVENT).
     * @param l Largeur de la (nouvelle) vue.
     * @param h Hauteur de la (nouvelle) vue.
	 */
	void resize(GLint l, GLint h);
	
	// Accesseurs / Setters
    /**
     * @brief Permet l'accès au modèle de données en lecture/écriture.
     * @return Modèle de données.
     */
	Model& model()
	{
		return m_model;
    }

    /**
     * @brief Permet l'accès au modèle de la caméra en lecture/écriture.
     * @return Modèle de la caméra.
     */
    std::unique_ptr<Camera>& camera()
    {
        return m_camera;
    }
};

#endif	// VIEW_H

