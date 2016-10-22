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

#include <glm/glm.hpp>  // Librairie Maths pour les matrices
#include <glm/gtc/matrix_transform.hpp> // Réglages perspectives, lookAt, etc.

/**
 * @brief The Camera class Classe de gestion de la Caméra.
 */
class Camera
{
private:
    // Les paramètres intrinsèques de la caméra sont
    // les paramètres de l'opération gluPerspective
    double m_openAngleY;  ///< Angle d'ouverture Y de la caméra.
    double m_apsect;      ///< Affinité orthogonale en XY.
    double m_zNear;       ///< Plan de clipping proche.
    double m_zFar;        ///< Plan de clipping loin.

protected:
    glm::mat4 m_projectionMatrix;       ///< Matrice de projection.
    glm::mat4 m_visualisationMatrix;    ///< Matrice de visualisation.

public:
    /**
     * @brief Constructeur.
     * @param openAngleY Angle d'ouverture Y de la caméra.
     * @param aspect Affinité orthogonale en XY.
     * @param zNear Plan de clipping proche.
     * @param zFar Plan de clipping loin.
     */
    Camera(double openAngleY, double aspect,
           double zNear, double zFar);

    /**
     * @brief Applique les paramètres de projection réglé en mettant à jour la matrice de projection à utiliser.
     */
    void applyPerspectiveProjection();

    /**
     * @brief Réinitialise la transformation View à l'identité.
     */
    void clearView();

    /**
     * @brief Réinitialise la transformation Projection à l'identité.
     */
    void clearProjection();

    /**
     * @brief Applique le changement de repère de la caméra aux primitives graphiques.
     */
    virtual void applyCameraTransformation() =0;

    // Accesseurs / Setters
    // Valeurs intrinsèques
    // Angle d'ouverture
    /**
     * @brief Récupère l'angle d'ouverture sur l'axe Y de la caméra.
     * @return Angle d'ouverture de la caméra.
     */
    double getOpenAngle() const
    {
        return m_openAngleY;
    }

    /**
     * @brief Met à jour l'angle d'ouverture sur l'axe Y de la caméra.
     * @param angle Nouvel angle d'ouverture de la caméra.
     */
    void setOpenAngle(double angle)
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
    void updateOpenAngle(double offset)
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
    double getAspect() const
    {
        return m_apsect;
    }

    /**
     * @brief Met à jour l'aspect de la caméra.
     * @param aspect Nouvel aspect de la caméra.
     */
    void setAspect(double aspect)
    {
        m_apsect = aspect;
    }

    /**
     * @brief Récupère la distance vers le plan de clipping proche.
     * @return Distance au plan de clipping proche.
     */
    double getNearClipping() const
    {
        return m_zNear;
    }

    /**
     * @brief Met à jour le plan de clipping proche.
     * @param zNear Nouveau plan de clipping proche.
     */
    void setNearClipping(double zNear)
    {
        m_zNear = zNear;
    }

    /**
     * @brief Récupère la distance vers le plan de clipping loin.
     * @return Distance au plan de clipping loin.
     */
    double getFarClipping() const
    {
        return m_zFar;
    }

    /**
     * @brief Met à jour le plan de clipping loin.
     * @param zFar Nouveau plan de clipping loin.
     */
    void setFarClipping(double zFar)
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
    void setProjection(double openAngleY, double aspect, double zNear, double zFar)
    {
        m_openAngleY = openAngleY;
        m_apsect = aspect;
        m_zNear = zNear;
        m_zFar = zFar;
    }

    /**
     * @brief Récupère la matrice de projection.
     * @return Matrice de projection.
     */
    const glm::mat4& getProjection() const
    {
        return m_projectionMatrix;
    }

    /**
     * @brief Récupère la matrice de visualisation.
     * @return Matrice de visualisation.
     */
    const glm::mat4& getVisualisation() const
    {
        return m_visualisationMatrix;
    }
};

#endif	// CAMERA_H
