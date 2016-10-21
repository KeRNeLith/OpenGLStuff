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

#include <memory>

#include "Models/Textures/texturemanager.h"

/**
 * @brief The Model class Gère le modèle de données de l'application.
 */
class Model
{
private:
    std::shared_ptr<TextureManager> m_texture;   ///< Texture bitmap.

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
     * @brief Récupère un pointeur sur la texture.
     * @return Pointeur sur la texture.
     */
    const std::shared_ptr<TextureManager>& getTexture() const
    {
        return m_texture;
    }
};

#endif	// MODEL_H

