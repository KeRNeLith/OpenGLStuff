/******************************************************************************\
*     Copyright (C) 2016 by Alexandre Rabérin                                  * 
*     Based on Copyright (C) 2016 by Rémy Malgouyres                           * 
*     http://malgouyres.org                                                    * 
*                                                                              * 
* The program is distributed under the terms of the GNU General Public License * 
*                                                                              * 
\******************************************************************************/

#ifndef MOUSEDATA_H
#define MOUSEDATA_H

#include <SDL2/SDL.h>

/**
 * @brief The MouseData struct Modèle pour la souris (interaction utilisateur).
 * Elle contient des paramètres concernant la souris (état, vitesse, etc.).
 */
struct MouseData
{
	// Variables globales pour gestion de la souris
    static Sint32 mouseX; 	///< Mémorise la dernière position en X de la souris.
    static Sint32 mouseY; 	///< Mémorise la dernière position en Y de la souris.
    static bool leftButtonPressed; 		///< État du bouton gauche de la souris.
    static bool middleButtonPressed; 	///< État du bouton du milieu de la souris.
    static bool rightButtonPressed;     ///< État du bouton droit de la souris.
    static float speed; 	///< Facteur vitesse de la souris.
};

#endif  // MOUSEDATA_H
