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

/**
 * @brief The Model class Gère le modèle de données de l'application.
 */
class Model
{
private:
    double m_wheelSpeed;    ///< Vitesse de rotation d'une roue.
    double m_step;          ///< Etape de rotation d'une roue.
    std::array<double, 3> m_wheelRotationAxis;  ///< Axe de rotation d'une roue.

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
    double getWheelSpeed() const
    {
        return m_wheelSpeed;
    }

    /**
     * @brief Récupère l'angle de rotation d'une roue.
     * @return Angle de rotation d'une roue.
     */
    double getWheelAngle() const
    {
        return m_step*m_wheelSpeed;
    }

    /**
     * @brief Récupère l'axe de rotation d'une roue.
     * @return Axe de rotation d'une roue.
     */
    const std::array<double, 3>& getWheelRotationAxis() const
    {
        return m_wheelRotationAxis;
    }
};

#endif	// MODEL_H

