/******************************************************************************\
*     Copyright (C) 2016 by Alexandre Rabérin                                  * 
*     Based on Copyright (C) 2016 by Rémy Malgouyres                           * 
*     http://malgouyres.org                                                    * 
*                                                                              * 
* The program is distributed under the terms of the GNU General Public License * 
*                                                                              * 
\******************************************************************************/ 

#include "gui.h"

#include "SDL/eventcontroller.h"

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

