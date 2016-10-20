#ifndef TEAPOT_H
#define TEAPOT_H

#include "Models/Renders/renderscene.h"

/**
 * @brief The Teapot class Scène affichant une simple théière.
 */
class Teapot
        : public RenderScene
{
public:
    /**
     * @brief Constructeur.
     * @param model Modèle de données de l'application.
     */
    Teapot(const Model& model);

    /**
     * @see RenderScene#drawScene()
     */
    void drawScene() override;
};

#endif // TEAPOT_H
