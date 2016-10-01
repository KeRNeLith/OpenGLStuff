/******************************************************************************\
*     Copyright (C) 2016 by Alexandre Rabérin                                  * 
*                                                                              * 
* The program is distributed under the terms of the GNU General Public License * 
*                                                                              * 
\******************************************************************************/

#ifndef RENDERINGMODEL_H
#define RENDERINGMODEL_H

#include <string>

#include <GL/glut.h>

class aiScene;

/**
 * @brief The Model class Gère les modèles de rendu et d'éclairage de la scène.
 */
class RenderingModel
{
private:
    const aiScene* m_scene; ///< Scène 3D.

    /**
     * @brief Charge la scène dont le nom de fichier est spécifié.
     * Note : Il est nécessaire de gérer la désallocation des ressources allouées à la scène.
     * @param sceneFilename Nom du fichier contenant la scène 3D à charger.
     * @return Scène chargée, nullptr si le chargement échou.
     */
    const aiScene* loadScene(const std::string& sceneFilename);

public:
    /**
     * @brief Constructeur.
     * @param sceneFilename Nom du fichier contenant la scène 3D à charger.
     */
    RenderingModel(const std::string& sceneFilename);
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
     * @brief Dessine la scène chargée.
     */
    void drawScene();
};

#endif	// RENDERINGMODEL_H

