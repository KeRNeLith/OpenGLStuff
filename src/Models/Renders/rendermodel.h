/******************************************************************************\
*     Copyright (C) 2016 by Alexandre Rabérin                                  * 
*                                                                              * 
* The program is distributed under the terms of the GNU General Public License * 
*                                                                              * 
\******************************************************************************/

#ifndef RenderModel_H
#define RenderModel_H

#include <memory>

#include <GL/glut.h>

#include "Models/Textures/texturemanager.h"

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
    std::unique_ptr<Loader> m_object; ///< Scène ou objet chargé.

    /**
     * @brief Charge un objet correspondant au type de modèle spécifié.
     * @param type Type du modèle à instancier.
     * @return Instance du modèle choisi.
     */
    Loader* loadObject(RenderModel::ModelType type);

public:
    /**
     * @brief Constructeur. Construit un objet du type spécifié.
     * @param type Type d'objet.
     * @param texture Texture à appliquer à l'objet.
     */
    RenderModel(RenderModel::ModelType type, const std::shared_ptr<TextureManager>& texture = nullptr);

    /**
     * @brief Constructeur. Instancie un objet chargé depuis un fichier via Assimp.
     * @param filename Chemin vers le fichier à charger.
     */
    RenderModel(const std::string& filename);

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
     * @brief Dessine l'objet chargé.
     */
    void drawObject() const;
};

#endif	// RenderModel_H

