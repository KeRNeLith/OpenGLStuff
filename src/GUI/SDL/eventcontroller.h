/******************************************************************************\
*     Copyright (C) 2016 by Alexandre Rabérin                                  *
*                                                                              *
* The program is distributed under the terms of the GNU General Public License *
*                                                                              *
\******************************************************************************/

#ifndef EVENTCONTROLLER_H
#define EVENTCONTROLLER_H

#include <SDL2/SDL.h>

// Forward Declarations
class DisplayManager;

/**
 * @brief The EventController class est le contrôleur d'événements SDL.
 */
class EventController
{
private:
    // Au cas où on ait besoin de modifier
    static SDL_TimerID m_timerId;   ///< Id du timer SDL.

    static double m_motionSpeed;    ///< Vitesse des mouvements.

    // Fonctions de gestion des évènements
    // Clavier
    /**
     * @brief Gestion d'un événement SDL clavier.
     * @param event Données de l'événement SDL.
     * @param window Fenêtre SDL (pour gérer les SDL_WINDOWEVENT).
     * @param displayParams Instance de la classe Vue pour obtenir les paramètres d'affichage.
     */
    static void handleKeyboardEvent(SDL_Event* event, SDL_Window* window, DisplayManager* displayParams);

    /**
     * @brief Gestion d'un événement SDL clavier (appui de touche).
     * @param event Données de l'événement SDL.
     * @param window Fenêtre SDL (pour gérer les SDL_WINDOWEVENT).
     * @param displayParams Instance de la classe Vue pour obtenir les paramètres d'affichage.
     */
    static void handleKeyDownEvent(SDL_Event* event, SDL_Window* window, DisplayManager* displayParams);

    /**
     * @brief Gestion d'un événement SDL clavier (relachement de touche).
     * @param event Données de l'événement SDL.
     * @param window Fenêtre SDL (pour gérer les SDL_WINDOWEVENT).
     * @param displayParams Instance de la classe Vue pour obtenir les paramètres d'affichage.
     */
    static void handleKeyUpEvent(SDL_Event* event, SDL_Window* window, DisplayManager* displayParams);

    // Souris
    /**
     * @brief Gestion d'un événement SDL souris.
     * @param event Données de l'événement SDL.
     * @param window Fenêtre SDL (pour gérer les SDL_WINDOWEVENT).
     * @param displayParams Instance de la classe Vue pour obtenir les paramètres d'affichage.
     */
    static void handleMouseEvent(SDL_Event* event, SDL_Window* window, DisplayManager* displayParams);

    /**
     * @brief Gestion d'un événement SDL souris (appui d'un bouton souris).
     * @param event Données de l'événement SDL.
     * @param window Fenêtre SDL (pour gérer les SDL_WINDOWEVENT).
     * @param displayParams Instance de la classe Vue pour obtenir les paramètres d'affichage.
     */
    static void handleMouseButtonDownEvent(SDL_Event* event, SDL_Window* window, DisplayManager* displayParams);

    /**
     * @brief Gestion d'un événement SDL souris (relachement d'un bouton souris).
     * @param event Données de l'événement SDL.
     * @param window Fenêtre SDL (pour gérer les SDL_WINDOWEVENT).
     * @param displayParams Instance de la classe Vue pour obtenir les paramètres d'affichage.
     */
    static void handleMouseButtonUpEvent(SDL_Event* event, SDL_Window* window, DisplayManager* displayParams);

    /**
     * @brief Gestion d'un événement SDL souris (molette souris).
     * @param event Données de l'événement SDL.
     * @param window Fenêtre SDL (pour gérer les SDL_WINDOWEVENT).
     * @param displayParams Instance de la classe Vue pour obtenir les paramètres d'affichage.
     */
    static void handleMouseWheelEvent(SDL_Event* event, SDL_Window* window, DisplayManager* displayParams);

    /**
     * @brief Gestion d'un événement SDL souris (déplacement de souris).
     * @param event Données de l'événement SDL.
     * @param window Fenêtre SDL (pour gérer les SDL_WINDOWEVENT).
     * @param displayParams Instance de la classe Vue pour obtenir les paramètres d'affichage.
     */
    static void handleMouseMotionEvent(SDL_Event* event, SDL_Window* window, DisplayManager* displayParams);

    // Personnalisé
    /**
     * @brief Gestion d'un événement utilisateur (défini par le programmeur).
     * @param event Données de l'événement SDL.
     * @param window Fenêtre SDL (pour gérer les SDL_WINDOWEVENT).
     * @param displayParams Instance de la classe Vue pour obtenir les paramètres d'affichage.
     */
    static void handleUserEvent(SDL_Event* event, SDL_Window* window, DisplayManager* displayParams);

public:
    /**
     * @brief Initialisation du timer SDL.
     * @param displayParams Paramètres d'affichage.
     */
    static void init(DisplayManager* displayParams);

    /**
     * @brief Boucle d'attente des événements SDL.
     * @param window Fenêtre SDL (pour gérer les SDL_WINDOWEVENT).
     * @param displayParams Instance de la classe Vue avec les paramètres d'affichage.
     */
    static void doEventsLoop(SDL_Window* window, DisplayManager* displayParams);

    /**
     * @brief Gestion d'un événement SDL extrait de la file.
     * @param event Données de l'événement SDL.
     * @param window Fenêtre SDL (pour gérer les SDL_WINDOWEVENT).
     * @param displayParams Instance de la classe Vue pour obtenir les paramètres d'affichage.
     * @return True si l'événement est SDL_QUIT (fermeture de la fenêtre).
     */
    static bool handleSDLEvent(SDL_Event* event, SDL_Window* window, DisplayManager* displayParams);

    /**
     * @brief Callback du timer de raffraichissement de la vue.
     * @see http://sdl.beuc.net/sdl.wiki/SDL_AddTimer
     * @param interval Intervalle jusqu'au prochain déclenchement du timer.
     * @param displayManager Pointeur sur la fonction de rafraichissement de l'affichage.
     * @return Intervalle jusqu'au prochain déclenchement du timer.
     */
    static Uint32 createTimerRefreshFrame(Uint32 interval, void* displayManager);

    // Accesseurs
    /**
     * @brief getTimerId Permet de récupérer l'id du timer SDL.
     * @return Id du timer.
     */
    static SDL_TimerID getTimerId()
    {
        return m_timerId;
    }
};

#endif // EVENTCONTROLLER_H
