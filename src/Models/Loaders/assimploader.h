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

#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"
#pragma GCC diagnostic ignored "-Wfloat-equal"
#endif

#include <assimp/Importer.hpp>      // C++ importer interface

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif

class aiScene;

/**
 * @brief The AssimpLoader class Load a 3D model using the ASSIMP library.
 */
class AssimpLoader
        : public Loader
{
private:
    Assimp::Importer m_importer;    ///< Importeur de fichier (Assimp).
    const aiScene* m_scene;         ///< Scène 3D (Désallocation managée par m_importer).

    std::vector< std::vector< GLfloat* > > m_vertices;              ///< Tableau des tableaux de vertices (Chaque entrée du tableau correspond aux vertices d'un mesh ASSIMP).
    std::vector< std::vector< GLfloat* > > m_normals;               ///< Tableau des tableaux de normales (Chaque entrée du tableau correspond aux normales d'un mesh ASSIMP).
    std::vector< std::vector< std::vector<unsigned int> > > m_faces;///< Tableau des tableaux de faces (Chaque entrée du tableau correspond aux faces d'un mesh ASSIMP, chaque face comportant un tableau de ).
    std::vector< Material > m_materials;                            ///< Tableau de matériaux (Chaque entrée du tableau correspond à un matériau d'une scène ASSIMP).
    std::vector< unsigned int > m_meshMaterials;                    ///< Tableau des indices des matériaux par maillage.

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
     * @param sceneFilename Chemin vers le modèle 3D.
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
    const std::vector< GLfloat* >& vertices(int meshIndex = 0) const override;
    /**
     * @brief See Loader#normals(int)
     */
    const std::vector< GLfloat* >& normals(int meshIndex = 0) const override;
    /**
     * @brief See Loader#faces(int)
     */
    const std::vector< std::vector<unsigned int> >& faces(int meshIndex = 0) const override;
    /**
     * @brief See Loader#material(int)
     */
    const Material& material(int meshIndex = 0) const override;
};

#endif // ASSIMPLOADER_H
