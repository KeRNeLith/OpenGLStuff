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

#include <SDL2/SDL.h>

// Forward Declarations
class DisplayManager;

/**
 * @brief The WrapperSDL class Wrapper pour SDL et assurant les fonctionnalités de la GUI (interface).
 */
class WrapperSDL
{
    /**
     * @brief The EventController class est le contrôleur d'événements SDL.
     */
	class EventController
	{
	private:
        // Au cas où on ait besoin de modifier
        static SDL_TimerID m_timerId;   ///< Id du timer SDL.

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
		 * @brief Gestion d'un événement SDL extrait de la file
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

    /**
     * @brief The WindowManager class est un gestionnaire de la fenêtre graphique et du contexte OpenGL.
     */
	class WindowManager
	{
	private:
        SDL_Window* m_window;       ///< Fenêtre graphique SDL.
        SDL_GLContext* m_glContext; ///< Contexte OpenGL.
		
	protected:
        /**
         * @brief Initialise la fenêtre d'affichage SDL.
         * @param windowWidth Largeur de la fenêtre.
         * @param windowHeight Hauteur de la fenêtre.
         * @param windowTitle Titre de la fenêtre graphique.
         * @return Instance de fenêtre SDL créée.
         */
		static SDL_Window* init_SDL_Window(int windowWidth, int windowHeight, const char* windowTitle);
		
	public:
        /**
         * @brief Constructeur.
         * @param initWindowWidth Largeur initiale de la fenêtre d'affichage.
         * @param initWindowHeight Hauteur initiale de la fenêtre d'affichage.
         * @param windowTitle Titre de la fenêtre graphique.
         */
		WindowManager(	int initWindowWidth, 
						int initWindowHeight,
						const char* windowTitle);

		// On interdit explicitement la recopie
		WindowManager(const WindowManager&) = delete;
		WindowManager& operator=(const WindowManager&) = delete;

        /**
         * @brief Destructeur : Libération des ressources SDL
         */
		~WindowManager();
		
		// Accesseurs
        /**
         * @brief window Accès en lecture/écriture à la fenêtre graphique.
         * @return Fenêtre graphique SDL.
         */
		SDL_Window*& window()
		{
			return m_window;
		}
	};

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

