/******************************************************************************\
*     Copyright (C) 2016 by Alexandre Rabérin                                  *
*                                                                              *
* The program is distributed under the terms of the GNU General Public License *
*                                                                              *
\******************************************************************************/

#ifndef POINTLIGHTSOURCE_H
#define POINTLIGHTSOURCE_H

#include <array>

#include <GL/glut.h>

/**
 * @brief The PointLightSource class Gère les données nécessaires à la mise en place de sources lumineuse.
 */
class PointLightSource
{
private:
    GLenum m_lightId;                               ///< Id de la source lumineuse.
    std::array<GLfloat, 4> m_position;              ///< Position de la source lumineuse (x, y, z, 1).
    std::array<GLfloat, 4> m_diffuseIntensity;      ///< Intensité diffuse de la source lumineuse.
    std::array<GLfloat, 4> m_specularIntensity;     ///< Intensité spéculaire de la source lumineuse.

public:
    /**
     * @brief Constructeur.
     * @param ligthId Id de la lumière.
     * @param posX Position X de la source lumineuse.
     * @param posY Position Y de la source lumineuse.
     * @param posZ Position Z de la source lumineuse.
     * @param diffuseIntensityR Intensité diffuse sur la composante rouge.
     * @param diffuseIntensityG Gntensité diffuse sur la composante vert.
     * @param diffuseIntensityB Intensité diffuse sur la composante bleu.
     * @param specularIntensityR Intensité spéculaire sur la composante rouge.
     * @param specularIntensityG Intensité spéculaire sur la composante vert.
     * @param specularIntensityB Intensité spéculaire sur la composante bleu.
     */
    PointLightSource(GLenum lightId,
                     GLfloat posX, GLfloat posY, GLfloat posZ,
                     GLfloat diffuseIntensityR = 0.4f, GLfloat diffuseIntensityG = 0.4f, GLfloat diffuseIntensityB = 0.4f,
                     GLfloat specularIntensityR = 0.4f, GLfloat specularIntensityG = 0.4f, GLfloat specularIntensityB = 0.4f);

    /**
     * @brief Initialiser les paramètres globaux d'éclairage du rendu de la scène.
     */
    static void init();

    /**
     * @brief Positionne une source de lumière dans le repère courant.
     * @param lightId Id de la source de lumière.
     * @param position Position de la source lumineuse.
     */
    static void applyLightPointPosition(GLenum lightId, const std::array<GLfloat, 4>& position);

    /**
     * @brief Active la source de lumière spécifiée et règle son intensité lumineuse (diffuse et spéculaire).
     * @param lightId Id de la source de lumière.
     * @param diffuseIntensity Intensité diffuse de la lumière.
     * @param specularIntensity Intensité spéculaire de la lumière.
     */
    static void applyLightPointIntensity(GLenum lightId, const std::array<GLfloat, 4>& diffuseIntensity, const std::array<GLfloat, 4>& specularIntensity);

    /**
     * @brief Positionne la source de lumière courante dans le repère courant.
     * @param lightId Id de la source de lumière.
     */
    void applyLightPointPosition() const;

    /**
     * @brief Active la source de lumière courante et règle son intensité lumineuse (diffuse et spéculaire).
     * @param lightId Id de la source de lumière.
     */
    void applyLightPointIntensity() const;

    /**
     * @brief Active la source de lumière spécifiée.
     * @param lightId Id de la source de lumière.
     */
    static void enableLightPoint(GLint lightId);

    /**
     * @brief Désactive la source de lumière spécifiée.
     * @param lightId Id de la source de lumière.
     */
    static void disableLightPoint(GLint lightId);

    /**
     * @brief Désactive la source de lumière courante.
     */
    void disableLightPoint() const;

    // Accesseurs / Setters
    /**
     * @brief Récupère l'id de la source lumineuse.
     * @return Id de la source lumineuse.
     */
    GLenum getLightId() const
    {
        return m_lightId;
    }

    // Position
    /**
     * @brief Récupère à la position X de la source lumineuse.
     * @return Position X de la source lumineuse.
     */
    GLfloat getPosX() const
    {
        return m_position[0];
    }

    /**
     * @brief Récupère à la position Y de la source lumineuse.
     * @return Position Y de la source lumineuse.
     */
    GLfloat getPosY() const
    {
        return m_position[1];
    }

    /**
     * @brief Récupère à la position Z de la source lumineuse.
     * @return Position Z de la source lumineuse.
     */
    GLfloat getPosZ() const
    {
        return m_position[2];
    }

    /**
     * @brief Récupère la position de la source lumineuse.
     * @return Position de la source lumineuse.
     */
    const std::array<GLfloat, 4>& getPosition() const
    {
        return m_position;
    }

    /**
     * @brief Met à jour la position de la source lumineuse.
     * @param position Nouvelle position de la source lumineuse.
     */
    void setPosition(const std::array<GLfloat, 3>& position)
    {
        m_position = {{ position[0], position[1], position[2], 1.0 }};
    }

    /**
     * @brief Met à jour la position X de la source lumineuse.
     * @param posX Nouvelle position X de la source lumineuse.
     */
    void setPosX(GLfloat posX)
    {
        m_position[0] = posX;
    }

    /**
     * @brief Met à jour la position Y de la source lumineuse.
     * @param posY Nouvelle position Y de la source lumineuse.
     */
    void setPosY(GLfloat posY)
    {
        m_position[1] = posY;
    }

    /**
     * @brief Met à jour la position Z de la source lumineuse.
     * @param posZ Nouvelle position Z de la source lumineuse.
     */
    void setPosZ(GLfloat posZ)
    {
        m_position[2] = posZ;
    }

    /**
     * @brief Met à jour la position X de la source lumineuse relativement à sa position actuelle.
     * @param offsetX Déplacement sur l'axe X.
     */
    void updatePosX(GLfloat offsetX)
    {
        m_position[0] += offsetX;
    }

    /**
     * @brief Met à jour la position Y de la source lumineuse relativement à sa position actuelle.
     * @param offsetY Déplacement sur l'axe Y.
     */
    void updatePosY(GLfloat offsetY)
    {
        m_position[1] += offsetY;
    }

    /**
     * @brief Met à jour la position Z de la source lumineuse relativement à sa position actuelle.
     * @param offsetZ Déplacement sur l'axe Z.
     */
    void updatePosZ(GLfloat offsetZ)
    {
        m_position[2] += offsetZ;
    }
};

#endif // POINTLIGHTSOURCE_H
