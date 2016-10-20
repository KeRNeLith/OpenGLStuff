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

#include "Models/Renders/material.h"

/**
 * @brief The Model class Gère le modèle de données de l'application.
 */
class Model
{
private:
    Material m_defaultMaterial; ///< Matériau par défaut.
    float m_shininess;          ///< Brillance du matériau.
    float m_ambiant;            ///< Coefficient de lumière ambiante.

    LightSource m_lights;       ///< Gère les différentes sources d'éclairage de la scène.

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
     * @brief Récupère le matériau par défaut.
     * @return Matériau.
     */
    const Material& getDefaultMaterial() const
    {
        return m_defaultMaterial;
    }

    /**
     * @brief Récupère le modèle des sources d'éclairage en lecture/écriture.
     * @return Modèle des sources d'éclairage.
     */
    LightSource& getLights()
	{
        return m_lights;
	}

    /**
     * @brief Met à jour la brillance du matériau par défaut.
     * @param offset Changement de brillance à appliquer.
     */
    void updateShininess(float offset)
    {
        m_shininess += offset;
        clip(m_shininess, 0.0f, 128.0f);
    }

    /**
     * @brief Met à jour les coefficient ambiant du matériau par défaut.
     * @param offset Changement du coefficient ambiant à appliquer.
     */
    void updateAmbiant(float offset)
    {
        m_ambiant += offset;
        clip(m_ambiant, 0.0f, 1.0f);
    }
};

#endif	// MODEL_H

