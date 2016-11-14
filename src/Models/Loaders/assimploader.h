/******************************************************************************\
*     Copyright (C) 2016 by Alexandre Rabérin                                  *
*                                                                              *
* The program is distributed under the terms of the GNU General Public License *
*                                                                              *
\******************************************************************************/

#ifndef ASSIMPLOADER_H
#define ASSIMPLOADER_H

#include <string>

#include "loader.h"

/**
 * @brief The AssimpLoader class Load a 3D model using the ASSIMP library.
 */
class AssimpLoader
        : public Loader
{
private:
    unsigned int m_nbMesh;                                  ///< Nombre de mesh présent dans le fichier chargé via ASSIMP.
    std::vector< GLenum > m_modes;                          ///< Tableau des modes de dessin par mesh chargé par ASSIMP.
    std::vector< std::vector< GLfloat > > m_vertices;       ///< Tableau des tableaux de vertices (Chaque entrée du tableau correspond aux vertices d'un mesh ASSIMP dont les coordonnées sont placés de manière contigus).
    std::vector< std::vector< unsigned int > > m_faces;     ///< Tableau des tableaux de faces (Chaque entrée du tableau correspond aux faces d'un mesh ASSIMP, dont les indices sont placés de manière contigus).
    std::vector< std::vector< GLfloat > > m_texCoords;      ///< Tableau des tableaux des coordonnées de texture (Chaque entrée du tableau correspond aux coordonnées de textures d'un mesh ASSIMP dont les coordonnées sont placés de manière contigus).

    /**
     * @brief Charge la scène dont le nom de fichier est spécifié.
     * @param sceneFilename Nom du fichier contenant la scène 3D à charger.
     */
    void loadScene(const std::string& sceneFilename);

    /**
     * @brief Convertit un mode de dessin de l'énumération de Assimp en mode de l'énumération d'OpenGL.
     * @param assimpMode Mode de dessin de Assimp.
     * @return Mode de dessin OpenGL.
     */
    GLenum getMode(unsigned int assimpMode);

public:
    /**
     * @brief Constructor.
     * @param sceneFilename Path to the 3D model file.
     */
    AssimpLoader(const std::string& sceneFilename);
    // Interdit la copie
    AssimpLoader(const AssimpLoader& other) = delete;
    AssimpLoader& operator= (const AssimpLoader& other) = delete;

    /**
     * @brief Destructeur.
     */
    ~AssimpLoader();

    /**
     * @brief See Loader#meshCount()
     */
    unsigned int meshCount() const override;
    /**
     * @brief See Loader#modes()
     */
    GLenum mode(int meshIndex = 0) const override;
    /**
     * @brief See Loader#vertices(int)
     */
    const std::vector< GLfloat >& vertices(int meshIndex = 0) const override;
    /**
     * @brief See Loader#faces(int)
     */
    const std::vector< unsigned int >& faces(int meshIndex = 0) const override;
    /**
     * @brief See Loader#texCoords(int)
     */
    const std::vector< GLfloat >& texCoords(int meshIndex = 0) const override;

    /**
     * @brief See Loader#getGraph()
     */
    std::shared_ptr<Node> getGraph();
};

#endif // ASSIMPLOADER_H
