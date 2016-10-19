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

public:
    /**
     * @brief Constructeur.
     * @param openAngleY Angle d'ouverture Y de la caméra.
     * @param aspect Affinité orthogonale en XY.
     * @param zNear Plan de clipping proche.
     * @param zFar Plan de clipping loin.
     */
    Camera(GLdouble openAngleY, GLdouble aspect,
           GLdouble zNear, GLdouble zFar);

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
     * @brief Applique le changement de repère de la caméra aux primitives graphiques.
     * Note : Seuls les objets affichés ultérieurement sont affichés.
     */
    virtual void applyCameraCoordinates() =0;

    // Accesseurs / Setters
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
