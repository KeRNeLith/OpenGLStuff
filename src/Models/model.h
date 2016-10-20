/******************************************************************************\
*     Copyright (C) 2016 by Alexandre Rabérin                                  * 
*     Based on Copyright (C) 2016 by Rémy Malgouyres                           * 
*     http://malgouyres.org                                                    * 
*                                                                              * 
* The program is distributed under the terms of the GNU General Public License * 
*                                                                              * 
\******************************************************************************/

#ifndef MODEL_H
#define MODEL_H

#include <array>

#include "Models/Textures/texturemanager.h"

/**
 * @brief The Model class Gère le modèle de données de l'application.
 */
class Model
{
private:
    TextureManager m_texture;

public:
    /**
     * @brief Constructeur initialisant les données nécessaires à l'affichage.
     */
	Model();

    /**
     * @brief update Met à jour le modèle de données (appelé à chaque évènement timer).
     */
	void update();
	
	// Accesseurs
    /**
     * @brief Récupère la vitesse de rotation d'une roue.
     * @return Vitesse de rotation d'une roue.
     */
    const TextureManager & getTexture() const
    {
        return m_texture;
    }

};

#endif	// MODEL_H

