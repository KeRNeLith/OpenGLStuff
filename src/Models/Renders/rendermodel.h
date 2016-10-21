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
    RenderModel(RenderModel::ModelType type);
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

