/******************************************************************************\
*     Copyright (C) 2016 by Alexandre Rabérin                                  * 
*     Based on Copyright (C) 2016 by Rémy Malgouyres                           * 
*     http://malgouyres.org                                                    * 
*                                                                              * 
* The program is distributed under the terms of the GNU General Public License * 
*                                                                              * 
\******************************************************************************/

#include "frames.h"

#include <cstring>

#include <SDL2/SDL.h>

// Initialisation des données de classe
unsigned int FramesData::m_nbSeconds = 0; 
unsigned int FramesData::m_nbFrames=0;
unsigned int FramesData::m_lastNbFrames=0; 			// Compteur de frames 
unsigned int FramesData::m_nextDueFrameDate = 0; 	// Pour timer affichage 
unsigned int FramesData::m_fps = 0; 				// Pour timer affichage 
char FramesData::m_fpsDescriptor[200];


void FramesData::init()
{
	strcpy(m_fpsDescriptor, "00 Frames en 00s, FPS: --");
}

bool FramesData::update()
{
	bool ret = false;
	
	m_nbFrames++;

	// Gestion des frames par secondes (ici 50 fps) 
	unsigned int currentTime = SDL_GetTicks(); // Date courante en milliseconde 
	
	if (currentTime/1000 > m_nbSeconds)
	{
		m_fps = m_nbFrames - m_lastNbFrames;
		m_lastNbFrames = m_nbFrames;
		m_nbSeconds++;
		
		sprintf(m_fpsDescriptor, 
				"       %4d Frames, en %ds, soit %d FPS       ",
				m_nbFrames,
				m_nbSeconds,
				m_fps);
				
		ret = true;
	}
	
	return ret;
}


