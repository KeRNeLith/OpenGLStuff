/******************************************************************************\
*     Copyright (C) 2016 by Alexandre Rabérin                                  * 
*                                                                              * 
* The program is distributed under the terms of the GNU General Public License * 
*                                                                              * 
\******************************************************************************/

#ifndef CAMERA_H
#define CAMERA_H

#include <cstring>

#include <GL/glut.h>

/**
 * Classe de gestion de la Caméra.
 */
class Camera
{
private:
    // Les paramètres intrinsèques de la caméra sont
    // les paramètres de l'opération gluPerspective
    GLdouble m_openAngleY;  ///< Angle d'ouverture Y de la caméra.
    GLdouble m_apsect;      ///< Affinité orthogonale en XY.
    GLdouble m_zNear;       ///< Plan de clipping proche.
    GLdouble m_zFar;        ///< Plan de clipping loin.

    // Alternative au gluLookAt
    GLdouble m_distance;    ///< Distance à l'origine de la scène observée.
    GLdouble m_azimuth;     ///< Angle azimuth (autour de l'axe Y).
    GLdouble m_elevation;   ///< Angle d'élévation.

    // La position et l'orientation de la caméra est donnée par
    // les paramètres de l'opération Look At
    GLdouble m_position[3];     ///< Position de la caméra (x, y, z).
    GLdouble m_targetPoint[3];  ///< Point cible de la caméra (Focus).
    GLdouble m_verticalVector[3];   ///< Vecteur vertical à l'axe de vision de la caméra.

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
    Camera(GLdouble openAngleY, GLdouble aspect,
           GLdouble zNear, GLdouble zFar,
           GLdouble posX, GLdouble posY, GLdouble posZ,
           GLdouble targetPointX, GLdouble targetPointY, GLdouble targetPointZ,
           GLdouble verticalVectorX, GLdouble verticalVectorY, GLdouble verticalVectorZ);

    /**
     * @brief Redéfinit les paramètres de position et d'orientation de la caméra.
     * @param position
     * @param targetPoint
     * @param verticalVector
     */
    void lookAt(GLdouble position[3], GLdouble targetPoint[3], GLdouble verticalVector[3]);

    /**
     * @brief Applique la projection en perspective sur les primitives graphiques basé sur les paramètres de la caméra.
     * Note : Seuls les objets affichés ultérieurement sont affichés.
     */
    void applyPerspectiveProjection();

    /**
     * @brief Réinitialise la transformation ModelView à l'identité.
     */
    static void clearModelView();

    /**
     * @brief Réinitialise la transformation Projection à l'identité.
     */
    static void clearProjection();

    /**
     * @brief Applique le changement de repère de la caméra aux primitives graphiques (via gluLookAt).
     * Note : Seuls les objets affichés ultérieurement sont affichés.
     */
    void applyCameraCoordinates();

    // Accesseurs / Setters
    // Position
    /**
     * @brief Récupère à la position X de la caméra.
     * @return Position X de la caméra.
     */
    GLdouble getPosX() const
    {
        return m_position[0];
    }

    /**
     * @brief Récupère à la position Y de la caméra.
     * @return Position Y de la caméra.
     */
    GLdouble getPosY() const
    {
        return m_position[1];
    }

    /**
     * @brief Récupère à la position Z de la caméra.
     * @return Position Z de la caméra.
     */
    GLdouble getPosZ() const
    {
        return m_position[2];
    }

    /**
     * @brief Récupère la position de la caméra.
     * @return Position de la caméra.
     */
    const GLdouble* getPosition() const
    {
        return m_position;
    }

    /**
     * @brief Met à jour la position de la caméra.
     * @param position Nouvelle position de la caméra.
     */
    void setPosition(GLdouble position[3])
    {
        memcpy(m_position, position, 3 * sizeof(GLdouble));
    }

    /**
     * @brief Met à jour la position X de la caméra.
     * @param posX Nouvelle position X de la caméra.
     */
    void setPosX(GLdouble posX)
    {
        m_position[0] = posX;
    }

    /**
     * @brief Met à jour la position Y de la caméra.
     * @param posY Nouvelle position Y de la caméra.
     */
    void setPosY(GLdouble posY)
    {
        m_position[1] = posY;
    }

    /**
     * @brief Met à jour la position Z de la caméra.
     * @param posZ Nouvelle position Z de la caméra.
     */
    void setPosZ(GLdouble posZ)
    {
        m_position[2] = posZ;
    }

    /**
     * @brief Met à jour la position X de la caméra relativement à sa position actuelle.
     * @param offsetX Déplacement sur l'axe X.
     */
    void updatePosX(GLdouble offsetX)
    {
        m_position[0] += offsetX;
    }

    /**
     * @brief Met à jour la position Y de la caméra relativement à sa position actuelle.
     * @param offsetY Déplacement sur l'axe Y.
     */
    void updatePosY(GLdouble offsetY)
    {
        m_position[1] += offsetY;
    }

    /**
     * @brief Met à jour la position Z de la caméra relativement à sa position actuelle.
     * @param offsetZ Déplacement sur l'axe Z.
     */
    void updatePosZ(GLdouble offsetZ)
    {
        m_position[2] += offsetZ;
    }

    // Target point
    /**
     * @brief Récupère à la coordonnée X du point cible de la caméra.
     * @return Coordonnée X de la cible de la caméra.
     */
    GLdouble getTargetX() const
    {
        return m_targetPoint[0];
    }

    /**
     * @brief Récupère à la coordonnée Y du point cible de la caméra.
     * @return Coordonnée Y de la cible de la caméra.
     */
    GLdouble getTargetY() const
    {
        return m_targetPoint[1];
    }

    /**
     * @brief Récupère à la coordonnée Z du point cible de la caméra.
     * @return Coordonnée Z de la cible de la caméra.
     */
    GLdouble getTargetZ() const
    {
        return m_targetPoint[2];
    }

    /**
     * @brief Récupère le point cible de la caméra.
     * @return Cible de la caméra.
     */
    const GLdouble* getTargetPoint() const
    {
        return m_targetPoint;
    }

    /**
     * @brief Met à jour le point cible de la caméra.
     * @param targetPosition Nouvau point cible.
     */
    void setTargetPosition(GLdouble targetPosition[3])
    {
        memcpy(m_targetPoint, targetPosition, 3 * sizeof(GLdouble));
    }

    /**
     * @brief Met à jour la coordonnée X de la cible de la caméra.
     * @param posX Nouvelle position X de la cible de la caméra.
     */
    void setTargetX(GLdouble posX)
    {
        m_targetPoint[0] = posX;
    }

    /**
     * @brief Met à jour la coordonnée Y de la cible de la caméra.
     * @param posY Nouvelle position Y de la cible de la caméra.
     */
    void setTargetY(GLdouble posY)
    {
        m_targetPoint[1] = posY;
    }

    /**
     * @brief Met à jour la coordonnée Z de la cible de la caméra.
     * @param posZ Nouvelle position Z de la cible de la caméra.
     */
    void setTargetZ(GLdouble posZ)
    {
        m_targetPoint[2] = posZ;
    }

    /**
     * @brief Met à jour la coordonnée X de la cible de la caméra relativement à sa position actuelle.
     * @param offsetX Déplacement sur l'axe X.
     */
    void updateTargetX(GLdouble offsetX)
    {
        m_targetPoint[0] += offsetX;
    }

    /**
     * @brief Met à jour la coordonnée Y de la cible de la caméra relativement à sa position actuelle.
     * @param offsetY Déplacement sur l'axe Y.
     */
    void updateTargetY(GLdouble offsetY)
    {
        m_targetPoint[1] += offsetY;
    }

    /**
     * @brief Met à jour la coordonnée Z de la cible de la caméra relativement à sa position actuelle.
     * @param offsetZ Déplacement sur l'axe Z.
     */
    void updateTargetZ(GLdouble offsetZ)
    {
        m_targetPoint[2] += offsetZ;
    }

    // Vertical vector
    /**
     * @brief Récupère le vecteur verticale à l'axe de vision de la caméra.
     * @return Vecteur verticale à l'axe de vision de la caméra.
     */
    const GLdouble* getVerticalVector() const
    {
        return m_verticalVector;
    }

    /**
     * @brief Met à jour le vecteur vertical à l'axe de la caméra.
     * @param verticalVector Nouveau vecteur vertical à l'axe de la caméra.
     */
    void setVerticalVector(GLdouble verticalVector[3])
    {
        memcpy(m_verticalVector, verticalVector, 3 * sizeof(GLdouble));
    }

    // Alternative au gluLookAt
    /**
     * @brief Récupère à la distance de la caméra à la scène.
     * @return Distance de la caméra à la scène.
     */
    GLdouble getDistance() const
    {
        return m_distance;
    }

    /**
     * @brief Met à jour la distance de la caméra à la scène.
     * @param dist Distance de la caméra à la scène.
     */
    void setDistance(GLdouble dist)
    {
        m_distance = dist;
    }

    /**
     * @brief Met à jour la distance de la caméra relativement à sa distance actuelle.
     * @param offset Déplacement sur l'axe Z.
     */
    void updateDistance(GLdouble offset)
    {
        m_distance += offset;
    }

    /**
     * @brief Récupère l'angle azimuth (angle de la caméra autour de l'axe Y).
     * @return Angle azimuth.
     */
    GLdouble getAzimuth() const
    {
        return m_azimuth;
    }

    /**
     * @brief Met à jour l'angle azimuth (angle de la caméra autour de l'axe Y).
     * @param angle Angle azimuth.
     */
    void setAzimuth(GLdouble angle)
    {
        m_azimuth = angle;
    }

    /**
     * @brief Met à jour l'angle azimuth (angle de la caméra autour de l'axe Y) relativement à sa valeur actuelle.
     * @param offset Incrément de l'angle azimuth.
     */
    void updateAzimuth(GLdouble offset)
    {
        m_azimuth += offset;
    }

    /**
     * @brief Récupère l'angle d'élévation de la caméra.
     * @return Angle d'élévation.
     */
    GLdouble getElevation() const
    {
        return m_elevation;
    }

    /**
     * @brief Met à jour l'angle d'élévation de la caméra.
     * @param angle Angle d'élévation.
     */
    void setElevation(GLdouble angle)
    {
        m_elevation = angle;
    }

    /**
     * @brief Met à jour l'angle d'élévation de la caméra relativement à sa valeur actuelle.
     * @param offset Incrément de l'angle d'élévation.
     */
    void updateElevation(GLdouble offset)
    {
        m_elevation += offset;
    }

    // Valeurs intrinsèques
    // Angle d'ouverture
    /**
     * @brief Récupère l'angle d'ouverture sur l'axe Y de la caméra.
     * @return Angle d'ouverture de la caméra.
     */
    GLdouble getOpenAngle() const
    {
        return m_openAngleY;
    }

    /**
     * @brief Met à jour l'angle d'ouverture sur l'axe Y de la caméra.
     * @param angle Nouvel angle d'ouverture de la caméra.
     */
    void setOpenAngle(GLdouble angle)
    {
        if (angle < 0)
            m_openAngleY = 0;
        else
            m_openAngleY = angle;
    }

    /**
     * @brief Met à jour l'angle d'ouverture sur l'axe Y de la caméra relativement à sa valeur actuelle.
     * @param offset Incrément d'angle pour l'angle d'ouverture de la caméra.
     */
    void updateOpenAngle(GLdouble offset)
    {
        if (m_openAngleY + offset < 0)
            m_openAngleY = 0;
        else
            m_openAngleY += offset;
    }

    // Aspect
    /**
     * @brief Récupère l'aspect de la caméra (rapport largeur/hauteur).
     * @return Aspect de la caméra.
     */
    GLdouble getAspect() const
    {
        return m_apsect;
    }

    /**
     * @brief Met à jour l'aspect de la caméra.
     * @param aspect Nouvel aspect de la caméra.
     */
    void setAspect(GLdouble aspect)
    {
        m_apsect = aspect;
    }

    /**
     * @brief Récupère la distance vers le plan de clipping proche.
     * @return Distance au plan de clipping proche.
     */
    GLdouble getNearClipping() const
    {
        return m_zNear;
    }

    /**
     * @brief Met à jour le plan de clipping proche.
     * @param aspect Nouveau plan de clipping proche.
     */
    void setNearClipping(GLdouble zNear)
    {
        m_zNear = zNear;
    }

    /**
     * @brief Récupère la distance vers le plan de clipping loin.
     * @return Distance au plan de clipping loin.
     */
    GLdouble getFarClipping() const
    {
        return m_zFar;
    }

    /**
     * @brief Met à jour le plan de clipping loin.
     * @param aspect Nouveau plan de clipping loin.
     */
    void setFarClipping(GLdouble zFar)
    {
        m_zFar = zFar;
    }

    /**
     * @brief Redéfinit les paramètres de projection en perspective.
     * @param openAngleY Angle d'ouverture Y de la caméra.
     * @param aspect Affinité orthogonale en XY.
     * @param zNear Plan de clipping proche.
     * @param zFar Plan de clipping loin.
     */
    void setProjection(GLdouble openAngleY, GLdouble aspect, GLdouble zNear, GLdouble zFar)
    {
        m_openAngleY = openAngleY;
        m_apsect = aspect;
        m_zNear = zNear;
        m_zFar = zFar;
    }
};

#endif	// CAMERA_H
