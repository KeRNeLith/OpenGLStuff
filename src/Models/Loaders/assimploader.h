/******************************************************************************\
*     Copyright (C) 2016 by Alexandre Rabérin                                  *
*                                                                              *
* The program is distributed under the terms of the GNU General Public License *
*                                                                              *
\******************************************************************************/

#ifndef ASSIMPLOADER_H
#define ASSIMPLOADER_H

#include <memory>
#include <string>

#include "loader.h"

class aiScene;

/**
 * @brief The AssimpLoader class Load a 3D model using the ASSIMP library.
 */
class AssimpLoader
        : public Loader
{
private:
    std::unique_ptr<const aiScene> m_scene; ///< Scène 3D.

    std::vector< std::vector< GLfloat* > > m_vertices;              ///< Tableau des tableaux de vertices (Chaque entrée du tableau correspond aux vertices d'un mesh ASSIMP).
    std::vector< std::vector< std::vector<unsigned int> > > m_faces;///< Tableau des tableaux de faces (Chaque entrée du tableau correspond aux faces d'un mesh ASSIMP, chaque face comportant un tableau de ).

    /**
     * @brief Charge la scène dont le nom de fichier est spécifié.
     * Note : Il est nécessaire de gérer la désallocation des ressources allouées à la scène.
     * @param sceneFilename Nom du fichier contenant la scène 3D à charger.
     * @return Scène chargée, nullptr si le chargement échou.
     */
    const aiScene* loadScene(const std::string& sceneFilename);

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
    GLenum modes(int meshIndex = 0) const override;
    /**
     * @brief See Loader#vertices(int)
     */
    const std::vector< GLfloat* >& vertices(int meshIndex = 0) const override;
    /**
     * @brief See Loader#faces(int)
     */
    const std::vector< std::vector<unsigned int> >& faces(int meshIndex = 0) const override;
};

#endif // ASSIMPLOADER_H
