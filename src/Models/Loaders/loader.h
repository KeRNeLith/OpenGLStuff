/******************************************************************************\
*     Copyright (C) 2016 by Alexandre Rabérin                                  *
*                                                                              *
* The program is distributed under the terms of the GNU General Public License *
*                                                                              *
\******************************************************************************/

#ifndef LOADER_H
#define LOADER_H

#include <vector>

#include <GL/glut.h>

/**
 * @brief The Loader class is an abstract interface that define methods that provide access to mesh modelling data.
 */
class Loader
{
public:
    /**
     * @brief Constructeur.
     */
    Loader();

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
    virtual GLenum modes(int meshIndex = 0) const =0;

    /**
     * @brief Récupère le tableaux des sommets associés au maillage spécifié en paramètre.
     * @param meshIndex Indice du maillage désiré (Doit être strictement inférieur à meshCount(), sinon le résultat n'est pas garanti).
     * @return Tableau des sommets du maillage spécifié.
     */
    virtual const std::vector< GLfloat* >& vertices(int meshIndex = 0) const =0;

    /**
     * @brief Récupère le tableaux des faces associées au maillage spécifié en paramètre.
     * @param meshIndex Indice du maillage désiré (Doit être strictement inférieur à meshCount(), sinon le résultat n'est pas garanti).
     * @return Tableau des faces du maillage spécifié (Indices des sommets nécessaires).
     */
    virtual const std::vector< std::vector<unsigned int> >& faces(int meshIndex = 0) const =0;
};

#endif // LOADER_H
