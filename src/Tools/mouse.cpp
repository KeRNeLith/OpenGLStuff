/******************************************************************************\
*     Copyright (C) 2016 by Alexandre Rabérin                                  * 
*     Based on Copyright (C) 2016 by Rémy Malgouyres                           * 
*     http://malgouyres.org                                                    * 
*                                                                              * 
* The program is distributed under the terms of the GNU General Public License * 
*                                                                              * 
\******************************************************************************/

#include "mouse.h"

// Initialisation des données de classe
Sint32 MouseData::mouseX = 0;
Sint32 MouseData::mouseY = 0;
bool MouseData::leftButtonPressed = false;
bool MouseData::middleButtonPressed = false;
bool MouseData::rightButtonPressed = false;
float MouseData::speed = 0.2f;
