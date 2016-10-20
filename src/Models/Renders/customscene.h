#ifndef CUSTOMSCENE_H
#define CUSTOMSCENE_H

#include "Models/Renders/rendermodel.h"
#include "Models/Renders/renderscene.h"

/**
 * @brief The CustomScene class Charge des modèles et les affiche dans un certain ordre et agencement.
 */
class CustomScene
        : public RenderScene
{
private:
    RenderModel m_object;   ///< Objet présent dans la scène.

public:
    /**
     * @brief Constructeur.
     * @param model Modèle de données de l'application.
     */
    CustomScene(const Model& model);

    /**
     * @see RenderScene#drawScene()
     */
    void drawScene() override;
};

#endif // CUSTOMSCENE
