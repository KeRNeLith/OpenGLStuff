/******************************************************************************\
*     Copyright (C) 2016 by Alexandre Rabérin                                  * 
*                                                                              * 
* The program is distributed under the terms of the GNU General Public License * 
*                                                                              * 
\******************************************************************************/

#ifndef RENDERINGMODEL_H
#define RENDERINGMODEL_H

#include <memory>

#include <GL/glut.h>

class Loader;

/**
 * @brief The Model class Gère les modèles de rendu et d'éclairage de la scène.
 */
class RenderingModel
{
private:
    std::unique_ptr<const Loader> m_object; ///< Scène ou objet chargé.

public:
    /**
     * @brief Constructeur.
     */
    RenderingModel();
    // Interdit la copie
    RenderingModel(const RenderingModel& other) = delete;
    RenderingModel& operator= (const RenderingModel& other) = delete;
    /**
     * @brief Destructeur.
     */
    ~RenderingModel();

    /**
     * @brief Initialiser les paramètres globaux du rendu de la scène.
     */
    static void init();

    /**
     * @brief Réinitialise la vue (efface l'écran).
     */
    static void initView();

    /**
     * @brief Positionne une source de lumière dans le repère courant.
     * @param lightId Id de la source de lumière.
     * @param position Position dans le repère courant.
     */
    static void applyLightPointPosition(GLint lightId, const GLfloat position[4]);

    /**
     * @brief Active la source de lumière spécifiée et règle son intensité lumineuse.
     * @param lightId Id de la source de lumière.
     * @param diffuseIntensity Intensité diffuse.
     * @param specularIntensity Intensité spéculaire.
     */
    static void applyLightPointIntensity(GLint lightId,
                                         const GLfloat diffuseIntensity[4],
                                         const GLfloat specularIntensity[4]);

    /**
     * @brief Désactive la source de lumière spécifiée.
     * @param lightId Id de la source de lumière.
     */
    static void disableLightPoint(GLint lightId);

    /**
     * @brief Applique des propriétés de matériaux pour les rendus d'objets suivants.
     */
    static void applyMaterial(/* Material material */);

    /**
     * @brief Dessine la scène ou l'objet chargé.
     */
    void drawScene();
};

#endif	// RENDERINGMODEL_H

