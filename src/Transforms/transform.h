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

/**
 * @brief The GeometricTransform struct gère des transformations géométriques.
 * Elle sert de Wrapper vers une bibliothèque d'affichage 3D (ici OpenGL, mais pourrait être DirectX).
 */
struct GeometricTransform
{
    /**
     * @brief Définit la zone visible (Viewport).
     * @param viewCenterX Coordonnée X du centre de la vision.
     * @param viewCenterY Coordonnée Y du centre de la vision.
     * @param viewWidth Largeur de la zone de vision.
     * @param viewHeight Hauteur de la zone de vision.
     */
    static void viewport(int32_t viewCenterX,  int32_t viewCenterY, uint32_t viewWidth, uint32_t viewHeight);

    /**
     * @brief Applique une nouvelle projection sur les primitives graphiques, définit par les paramètres.
     * Note: Seuls les objets affichés ultérieurement sont affectés.
     * @param openAngleY Angle d'ouverture Y de la caméra.
     * @param aspect Affinité orthogonale en XY.
     * @param zNear Plan de clipping proche.
     * @param zFar Plan de clipping loin.
     */
    static void applyPerspectiveProjection(double openAngleY, double aspect, double zNear, double zFar);

    /**
     * @brief Réinitialise la transformation ModelView à l'identité.
     */
    static void clearModelView();

    /**
     * @brief Réinitialise la transformation Projection à l'identité.
     */
    static void clearProjection();

    /**
     * @brief Réalise les opérations nécessaire au positionnement de la caméra et son orientation.
     * Note : Appel à gluLookAt.
     * @param position Coordonnées de la caméra.
     * @param targetPoint Coordonnées du point cible.
     * @param verticalVector Verteur vertical à l'axe de vision de la caméra.
     */
    static void lookAt(double position[3], double targetPoint[3], double verticalVector[3]);

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
     * @brief Sauvegarde la matrice courante dans la pile des matrices de transformations.
     */
    static void pushMatrix();

    /**
     * @brief Restaure la matrice du dessus de la pile des matrices de transformations.
     */
    static void popMatrix();
};

#endif	// GEOMETRIC_TRANSFORM_H
