/******************************************************************************\
*     Copyright (C) 2016 by Alexandre Rabérin                                  * 
*     Based on Copyright (C) 2016 by Rémy Malgouyres                           * 
*     http://malgouyres.org                                                    * 
*                                                                              * 
* The program is distributed under the terms of the GNU General Public License * 
*                                                                              * 
\******************************************************************************/ 

#ifndef GUI_H
#define GUI_H

#include "SDL/windowmanager.h"

// Forward Declarations
class DisplayManager;

/**
 * @brief The WrapperSDL class Wrapper pour SDL et assurant les fonctionnalités de la GUI (interface).
 */
class WrapperSDL
{
private:
    WindowManager m_windowManager;  ///< Gestionnaire de la fenêtre graphique

public:
    /**
     * @brief Constructeur. Construit une fenêtre graphique aux dimensions spécifiées, ainsi qu'un contexte OpenGL.
     * @param initWindowWidth Largeur initiale de la fenêtre d'affichage.
     * @param initWindowHeight Hauteur initiale de la fenêtre d'affichage.
     * @param windowTitle Titre de la fenêtre graphique.
     */
    WrapperSDL(int initWindowWidth, int initWindowHeight, const char* windowTitle);

    /**
     * @brief Initialise les paramètres d'affichage contenant les données à implémenter (évènements, vue, modèle, ...).
     * @param displayParams Paramètres d'affichage.
     */
	void init(DisplayManager* displayParams);

    /**
     * @brief Lance la boucle de traitement des évènements SDL.
     * @param displayParams Paramètres d'affichage.
     */
	void doEventsLoop(DisplayManager* displayParams);
};

#endif	// GUI_H

