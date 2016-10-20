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

    std::array<double, 3> m_light1RotationAxis; ///< Axe de rotation de la source lumineuse GL_LIGHT1.
    double m_light1RotationAngle;               ///< Angle de rotation de la source lumineuse GL_LIGHT1.

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

    /**
     * @brief Récupère l'angle de rotation de la source lumineuse GL_LIGHT1.
     * @return Angle de rotation.
     */
    double getLight1RotationAngle() const
    {
        return m_light1RotationAngle;
    }

    /**
     * @brief Récupère l'axe de rotation de la source lumineuse GL_LIGHT1.
     * @return Axe de rotation.
     */
    const std::array<double, 3>& getLight1RotationAxis() const
    {
        return m_light1RotationAxis;
    }
};

#endif	// MODEL_H

