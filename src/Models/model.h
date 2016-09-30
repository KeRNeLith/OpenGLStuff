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

/**
 * @brief The Model class Gère le modèle de données de l'application.
 */
class Model
{
private:
	// Niveau de gris du fond
    float m_grayLevel;  // TEMPORARY

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
    // TEMPORARY
	float getGrayLevel() const
	{
		return m_grayLevel;
	}
};

#endif	// MODEL_H

