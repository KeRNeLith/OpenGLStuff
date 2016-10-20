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

#include "Tools/general.h"

Model::Model()
    : m_defaultMaterial(0.2f, 0.2f, 0.2f,
                        1.0f, 0.0f, 1.0f,
                        1.0f, 0.0f, 1.0f,
                        120.0f)
    , m_shininess(120.0f)
    , m_ambiant(0.2f)
    , m_lights()
{
    // Source 0
    if (!m_lights.addLightSource(LightSource::LandmarkType::CAMERA, GL_LIGHT0, 40.0, 20.0, -20.0))
    {
        std::cerr << "Impossible d'ajouter la source lumineuse GL_LIGHT0" << std::endl;
    }
}

void Model::update()
{
    m_defaultMaterial.setAmbiant(m_ambiant, m_ambiant, m_ambiant);
    m_defaultMaterial.setShininess(m_shininess);
}

