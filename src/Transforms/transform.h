/******************************************************************************\
*     Copyright (C) 2016 by Alexandre Rabérin                                  *
*     Based on Copyright (C) 2016 by Rémy Malgouyres                           *
*     http://malgouyres.org                                                    *
*                                                                              *
* The program is distributed under the terms of the GNU General Public License *
*                                                                              *
\******************************************************************************/

#ifndef GEOMETRIC_TRANSFORM_H
#define GEOMETRIC_TRANSFORM_H

#include <cstdint>

#include <stack>

#include <glm/glm.hpp>

/**
 * @brief The GeometricTransform class Gère des transformations géométriques.
 * Elle sert de Wrapper vers une bibliothèque d'affichage 3D (ici OpenGL, mais pourrait être DirectX).
 */
class GeometricTransform
{
private:
    static glm::mat4 m_currentMatrix;                   ///< Matrice de transformation courante.
    static std::stack< glm::mat4 > m_transformsStack;   ///< Pile de matrices de transformations.

public:
    /**
     * @brief Réinitialise la transformation Model à l'identité.
     */
    static void clearModelMatrix();

    /**
     * @brief Applique une translation (de vecteur donné).
     * @param vecX Déplacement sur l'axe X.
     * @param vecY Déplacement sur l'axe Y.
     * @param vecZ Déplacement sur l'axe Z.
     */
    static void translate(double vecX, double vecY, double vecZ);

    /**
     * @brief Applique une rotation autour de l'axe passant par 0, dirigée par un vecteur donné.
     * @param angle Angle de rotation.
     * @param vecX Axe de rotation (X).
     * @param vecY Axe de rotation (Y).
     * @param vecZ Axe de rotation (Z).
     */
    static void rotate(double angle, double vecX, double vecY, double vecZ);

    /**
     * @brief Applique un changement d'échelle (affinités orthogonales) sur chaque axe.
     * @param factorX Changement d'échelle sur l'axe X.
     * @param factorY Changement d'échelle sur l'axe Y.
     * @param factorZ Changement d'échelle sur l'axe Z.
     */
    static void scale(double factorX, double factorY, double factorZ);

    /**
     * @brief Applique la transformation de matrix à la matrice courante.
     * Matrice courante = matrice courante * matrix.
     * @param matrix Matrice de transformation.
     */
    static void applyTransform(const glm::mat4& matrix);

    /**
     * @brief Sauvegarde la matrice courante dans la pile des matrices de transformations.
     */
    static void pushMatrix();

    /**
     * @brief Restaure la matrice du dessus de la pile des matrices de transformations.
     */
    static void popMatrix();

    /**
     * @brief Get the current transformation.
     * @return Transformation.
     */
    static const glm::mat4& getTransform();
};

#endif	// GEOMETRIC_TRANSFORM_H
