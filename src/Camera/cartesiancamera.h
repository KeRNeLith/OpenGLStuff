/******************************************************************************\
*     Copyright (C) 2016 by Alexandre Rabérin                                  * 
*                                                                              * 
* The program is distributed under the terms of the GNU General Public License * 
*                                                                              * 
\******************************************************************************/

#ifndef CARTESIANCAMERA_H
#define CARTESIANCAMERA_H

#include <array>

#include "camera.h"

/**
 * @brief The CartesianCamera class Classe de gestion de la Caméra avec une gestion des coordonnées cartésiennes.
 */
class CartesianCamera
        : public Camera
{
private:
    // La position et l'orientation de la caméra est donnée par
    // les paramètres de l'opération Look At
    std::array<double, 3> m_position;     ///< Position de la caméra (x, y, z).
    std::array<double, 3> m_targetPoint;  ///< Point cible de la caméra (Focus).
    std::array<double, 3> m_verticalVector;   ///< Vecteur vertical à l'axe de vision de la caméra.

public:
    /**
     * @brief Constructeur.
     * @param openAngleY Angle d'ouverture Y de la caméra.
     * @param aspect Affinité orthogonale en XY.
     * @param zNear Plan de clipping proche.
     * @param zFar Plan de clipping loin.
     * @param posX Position X de la caméra.
     * @param posY Position Y de la caméra.
     * @param posZ Position Z de la caméra.
     * @param targetPointX Coordonnée X du point cible de la caméra.
     * @param targetPointY Coordonnée Y du point cible de la caméra.
     * @param targetPointZ Coordonnée Z du point cible de la caméra.
     * @param verticalVectorX Coordonnée X du vecteur vertical à l'axe de vision de la caméra.
     * @param verticalVectorY Coordonnée Y du vecteur vertical à l'axe de vision de la caméra.
     * @param verticalVectorZ Coordonnée Z du vecteur vertical à l'axe de vision de la caméra.
     */
    CartesianCamera(    double openAngleY, double aspect,
                        double zNear, double zFar,
                        double posX, double posY, double posZ,
                        double targetPointX, double targetPointY, double targetPointZ,
                        double verticalVectorX, double verticalVectorY, double verticalVectorZ);

    /**
     * @brief Redéfinit les paramètres de position et d'orientation de la caméra.
     * @param position
     * @param targetPoint
     * @param verticalVector
     */
    void lookAt(const std::array<double, 3>& position, const std::array<double, 3>& targetPoint, const std::array<double, 3>& verticalVector);

    /**
     * @brief Applique le changement de repère de la caméra aux primitives graphiques.
     */
    void applyCameraTransformation() override;

    // Accesseurs / Setters
    // Position
    /**
     * @brief Récupère à la position X de la caméra.
     * @return Position X de la caméra.
     */
    double getPosX() const
    {
        return m_position[0];
    }

    /**
     * @brief Récupère à la position Y de la caméra.
     * @return Position Y de la caméra.
     */
    double getPosY() const
    {
        return m_position[1];
    }

    /**
     * @brief Récupère à la position Z de la caméra.
     * @return Position Z de la caméra.
     */
    double getPosZ() const
    {
        return m_position[2];
    }

    /**
     * @brief Récupère la position de la caméra.
     * @return Position de la caméra.
     */
    const std::array<double, 3>& getPosition() const
    {
        return m_position;
    }

    /**
     * @brief Met à jour la position de la caméra.
     * @param position Nouvelle position de la caméra.
     */
    void setPosition(const std::array<double, 3>& position)
    {
        m_position = position;
    }

    /**
     * @brief Met à jour la position X de la caméra.
     * @param posX Nouvelle position X de la caméra.
     */
    void setPosX(double posX)
    {
        m_position[0] = posX;
    }

    /**
     * @brief Met à jour la position Y de la caméra.
     * @param posY Nouvelle position Y de la caméra.
     */
    void setPosY(double posY)
    {
        m_position[1] = posY;
    }

    /**
     * @brief Met à jour la position Z de la caméra.
     * @param posZ Nouvelle position Z de la caméra.
     */
    void setPosZ(double posZ)
    {
        m_position[2] = posZ;
    }

    /**
     * @brief Met à jour la position X de la caméra relativement à sa position actuelle.
     * @param offsetX Déplacement sur l'axe X.
     */
    void updatePosX(double offsetX)
    {
        m_position[0] += offsetX;
    }

    /**
     * @brief Met à jour la position Y de la caméra relativement à sa position actuelle.
     * @param offsetY Déplacement sur l'axe Y.
     */
    void updatePosY(double offsetY)
    {
        m_position[1] += offsetY;
    }

    /**
     * @brief Met à jour la position Z de la caméra relativement à sa position actuelle.
     * @param offsetZ Déplacement sur l'axe Z.
     */
    void updatePosZ(double offsetZ)
    {
        m_position[2] += offsetZ;
    }

    // Target point
    /**
     * @brief Récupère à la coordonnée X du point cible de la caméra.
     * @return Coordonnée X de la cible de la caméra.
     */
    double getTargetX() const
    {
        return m_targetPoint[0];
    }

    /**
     * @brief Récupère à la coordonnée Y du point cible de la caméra.
     * @return Coordonnée Y de la cible de la caméra.
     */
    double getTargetY() const
    {
        return m_targetPoint[1];
    }

    /**
     * @brief Récupère à la coordonnée Z du point cible de la caméra.
     * @return Coordonnée Z de la cible de la caméra.
     */
    double getTargetZ() const
    {
        return m_targetPoint[2];
    }

    /**
     * @brief Récupère le point cible de la caméra.
     * @return Cible de la caméra.
     */
    const std::array<double, 3>& getTargetPoint() const
    {
        return m_targetPoint;
    }

    /**
     * @brief Met à jour le point cible de la caméra.
     * @param targetPosition Nouvau point cible.
     */
    void setTargetPosition(const std::array<double, 3>& targetPosition)
    {
        m_targetPoint = targetPosition;
    }

    /**
     * @brief Met à jour la coordonnée X de la cible de la caméra.
     * @param posX Nouvelle position X de la cible de la caméra.
     */
    void setTargetX(double posX)
    {
        m_targetPoint[0] = posX;
    }

    /**
     * @brief Met à jour la coordonnée Y de la cible de la caméra.
     * @param posY Nouvelle position Y de la cible de la caméra.
     */
    void setTargetY(double posY)
    {
        m_targetPoint[1] = posY;
    }

    /**
     * @brief Met à jour la coordonnée Z de la cible de la caméra.
     * @param posZ Nouvelle position Z de la cible de la caméra.
     */
    void setTargetZ(double posZ)
    {
        m_targetPoint[2] = posZ;
    }

    /**
     * @brief Met à jour la coordonnée X de la cible de la caméra relativement à sa position actuelle.
     * @param offsetX Déplacement sur l'axe X.
     */
    void updateTargetX(double offsetX)
    {
        m_targetPoint[0] += offsetX;
    }

    /**
     * @brief Met à jour la coordonnée Y de la cible de la caméra relativement à sa position actuelle.
     * @param offsetY Déplacement sur l'axe Y.
     */
    void updateTargetY(double offsetY)
    {
        m_targetPoint[1] += offsetY;
    }

    /**
     * @brief Met à jour la coordonnée Z de la cible de la caméra relativement à sa position actuelle.
     * @param offsetZ Déplacement sur l'axe Z.
     */
    void updateTargetZ(double offsetZ)
    {
        m_targetPoint[2] += offsetZ;
    }

    // Vertical vector
    /**
     * @brief Récupère le vecteur verticale à l'axe de vision de la caméra.
     * @return Vecteur verticale à l'axe de vision de la caméra.
     */
    const std::array<double, 3>& getVerticalVector() const
    {
        return m_verticalVector;
    }

    /**
     * @brief Met à jour le vecteur vertical à l'axe de la caméra.
     * @param verticalVector Nouveau vecteur vertical à l'axe de la caméra.
     */
    void setVerticalVector(const std::array<double, 3>& verticalVector)
    {
        m_verticalVector = verticalVector;
    }
};

#endif	// CARTESIANCAMERA_H
