#ifndef TRANSFORMNODE_H
#define TRANSFORMNODE_H

#include <glm/glm.hpp>  // Librairie Maths pour les matrices

#include "node.h"

/**
 * @brief The TransformNode class Stocke une transformation géométrique à appliquer.
 */
class TransformNode
        : public Node
{
protected:
    glm::mat4 m_transform;  ///< Transformation à appliquer.

public:
    /**
     * @brief Constructeur.
     * @param transform Transformation du noeud.
     */
    TransformNode(const glm::mat4& transform = glm::mat4(1.0));
    
    /**
     * @see Node#apply()
     */
    void apply() override;
};

#endif // TRANSFORMNODE_H
