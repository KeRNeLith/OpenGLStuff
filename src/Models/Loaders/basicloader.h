#ifndef BASICLOADER_H
#define BASICLOADER_H

#include "loader.h"

#include "Models/Renders/material.h"

/**
 * @brief The BasicLoader class Gère l'implémentation des structures de données basiques utilisé pour le wrapper sur des modèles définis manuellement.
 */
class BasicLoader
        : public Loader
{
protected:
    std::vector< GLfloat > m_vertices;      ///< Sommets définissant le modèle.
    std::vector< GLfloat > m_normals;       ///< Normales définies sur le modèle.
    std::vector< unsigned int > m_faces;    ///< Faces du modèle.
    Material m_material;                    ///< Matériau du modèle.
    std::vector< GLfloat > m_texCoords;     ///< Coordonnées de textures associées aux sommets.

public:
    /**
     * @brief Constructeur.
     */
    BasicLoader();

    /**
     * @brief Destructeur.
     */
    virtual ~BasicLoader();

    /**
     * @brief See Loader#vertices(int)
     */
    const std::vector< GLfloat >& vertices(int meshIndex = 0) const override;
    /**
     * @brief See Loader#normals(int)
     */
    const std::vector< GLfloat >& normals(int meshIndex = 0) const override;
    /**
     * @brief See Loader#faces(int)
     */
    const std::vector< unsigned int >& faces(int meshIndex = 0) const override;
    /**
     * @brief See Loader#materials(int)
     */
    const Material& materials(int meshIndex = 0) const override;
    /**
     * @brief See Loader#texCoords(int)
     */
    const std::vector< GLfloat >& texCoords(int meshIndex = 0) const override;
    /**
     * @brief See Loader#getGraph()
     */
    std::shared_ptr<Node> getGraph() const override;
};

#endif // BASICLOADER_H
