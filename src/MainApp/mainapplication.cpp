/******************************************************************************\
*     Copyright (C) 2016 by Alexandre Rabérin                                  * 
*     Based on Copyright (C) 2016 by Rémy Malgouyres                           * 
*     http://malgouyres.org                                                    * 
*                                                                              * 
* The program is distributed under the terms of the GNU General Public License * 
*                                                                              * 
\******************************************************************************/

#include "mainapplication.h"

MainApplication::MainApplication(	int initWindowWidth, 
									int initWindowHeight,
									const char* windowTitle)
	: m_guiManager(initWindowWidth, initWindowHeight, windowTitle)
	, m_displayParams(initWindowWidth, initWindowHeight)
{ 
	m_guiManager.init(&m_displayParams);
}

void MainApplication::doEventsLoop()
{
	m_guiManager.doEventsLoop(&m_displayParams);
}
