/******************************************************************************\
*     Copyright (C) 2016 by Alexandre Rabérin                                  *
*                                                                              *
* The program is distributed under the terms of the GNU General Public License *
*                                                                              *
\******************************************************************************/

#ifndef RENDERSCENE_H
#define RENDERSCENE_H

class Model;

/**
 * @brief The RenderScene class Gère le modèle de rendu et d'éclairage d'une scène.
 */
class RenderScene
{
private:
    const Model& m_model;       ///< Modèle de données de l'application (Gère l'évolution dans le temps).

public:
    /**
     * @brief Constructeur.
     * @param model Modèle de données de l'application.
     */
    RenderScene(const Model& model);

    /**
     * @brief Destructeur.
     */
    virtual ~RenderScene();

    /**
     * @brief Dessine la scène.
     */
    virtual void drawScene() =0;
};

#endif // RENDERSCENE_H
