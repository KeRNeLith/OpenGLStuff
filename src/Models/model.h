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
    double m_sunRadius;     ///< Rayon du soleil (2 fois supérieur à la terre).
    double m_earthRadius;   ///< Rayon de la terre (2 fois inférieur au soleil).

    std::array<double, 3> m_sunCoords;      ///< Coordonnées du centre du soleil.
    std::array<double, 3> m_earthCoords;    ///< Coordonnées du centre de la terre.

    double m_internalEarthRotationAngle;        ///< Angle de rotation de la terre sur elle même.
    double m_earthRotationAngle;                ///< Angle de rotation de la terre autour du soleil.
    std::array<double, 3> m_earthRotationAxis;  ///< Axe de rotation de la terre autour du soleil.

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
     * @brief Récupère les coordonnées du soleil.
     * @return Coordonnées du soleil.
     */
    const std::array<double, 3>& getSunCoords() const
    {
        return m_sunCoords;
    }

    /**
     * @brief Récupère les coordonnées de la terre.
     * @return Coordonnées de la terre.
     */
    const std::array<double, 3>& getEarthCoords() const
    {
        return m_earthCoords;
    }

    /**
     * @brief Récupère la taille du soleil.
     * @return Taille du soleil.
     */
    double getSunSize() const
    {
        return m_sunRadius;
    }

    /**
     * @brief Récupère la taille de la terre.
     * @return Taille de la terre.
     */
    double getEarthSize() const
    {
        return m_earthRadius;
    }

    /**
     * @brief Récupère l'angle de rotation de la terre sur elle même.
     * @return Angle de rotation de la terre sur elle même.
     */
    double getInternalEarthRotationAngle() const
    {
        return m_internalEarthRotationAngle;
    }

    /**
     * @brief Récupère l'angle de rotation de la terre autour du soleil.
     * @return Angle de rotation de la terre autour du soleil.
     */
    double getEarthRotationAngle() const
    {
        return m_earthRotationAngle;
    }

    /**
     * @brief Récupère l'axe de rotation de la terre autour du soleil.
     * @return Axe de rotation de la terre autour du soleil.
     */
    const std::array<double, 3>& getEarthRotationAxis() const
    {
        return m_earthRotationAxis;
    }
};

#endif	// MODEL_H

