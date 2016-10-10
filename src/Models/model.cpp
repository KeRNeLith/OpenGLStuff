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
    : m_sunRadius(6)
    , m_earthRadius(m_sunRadius / double(2))
    , m_sunCoords({{ 0, 0, 0 }})
    , m_earthCoords({{ 5, 5, 5 }})
{
}

void Model::update()
{

}

