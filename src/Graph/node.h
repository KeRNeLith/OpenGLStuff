#ifndef NODE_H
#define NODE_H

#include <memory>
#include <vector>

/**
 * @brief The Node class Base pour la notion de noeud de graphe de scène.
 */
class Node
{
public:
    using NodeList = std::vector< std::shared_ptr<Node> >;

protected:
    NodeList m_children;    ///< Liste des noeuds fils.

public:
    /**
     * @brief Constructeur.
     */
    Node();
    /**
     * @brief Destructeur.
     */
    virtual ~Node();

    /**
     * @brief Applique le rôle du noeud.
     */
    virtual void apply();

    /**
     * @brief Ajoute un noeud fils au noeud.
     * @param node Noeud à ajouter.
     */
    void addChild(const std::shared_ptr<Node>& node);
};

#endif // NODE_H
