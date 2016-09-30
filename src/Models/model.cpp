/******************************************************************************\
*     Copyright (C) 2016 by Alexandre Rabérin                                  * 
*     Based on Copyright (C) 2016 by Rémy Malgouyres                           * 
*     http://malgouyres.org                                                    * 
*                                                                              * 
* The program is distributed under the terms of the GNU General Public License * 
*                                                                              * 
\******************************************************************************/

#include "model.h"

Model::Model()
	: m_grayLevel(0.0f)
{
}

void Model::update()
{
	m_grayLevel += 0.01f;
	if (m_grayLevel > 1.0f)
	{
		m_grayLevel = 0.0f;
	}
}

