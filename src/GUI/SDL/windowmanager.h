/******************************************************************************\
*     Copyright (C) 2016 by Alexandre Rabérin                                  *
*                                                                              *
* The program is distributed under the terms of the GNU General Public License *
*                                                                              *
\******************************************************************************/

#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H

#include <SDL2/SDL.h>

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
    WindowManager(  int initWindowWidth,
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

#endif // WINDOWMANAGER_H
