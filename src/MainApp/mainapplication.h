/******************************************************************************\
*     Copyright (C) 2016 by Alexandre Rabérin                                  * 
*     Based on Copyright (C) 2016 by Rémy Malgouyres                           * 
*     http://malgouyres.org                                                    * 
*                                                                              * 
* The program is distributed under the terms of the GNU General Public License * 
*                                                                              * 
\******************************************************************************/

#ifndef MAINAPPLICATION_H
#define MAINAPPLICATION_H

#include "GUI/gui.h"
#include "GUI/view.h"

/**
 * @brief The MainApplication class Gère le stockage de toutes les données de l'application.
 * Elle réalise toutes les initialisations.
 * @warning Le gestionnaire GUI initialise le contexte OpenGL qui peut être utilisé par les constructeurs
 * et les paramètres de la vue (choix du mode graphique, etc.).
 * Le gestionnaire de GUI (interface) doit donc être initialisé avant les paramètres d'affichage.
 */
class MainApplication
{
private:
    WrapperSDL m_guiManager;    ///< Gestionnaire de GUI (interface) et du contexte OpenGL.

    DisplayManager m_displayParams; ///< Gestionnaire d'affichage (vue).

public:
    /**
     * @brief Constructeur de l'application.
     * @param initWindowWidth Largeur initiale de la fenêtre graphique
     * @param initWindowHeight Hauteur initiale de la fenêtre graphique
     * @param windowTitle Nom de l'application.
     */
	MainApplication(int initWindowWidth, 
					int initWindowHeight,
					const char* windowTitle);

    /**
     * @brief Lance la boucle d'évènements SDL (attente des évènements).
     */
	void doEventsLoop();
};

#endif	// MAINAPPLICATION_H
