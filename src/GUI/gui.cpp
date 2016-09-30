/******************************************************************************\
*     Copyright (C) 2016 by Alexandre Rabérin                                  * 
*     Based on Copyright (C) 2016 by Rémy Malgouyres                           * 
*     http://malgouyres.org                                                    * 
*                                                                              * 
* The program is distributed under the terms of the GNU General Public License * 
*                                                                              * 
\******************************************************************************/ 

#include "gui.h"

// Initialisation des variables statiques
SDL_TimerID WrapperSDL::EventController::m_timerId;

///////////////////////////////////////
/// Event Controller du Wrapper SDL ///
///////////////////////////////////////
void WrapperSDL::EventController::init(DisplayManager* displayParams)
{
	// Enregistrement d'un timer de raffraichissement de la vue 
	m_timerId = SDL_AddTimer(20, createTimerRefreshFrame, (void*)displayParams);
}

void WrapperSDL::EventController::doEventsLoop(SDL_Window* window, DisplayManager* displayParams)
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
			end = handle_SDL_Event(&event, window, displayParams);
		}
	}
}

Uint32 WrapperSDL::EventController::createTimerRefreshFrame(Uint32 interval, void* displayManager)
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


///////////////////////////////////////
//// Window Manager du Wrapper SDL ////
///////////////////////////////////////
WrapperSDL::WindowManager::WindowManager(	int initWindowWidth, 
											int initWindowHeight,
											const char* windowTitle)
	// Initialisation d'une fenêtre SDL
	: m_window(init_SDL_Window(initWindowWidth, initWindowHeight, windowTitle))
	// Création du contexte OpenGL associé à cette fenêtre 		
	, m_glContext(new SDL_GLContext(SDL_GL_CreateContext(m_window)))
{
}

SDL_Window* WrapperSDL::WindowManager::init_SDL_Window(int windowWidth, int windowHeight, const char* windowTitle)
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

WrapperSDL::WindowManager::~WindowManager()
{
	SDL_GL_DeleteContext(*m_glContext);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
	
	delete m_glContext;
}


///////////////////////////////////////
///////////// Wrapper SDL /////////////
///////////////////////////////////////
WrapperSDL::WrapperSDL(	int initWindowWidth, int initWindowHeight, const char* windowTitle)
	: m_windowManager(initWindowWidth, initWindowHeight, windowTitle)
{
}

void WrapperSDL::init(DisplayManager* displayParams)
{
	EventController::init(displayParams);
}

void WrapperSDL::doEventsLoop(DisplayManager* displayParams)
{
	EventController::doEventsLoop(m_windowManager.window(), displayParams);
}

