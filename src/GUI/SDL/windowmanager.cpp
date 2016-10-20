/******************************************************************************\
*     Copyright (C) 2016 by Alexandre Rabérin                                  *
*                                                                              *
* The program is distributed under the terms of the GNU General Public License *
*                                                                              *
\******************************************************************************/

#include "windowmanager.h"

WindowManager::WindowManager(   int initWindowWidth,
                                int initWindowHeight,
                                const char* windowTitle)
    // Initialisation d'une fenêtre SDL
    : m_window(init_SDL_Window(initWindowWidth, initWindowHeight, windowTitle))
    // Création du contexte OpenGL associé à cette fenêtre
    , m_glContext(new SDL_GLContext(SDL_GL_CreateContext(m_window)))
{
}

SDL_Window* WindowManager::init_SDL_Window(int windowWidth, int windowHeight, const char* windowTitle)
{
    // VERSION OPENGL
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_Init(SDL_INIT_VIDEO);

    // Le double buffering permet les animations temps réel
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    SDL_Window* window = SDL_CreateWindow(	windowTitle,
                                                SDL_WINDOWPOS_CENTERED,
                                                SDL_WINDOWPOS_CENTERED,
                                                windowWidth,
                                                windowHeight,
                                                SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);

    return window;
}

WindowManager::~WindowManager()
{
    SDL_GL_DeleteContext(*m_glContext);
    SDL_DestroyWindow(m_window);
    SDL_Quit();

    delete m_glContext;
}
