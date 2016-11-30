/******************************************************************************\
*     Copyright (C) 2016 by Alexandre Rabérin                                  * 
*                                                                              * 
* The program is distributed under the terms of the GNU General Public License * 
*                                                                              * 
\******************************************************************************/

#ifndef RenderModel_H
#define RenderModel_H

#include <memory>
#include <vector>

#include "Models/Loaders/objectdatastorage.h"

#include "Shaders/shaderprogram.h"

class Loader;

/**
 * @brief The Model class Stocke les données nécessaires à la réalisation d'un rendu d'un modèle 3D en fournissant un shader et ses données (maillage, texture, etc.).
 */
class RenderModel
{
private:
    GLenum m_mode;                              ///< Mode de dessin OpenGL.
    GLsizei m_nbElements;                       ///< Nombre d'éléments à dessiner.

    GLuint m_vertexBufferObjectID;              ///< Vertex buffer object Id.
    GLuint m_elementBufferObjectID;             ///< Element buffer object Id.

    std::shared_ptr<ShaderProgram> m_shader;    ///< Shader à utiliser.

    ObjectDataStorage m_data;                   ///< Données de l'objet.

    /**
     * @brief Alloue et initialise le VBO destiné à la mémoire vidéo à partir des données de l'objet.
     * @param usage Pattern d'utilisation des données envoyées.
     */
    void createVBOs(GLenum usage);

    /**
     * @brief Rend actif le VBO lié au mesh.
     */
    void enableVBOs() const;

public:
    /**
     * @brief Constructeur à partir d'un loader.
     * @param shader Shader associé au modèle à rendre.
     * @param data Données de l'objet.
     */
    RenderModel(const std::shared_ptr<ShaderProgram>& shader, const ObjectDataStorage& data);

    /**
     * @brief Constructeur à partir d'un loader.
     * @param shader Shader associé au modèle à rendre.
     * @param loader Objet servant de base au rendu.
     * @param meshIndex Indice du mesh à récupérer depuis le loader.
     */
    RenderModel(const std::shared_ptr<ShaderProgram>& shader, const Loader& loader, unsigned int meshIndex = 0);

    /**
     * @brief Destructeur.
     */
    ~RenderModel();

    /**
     * @brief Envoi les données de dessin au GPU.
     */
    void drawObject() const;

    /**
     * @brief Initialiser les paramètres globaux du rendu de la scène.
     */
    static void init();

    /**
     * @brief Réinitialise la vue (efface l'écran).
     */
    static void resetView();

    /**
     * @brief Récupère le shader associé au modèle.
     * @return Programme shader.
     */
    const std::shared_ptr<ShaderProgram>& getShader() const
    {
        return m_shader;
    }
};

#endif	// RenderModel_H

