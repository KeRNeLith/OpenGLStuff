#ifndef OBJECTDATASTORAGE_H
#define OBJECTDATASTORAGE_H

#include <vector>

#include <GLES3/gl3.h>

#include "Models/Loaders/loader.h"

/**
 * @brief The ObjectDataStorage class Stocke les données nécessaire à un objet 3D.
 */
class ObjectDataStorage
{
private:
    std::vector< GLfloat > m_vertices;      ///< Sommets définissant le modèle.
    std::vector< GLfloat > m_normals;       ///< Normales définies sur le modèle.
    std::vector< unsigned int > m_faces;    ///< Faces du modèle.
    std::vector< GLfloat > m_texCoords;     ///< Coordonnées de textures associées aux sommets.

public:
    /**
     * @brief Constructeur.
     * @param v Tableau de sommets.
     * @param n Tableau des normales.
     * @param f Tableau des faces (indices des sommets).
     * @param tc Tableau des coordonnées de texture.
     */
    ObjectDataStorage(const std::vector< GLfloat >& v,
                      const std::vector< GLfloat >& n,
                      const std::vector< unsigned int >& f,
                      const std::vector< GLfloat >& tc);

    /**
     * @brief Constructeur.
     * @param loader Chargeur de modèle.
     * @param index Indice du maillage à récupérer dans le chargeur.
     */
    ObjectDataStorage(const Loader& loader, unsigned int index);

    /**
     * @brief Récupère le tableaux des sommets (indices donnés de manière contigu).
     * @return Tableau des sommets.
     */
    const std::vector< GLfloat >& vertices() const
    {
        return m_vertices;
    }

    /**
     * @brief Récupère le tableaux des normales (indices donnés de manière contigu).
     * @return Tableau des normales.
     */
    const std::vector< GLfloat >& normals() const
    {
        return m_normals;
    }

    /**
     * @brief Récupère le tableaux des faces (indices donnés de manière contigu).
     * @return Tableau des faces (Indices des sommets nécessaires).
     */
    const std::vector< unsigned int >& faces() const
    {
        return m_faces;
    }

    /**
     * @brief Récupère le tableaux des coordonnées de texture (coordonnées données de manière contigu).
     * @return Tableau des coordonnées de texture.
     */
    const std::vector< GLfloat >& texCoords() const
    {
        return m_texCoords;
    }
};

#endif // OBJECTDATASTORAGE_H
