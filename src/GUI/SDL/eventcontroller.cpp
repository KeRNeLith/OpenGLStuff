/******************************************************************************\
*     Copyright (C) 2016 by Alexandre Rabérin                                  *
*                                                                              *
* The program is distributed under the terms of the GNU General Public License *
*                                                                              *
\******************************************************************************/

#include "eventcontroller.h"

#include <iostream>

#include "Tools/mouse.h"
#include "GUI/view.h"

// Initialisation des variables statiques
SDL_TimerID EventController::m_timerId;

void EventController::init(DisplayManager* displayParams)
{
    // Enregistrement d'un timer de raffraichissement de la vue
    m_timerId = SDL_AddTimer(20, createTimerRefreshFrame, (void*)displayParams);
}

void EventController::doEventsLoop(SDL_Window* window, DisplayManager* displayParams)
{
    bool end = false;
    SDL_Event event; // Union contenant un évennement

    // Tant que l'on ne demande pas l'arrêt du programme
    while(!end)
    {
        // On défile les évennements
        while (SDL_PollEvent(&event))
        {
            // Gestion de l'événement et modification des variables
            end = handleSDLEvent(&event, window, displayParams);
        }
    }
}

Uint32 EventController::createTimerRefreshFrame(Uint32 interval, void* displayManager)
{
    SDL_UserEvent userEvent;

    userEvent.type = SDL_USEREVENT;
    userEvent.code = 0;
    // Initialisation des données de l'événement nécessaire à l'affichage
    userEvent.data1 = (void*)displayManager; // Fonction de raffraichissement de la vue
    userEvent.data2 = NULL; // On ne l'utilise pas ici

    // On crée l'événement pour la fois suivante
    SDL_Event event;
    event.type = SDL_USEREVENT;
    event.user = userEvent;

    SDL_PushEvent(&event);

    return interval;
}

/**
 * @brief Gestion d'un événement SDL extrait de la file.
 * @param event Données de l'événement.
 * @param window Fenêtre SDL (pour gérer les SDL_WINDOWEVENT).
 * @param displayParams Instance de la classe Vue pour les paramètres d'affichage.
 * @return True si l'événement est SDL_QUIT (fermeture de la fenêtre).
 */
bool EventController::handleSDLEvent(SDL_Event* event, SDL_Window* window, DisplayManager* displayParams)
{
    bool ret = false;

    switch (event->type)	 // Suivant le type d'événement
    {
    //////////////////////////////////////////////////////
    // Événements utilisateur via la souris
    case SDL_MOUSEBUTTONDOWN:   // Enfoncement d'un bouton souris
    case SDL_MOUSEBUTTONUP:     // Relachement d'un bouton souris
    case SDL_MOUSEMOTION:       // Mouvement de la souris
    case SDL_MOUSEWHEEL:
        handleMouseEvent(event, window, displayParams);
        break;

    //////////////////////////////////////////////////////
    // Événements clavier
    case SDL_KEYDOWN:
    case SDL_KEYUP:
    case SDL_TEXTEDITING:
    case SDL_TEXTINPUT:
        handleKeyUpEvent(event, window, displayParams);
        break;

    //////////////////////////////////////////////////////
    // Événements perso
    case SDL_USEREVENT: // Événement timer
        handleUserEvent(event, window, displayParams);
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
        ret = true;
        break;

    default:
        std::cerr << "Évènement " << event->type << " non géré" << std::endl;
    }

    return ret;
}

void EventController::handleKeyboardEvent(SDL_Event* event, SDL_Window* window, DisplayManager* displayParams)
{
    switch (event->type)
    {
    case SDL_KEYDOWN:
        handleKeyDownEvent(event, window, displayParams);
        break;

    case SDL_KEYUP:
        handleKeyUpEvent(event, window, displayParams);
        break;

    default:
        std::cerr << "Évènement clavier non géré" << std::endl;
    }
}

void EventController::handleKeyUpEvent(SDL_Event* /*event*/, SDL_Window* /*window*/, DisplayManager* /*displayParams*/)
{
    // To be implemented
}

void EventController::handleKeyDownEvent(SDL_Event* /*event*/, SDL_Window* /*window*/, DisplayManager* /*displayParams*/)
{
    // To be implemented
}

void EventController::handleMouseEvent(SDL_Event* event, SDL_Window* window, DisplayManager* displayParams)
{
    switch (event->type)
    {
    case SDL_MOUSEBUTTONDOWN:
        handleMouseButtonDownEvent(event, window, displayParams);
        break;

    case SDL_MOUSEBUTTONUP:
        handleMouseButtonUpEvent(event, window, displayParams);
        break;

    case SDL_MOUSEMOTION:
        handleMouseMotionEvent(event, window, displayParams);
        break;

    case SDL_MOUSEWHEEL:
        handleMouseWheelEvent(event, window, displayParams);
        break;

    default:
        std::cerr << "Évènement souris non géré" << std::endl;
    }
}

void EventController::handleMouseButtonDownEvent(SDL_Event* event, SDL_Window* /*window*/, DisplayManager* /*displayParams*/)
{
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

        default:
            std::cerr << "Appui bouton souris non géré" << std::endl;
    }
}

void EventController::handleMouseButtonUpEvent(SDL_Event* event, SDL_Window* /*window*/, DisplayManager* /*displayParams*/)
{
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

    default:
        std::cerr << "Relachement bouton souris non géré" << std::endl;
    }
}

void EventController::handleMouseMotionEvent(SDL_Event* event, SDL_Window* /*window*/, DisplayManager* /*displayParams*/)
{
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
}

void EventController::handleMouseWheelEvent(SDL_Event* /*event*/, SDL_Window* /*window*/, DisplayManager* /*displayParams*/)
{
    // To be implemented
}

void EventController::handleUserEvent(SDL_Event* event, SDL_Window* window, DisplayManager* /*displayParams*/)
{
    // Evènement de rafraichissement
    // Récupération des données de l'événement nécessaire à l'affichage
    DisplayManager* dispParams = static_cast<DisplayManager*>(event->user.data1);

    // Mise à jour du modèle :
    dispParams->model().update();

    // On raffraichit la vue
    dispParams->display();

    SDL_GL_SwapWindow(window); // On envoie le buffer à l'écran
}
