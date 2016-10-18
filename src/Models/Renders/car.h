#ifndef CAR_H
#define CAR_H

#include "renderscene.h"

/**
 * @brief The Car class Gère l'affichage d'une voiture.
 */
class Car
        : public RenderScene
{
private:
    RenderModel m_wheelRender;  ///< Modèle de roue.
    RenderModel m_cubeRender;   ///< Modèle de cube.

    /**
     * @brief Dessine un essieu.
     */
    void drawAxle() const;

public:
    /**
     * @brief Constructeur.
     * @param model Modèle de données de l'application.
     */
    Car(const Model& model);

    /**
     * @brief See RenderScene#drawScene.
     */
    void drawScene() const override;
};

#endif // CAR_H
