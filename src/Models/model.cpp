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
    : m_wheelSpeed(0.1)
    , m_step(0)
    , m_wheelRotationAxis({{ 1, 0, 0 }})    // Axe X
{
}

void Model::update()
{
    m_step += 10;
}

