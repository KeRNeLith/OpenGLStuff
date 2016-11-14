/******************************************************************************\
*     Copyright (C) 2016 by Alexandre Rabérin                                  *
*                                                                              *
* The program is distributed under the terms of the GNU General Public License *
*                                                                              *
\******************************************************************************/

#ifndef LOADER_H
#define LOADER_H

#include <memory>
#include <vector>

#include <GL/glut.h>

#include "Graph/node.h"

#include "Models/Textures/texturemanager.h"

/**
 * @brief The Loader class is an abstract interface that define methods that provide access to mesh modelling data.
 */
class Loader
{
private:
    std::shared_ptr<TextureManager> m_texture;  ///< Texture de l'objet

public:
    /**
     * @brief Constructeur.
     * @param texture Texture associé au modèle.
     */
    Loader(TextureManager* texture = nullptr);

    /**
     * @brief Destructeur.
     */
    virtual ~Loader();

    /**
     * @brief Récupère le nombre d'objets 3D disponible.
     * @return Nombre de maillage disponible.
     */
    virtual unsigned int meshCount() const =0;

    /**
     * @brief Récupère le mode de dessin à utiliser pour le dessin OpenGL.
     * @param meshIndex Indice du maillage désiré (Doit être strictement inférieur à meshCount(), sinon le résultat n'est pas garanti).
     * @return Mode de dessin (Une parmi : GL_POINTS, GL_LINES, GL_TRIANGLES, GL_QUADS et GL_POLYGON).
     */
    virtual GLenum mode(int meshIndex = 0) const =0;

    /**
     * @brief Récupère le tableaux des sommets associés au maillage spécifié en paramètre (sommets donnés de manière contigu).
     * @param meshIndex Indice du maillage désiré (Doit être strictement inférieur à meshCount(), sinon le résultat n'est pas garanti).
     * @return Tableau des sommets du maillage spécifié.
     */
    virtual const std::vector< GLfloat >& vertices(int meshIndex = 0) const =0;

    /**
     * @brief Récupère le tableaux des faces associées au maillage spécifié en paramètre (indices donnés de manière contigu).
     * @param meshIndex Indice du maillage désiré (Doit être strictement inférieur à meshCount(), sinon le résultat n'est pas garanti).
     * @return Tableau des faces du maillage spécifié (Indices des sommets nécessaires).
     */
    virtual const std::vector< unsigned int >& faces(int meshIndex = 0) const =0;

    /**
     * @brief Récupère le tableaux des coordonnées de texture associées au maillage spécifié en paramètre (coordonnées données de manière contigu).
     * @param meshIndex Indice du maillage désiré (Doit être strictement inférieur à meshCount(), sinon le résultat n'est pas garanti).
     * @return Tableau des coordonnées de texture du maillage spécifié.
     */
    virtual const std::vector< GLfloat >& texCoords(int meshIndex = 0) const =0;

    /**
     * @brief Crée une graph contenant les objets loadés par le loader.
     * @return Graph.
     */
    virtual std::shared_ptr<Node> getGraph() const =0;

    /**
     * @brief Sélectionne la texture.
     * Note : Il est nécessaire de vérifier auparavant que l'objet possède une texture via la méthode hasTexture().
     */
    void selectTexture() const;

    /**
     * @brief Test si l'objet chargé possède une texture.
     * @return True si l'objet possède une texture.
     */
    bool hasTexture() const
    {
        return m_texture != nullptr;
    }

    /**
     * @brief Affecte ou met à jour la texture de l'objet.
     * @param texture Nouvelle texture.
     */
    void setTexture(const std::shared_ptr<TextureManager>& texture)
    {
        m_texture = texture;
    }
};

#endif // LOADER_H
