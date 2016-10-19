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

#include "Lights/lightsource.h"

/**
 * @brief The Model class Gère le modèle de données de l'application.
 */
class Model
{
private:
    LightSource m_lights;   ///< Gère les différentes sources d'éclairage de la scène.

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
     * @brief Récupère le modèle des sources d'éclairage en lecture/écriture.
     * @return Modèle des sources d'éclairage.
     */
    LightSource& getLights()
	{
        return m_lights;
	}
};

#endif	// MODEL_H

