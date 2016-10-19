/******************************************************************************\
*     Copyright (C) 2016 by Alexandre Rabérin                                  * 
*     Based on Copyright (C) 2016 by Rémy Malgouyres                           * 
*     http://malgouyres.org                                                    * 
*                                                                              * 
* The program is distributed under the terms of the GNU General Public License * 
*                                                                              * 
\******************************************************************************/

#include "model.h"

#include <iostream>

Model::Model()
    : m_lights()
{
    // Source 0
    if (!m_lights.addLightSource(LightSource::LandmarkType::CAMERA, GL_LIGHT0, 40.0, 20.0, -20.0))
    {
        std::cerr << "Impossible d'ajouter la source lumineuse GL_LIGHT0" << std::endl;
    }
}

void Model::update()
{
}

