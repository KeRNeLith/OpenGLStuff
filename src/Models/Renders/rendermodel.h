/******************************************************************************\
*     Copyright (C) 2016 by Adrien Pierreval                                   *
*                                                                              *
* The program is distributed under the terms of the GNU General Public License *
*                                                                              *
\******************************************************************************/

#ifndef RenderModel_H
#define RenderModel_H

#include <memory>

#include <GL/glut.h>

class Loader;

/**
 * @brief The Model class Gère le modèle de rendu et d'éclairage d'un objet.
 */
class RenderModel
{
public:
    /**
     * @brief The ModelType enum Enumère tous les types de modèles disponibles.
     */
    enum ModelType
    {
        CYLINDER
    };

private:
    std::unique_ptr<const Loader> m_object; ///< Scène ou objet chargé.

    /**
     * @brief Charge un objet correspondant au type de modèle spécifié.
     * @param type Type du modèle à instancier.
     * @return Instance du modèle choisi.
     */
    Loader* loadObject(RenderModel::ModelType type);

public:
    /**
     * @brief Constructeur.
     */
    RenderModel(RenderModel::ModelType type = ModelType::CYLINDER);
    // Interdit la copie
    RenderModel(const RenderModel& other) = delete;
    RenderModel& operator= (const RenderModel& other) = delete;
    /**
     * @brief Destructeur.
     */
    ~RenderModel();

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
     * @brief Dessine l'objet chargé.
     */
    void drawObject();
};

#endif	// RenderModel_H

