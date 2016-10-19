/******************************************************************************\
*     Copyright (C) 2016 by Alexandre Rabérin                                  * 
*     Based on Copyright (C) 2016 by Rémy Malgouyres                           * 
*     http://malgouyres.org                                                    * 
*                                                                              * 
* The program is distributed under the terms of the GNU General Public License * 
*                                                                              * 
\******************************************************************************/ 

#include "gui.h"

#include <iostream>

#include "Tools/mouse.h"
#include "GUI/view.h"

/**
 * @brief Gestion d'un événement SDL extrait de la file.
 * @param event Données de l'événement.
 * @param window Fenêtre SDL (pour gérer les SDL_WINDOWEVENT).
 * @param displayParams Instance de la classe Vue pour les paramètres d'affichage.
 * @return True si l'événement est SDL_QUIT (fermeture de la fenêtre).
 */
bool WrapperSDL::EventController::handleSDLEvent(SDL_Event* event, SDL_Window* window, DisplayManager* displayParams)
{
	switch (event->type)	 // Suivant le type d'événement
	{ 
	//////////////////////////////////////////////////////
	// Événements utilisateur via la souris
	case SDL_MOUSEBUTTONDOWN: // Enfoncement d'un bouton souris 
		switch (event->button.button)
		{
			case SDL_BUTTON_LEFT :  // Bouton gauche 
				MouseData::leftButtonPressed = true;
				MouseData::mouseX = event->button.x; // Mémorisation coordonnées souris 
				MouseData::mouseY = event->button.y; // Mémorisation coordonnées souris 
				break;
				
			case SDL_BUTTON_MIDDLE :  // Bouton gauche 
				MouseData::middleButtonPressed = true;
				MouseData::mouseX = event->button.x; // Mémorisation coordonnées souris 
				MouseData::mouseY = event->button.y; // Mémorisation coordonnées souris 
				break;
			
            case SDL_BUTTON_RIGHT:      // Bouton droit
                MouseData::rightButtonPressed = true;
                MouseData::mouseX = event->button.x; // Mémorisation coordonnées souris
                MouseData::mouseY = event->button.y; // Mémorisation coordonnées souris
                break;

			default: ;
		}
		break;
		     
	case SDL_MOUSEBUTTONUP: // Relachement d'un bouton souris 
		switch (event->button.button)
		{
		case SDL_BUTTON_LEFT :  	// Bouton gauche 
			MouseData::leftButtonPressed = false;
			break;
		
        case SDL_BUTTON_MIDDLE : 	// Bouton milieu
			MouseData::middleButtonPressed = false;
			break;

        case SDL_BUTTON_RIGHT:      // Bouton droit
            MouseData::rightButtonPressed = false;
            break;

		default: ;
		}
		
		break;  
		
	case SDL_MOUSEMOTION: // Mouvement de la souris 
		if (MouseData::leftButtonPressed)
		{   
			// Mise à jour du modèle
            // Non implémenté
			MouseData::mouseX = event->motion.x; // Enregistrement des nouvelles 
			MouseData::mouseY = event->motion.y; // Coordonnées de la souris 
		}
		
		if (MouseData::middleButtonPressed)
		{
			// Mise à jour du modèle
			// Non implémenté
			MouseData::mouseX = event->motion.x; // Enregistrement des nouvelles 
			MouseData::mouseY = event->motion.y; // Coordonnées de la souris 
		}

        if (MouseData::rightButtonPressed)
        {
            // Mise à jour du modèle
            // Non implémenté
            MouseData::mouseX = event->motion.x; // Enregistrement des nouvelles
            MouseData::mouseY = event->motion.y; // Coordonnées de la souris
        }
    break;

    //////////////////////////////////////////////////////
    // Événements liés au clavier
    case SDL_KEYDOWN:
    {
        float direction = -0.05f;
        switch (event->key.keysym.sym)
        {
        case SDLK_i:
        {
            if (event->key.keysym.mod & KMOD_SHIFT)
            {
                // Handle 'I'
                direction *= -1;
            }
            /*else
            {
                // Handle 'i'
            }*/

            PointLightSource* source = displayParams->model().getLights().getLightSource(GL_LIGHT0);

            if (source)
            {
                source->updateLightPointDiffuseIntensity(direction, direction, direction);
                source->updateLightPointSpecularIntensity(direction, direction, direction);
            }
            break;
        }
        default:
            std::cerr << "Touche non gérée" << std::endl;
            break;
        }
    }
    break;
	
	//////////////////////////////////////////////////////
	// Événements perso : raffraîchissement de la vue
	case SDL_USEREVENT: // Événement timer
	{	  
		// Récupération des données de l'événement nécessaire à l'affichage
		DisplayManager* dispParams = static_cast<DisplayManager*>(event->user.data1);

		// Mise à jour du modèle :
		dispParams->model().update();

		// On raffraichit la vue
		dispParams->display();

		SDL_GL_SwapWindow(window); // On envoie le buffer à l'écran 
	}
		break;

	//////////////////////////////////////////////////////
	// Événements utilisateur sur la fenêtre graphique
	case SDL_WINDOWEVENT: // La fenêtre graphique a changé
		int w, h;
		SDL_GetWindowSize(window, &w, &h); // Récupération taille fenêtre 
		displayParams->resize(w, h);
		break;
	
	//////////////////////////////////////////////////////
	// Fermeture de l'application
	case SDL_QUIT: // Fermeture de la fenêtre 
		return true;
		break;
	
	default:
        std::cerr << "Évènement " << event->type << " non géré" << std::endl;
	}     
	
	return false;
}

