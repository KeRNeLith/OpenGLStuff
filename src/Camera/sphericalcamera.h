/******************************************************************************\
*     Copyright (C) 2016 by Alexandre Rabérin                                  *
*                                                                              *
* The program is distributed under the terms of the GNU General Public License *
*                                                                              *
\******************************************************************************/

#ifndef SPHERICALCAMERA_H
#define SPHERICALCAMERA_H

#include "camera.h"

/**
 * @brief The SphericalCamera class Classe de gestion de la Caméra utilisant des mouvements sphériques.
 */
class SphericalCamera
        : public Camera
{
private:
    // La position et l'orientation de la caméra
    // Alternative au gluLookAt
    double m_distance;    ///< Distance à l'origine de la scène observée.
    double m_azimuth;     ///< Angle azimuth (autour de l'axe Y).
    double m_elevation;   ///< Angle d'élévation.

public:
    /**
     * @brief Constructeur.
     * @param openAngleY Angle d'ouverture Y de la caméra.
     * @param aspect Affinité orthogonale en XY.
     * @param zNear Plan de clipping proche.
     * @param zFar Plan de clipping loin.
     * @param dist Distance à la scène 3D.
     * @param azimuth Angle azimuth (rotation sur l'axe Y).
     * @param elevation Angle d'élévation (rotation sur l'axe X).
     */
    SphericalCamera(    double openAngleY, double aspect,
                        double zNear, double zFar,
                        double dist, double azimuth, double elevation);

    /**
     * @brief Applique le changement de repère de la caméra aux primitives graphiques.
     */
    void applyCameraTransformation() override;

    // Accesseurs / Setters
    /**
     * @brief Récupère à la distance de la caméra à la scène.
     * @return Distance de la caméra à la scène.
     */
    double getDistance() const
    {
        return m_distance;
    }

    /**
     * @brief Met à jour la distance de la caméra à la scène.
     * @param dist Distance de la caméra à la scène.
     */
    void setDistance(double dist)
    {
        m_distance = dist;
    }

    /**
     * @brief Met à jour la distance de la caméra relativement à sa distance actuelle.
     * @param offset Déplacement sur l'axe Z.
     */
    void updateDistance(double offset)
    {
        m_distance += offset;
    }

    /**
     * @brief Récupère l'angle azimuth (angle de la caméra autour de l'axe Y).
     * @return Angle azimuth.
     */
    double getAzimuth() const
    {
        return m_azimuth;
    }

    /**
     * @brief Met à jour l'angle azimuth (angle de la caméra autour de l'axe Y).
     * @param angle Angle azimuth.
     */
    void setAzimuth(double angle)
    {
        m_azimuth = angle;
    }

    /**
     * @brief Met à jour l'angle azimuth (angle de la caméra autour de l'axe Y) relativement à sa valeur actuelle.
     * @param offset Incrément de l'angle azimuth.
     */
    void updateAzimuth(double offset)
    {
        m_azimuth += offset;
    }

    /**
     * @brief Récupère l'angle d'élévation de la caméra.
     * @return Angle d'élévation.
     */
    double getElevation() const
    {
        return m_elevation;
    }

    /**
     * @brief Met à jour l'angle d'élévation de la caméra.
     * @param angle Angle d'élévation.
     */
    void setElevation(double angle)
    {
        m_elevation = angle;
    }

    /**
     * @brief Met à jour l'angle d'élévation de la caméra relativement à sa valeur actuelle.
     * @param offset Incrément de l'angle d'élévation.
     */
    void updateElevation(double offset)
    {
        m_elevation += offset;
    }
};

#endif	// SPHERICALCAMERA_H
