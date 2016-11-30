#ifndef DRAWABLENODE_H
#define DRAWABLENODE_H

#include <memory>

#include <GLES3/gl3.h>

#include "node.h"

#include "Models/Renders/rendermodel.h"

#include "Shaders/shaderprogram.h"

/**
 * @brief The DrawableNode class Stocke les données nécessaires à la réalisation d'un rendu d'un maillage.
 */
class DrawableNode
        : public Node
{
protected:
    std::shared_ptr<RenderModel> m_object;      ///< Objet à rendre.

public:
    /**
     * @brief Constructeur.
     * @param model Modèle à rendre sur le noeud.
     */
    DrawableNode(const std::shared_ptr<RenderModel>& model);

    /**
     * @brief Destructeur.
     */
    ~DrawableNode();

    /**
     * @see Node#apply()
     */
    void apply() const override;
};

#endif // DRAWABLENODE_H
