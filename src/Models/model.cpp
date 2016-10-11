/******************************************************************************\
*     Copyright (C) 2016 by Alexandre Rabérin                                  * 
*     Based on Copyright (C) 2016 by Rémy Malgouyres                           * 
*     http://malgouyres.org                                                    * 
*                                                                              * 
* The program is distributed under the terms of the GNU General Public License * 
*                                                                              * 
\******************************************************************************/

#include "model.h"

#include "Tools/convert.h"

Model::Model()
    : m_sunRadius(6)
    , m_earthRadius(m_sunRadius / double(2))
    , m_sunCoords({{ 0, 0, 0 }})
    , m_earthCoords({{ 3*m_sunRadius, 0, 0 }})
    , m_internalEarthRotationAngle(0)
    , m_earthRotationAngle(0)
    , m_earthRotationAxis({{ 0, 1, 0 }})    // Vertical
{
}

void Model::update()
{
    m_internalEarthRotationAngle += 2;
    m_earthRotationAngle += 1;
}

