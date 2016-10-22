#ifndef CUSTOMSCENE_H
#define CUSTOMSCENE_H

#include "renderscene.h"

/**
 * @brief The CustomScene class Gère l'affichage d'une scène personnalisée.
 */
class CustomScene
        : public RenderScene
{
private:
    RenderModel m_cylinderRender;  ///< Modèle de cylindre.

public:
    /**
     * @brief Constructeur.
     * @param model Modèle de données de l'application.
     */
    CustomScene(const Model& model);

    /**
     * @brief See RenderScene#drawScene.
     */
    void drawScene() const override;
};

#endif // CUSTOMSCENE_H
