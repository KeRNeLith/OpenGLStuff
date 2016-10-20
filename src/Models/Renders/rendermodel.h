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

#include "Models/Renders/material.h"

class Loader;

/**
 * @brief The Model class Gère le modèle de rendu et d'éclairage d'un objet.
 */
class RenderModel
{
private:
    std::unique_ptr<const Loader> m_object; ///< Scène ou objet chargé.

public:
    /**
     * @brief Constructeur.
     * @param filename Chemin du fichier à charger.
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
     * @brief Applique des propriétés de matériaux pour les rendus d'objets suivants.
     * @param material Matériau à appliquer.
     */
    static void applyMaterial(const Material& material);

    /**
     * @brief Dessine l'objet chargé.
     */
    void drawObject();
};

#endif	// RenderModel_H

