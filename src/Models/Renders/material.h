/******************************************************************************\
*     Copyright (C) 2016 by Alexandre Rabérin                                  *
*                                                                              *
* The program is distributed under the terms of the GNU General Public License *
*                                                                              *
\******************************************************************************/

#ifndef MATERIAL_H
#define MATERIAL_H

#include <array>

#include <GL/glut.h>

/**
 * @brief The Material class Gère les données liées à un matériau pouvant être affecté à un objet.
 */
class Material
{
private:
    std::array<GLfloat, 4> m_ambient;   ///< Coefficient de réflexion ambiant.
    std::array<GLfloat, 4> m_diffuse;   ///< Coefficient de réflexion diffuse.
    std::array<GLfloat, 4> m_specular;  ///< Coefficient de réflexion spéculaire.
    GLfloat m_shininess;                ///< Brillance.

public:
    /**
     * @brief Constructeur.
     * @param ambientR Composante rouge du coefficient de réflexion ambiant.
     * @param ambientG Composante verte du coefficient de réflexion ambiant.
     * @param ambientB Composante bleu du coefficient de réflexion ambiant.
     * @param diffuseR Composante rouge du coefficient de réflexion diffuse.
     * @param diffuseG Composante verte du coefficient de réflexion diffuse.
     * @param diffuseB Composante bleu du coefficient de réflexion diffuse.
     * @param specularR Composante rouge du coefficient de réflexion spéculaire.
     * @param specularG Composante verte du coefficient de réflexion spéculaire.
     * @param specularB Composante bleu du coefficient de réflexion spéculaire.
     * @param shininess Brillance.
     */
    Material(GLfloat ambientR, GLfloat ambientG, GLfloat ambientB,
             GLfloat diffuseR, GLfloat diffuseG, GLfloat diffuseB,
             GLfloat specularR, GLfloat specularG, GLfloat specularB,
             GLfloat shininess);

    // Accesseurs
    /**
     * @brief Récupère les coefficients de réflexion ambiant.
     * @return Coefficient de réflexion ambiant.
     */
    const std::array<GLfloat, 4>& getAmbient() const { return m_ambient; }

    /**
     * @brief Affecte les coefficients ambiant.
     * @param ambiantR Composante rouge du coefficient de réflexion ambiant.
     * @param ambiantG Composante verte du coefficient de réflexion ambiant.
     * @param ambiantB Composante bleu du coefficient de réflexion ambiant.
     */
    void setAmbiant(float ambiantR, float ambiantG, float ambiantB)
    {
        m_ambient[0] = ambiantR;
        m_ambient[1] = ambiantG;
        m_ambient[2] = ambiantB;
    }

    /**
     * @brief Récupère les coefficients de réflexion diffuse.
     * @return Coefficient de réflexion diffuse.
     */
    const std::array<GLfloat, 4>& getDiffuse() const { return m_diffuse; }

    /**
     * @brief Récupère les coefficients de réflexion spéculaire.
     * @return Coefficient de réflexion spéculaire.
     */
    const std::array<GLfloat, 4>& getSpecular() const { return m_specular; }

    /**
     * @brief Récupère la brillance.
     * @return Brillance.
     */
    GLfloat getShininess() const { return m_shininess; }

    /**
     * @brief Affecte la brillance.
     * @param shininess Brillance.
     */
    void setShininess(float shininess) { m_shininess = shininess; }
};

#endif // MATERIAL_H
