#ifndef DRAWABLENODE_H
#define DRAWABLENODE_H

#include <memory>

#include "node.h"

#include "Shaders/shaderprogram.h"

/**
 * @brief The DrawableNode class Stocke les données nécessaires à la réalisation d'un rendu d'un maillage.
 */
class DrawableNode
        : public Node
{
protected:
    std::shared_ptr<ShaderProgram> m_shader;    ///< Programme OpenGL à utiliser.

public:
    /**
     * @brief Constructeur.
     * @param shader Programme shader à utiliser.
     */
    DrawableNode(const std::shared_ptr<ShaderProgram>& shader);

    /**
     * @see Node#apply()
     */
    void apply() override;

    /**
     * @brief Récupère le shader associé au noeud.
     * @return Programme OpenGL.
     */
    const std::shared_ptr<ShaderProgram>& getShader() const
    {
        return m_shader;
    }

    /**
     * @brief Met à jour le programme shader associé au noeud.
     * @param shader Nouveau programme OpenGL à utiliser.
     */
    void setShader(const std::shared_ptr<ShaderProgram>& shader)
    {
        m_shader = shader;
    }
};

#endif // DRAWABLENODE_H
