/******************************************************************************\
*     Copyright (C) 2016 by Adrien Pierreval                                   *
*                                                                              *
* The program is distributed under the terms of the GNU General Public License *
*                                                                              *
\******************************************************************************/

#ifndef BASICLOADER_H
#define BASICLOADER_H

#include "loader.h"

/**
 * @brief The BasicLoader class Gère l'implémentation des structures de données basiques utilisé pour le wrapper sur des modèles définis manuellement.
 */
class BasicLoader
        : public Loader
{
protected:
    std::vector< GLfloat* > m_vertices;                 ///< Sommets définissant le modèle.
    std::vector< std::vector<unsigned int> > m_faces;   ///< Faces du modèle.

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
    const std::vector< GLfloat* >& vertices(int meshIndex = 0) const override;
    /**
     * @brief See Loader#faces(int)
     */
    const std::vector< std::vector<unsigned int> >& faces(int meshIndex = 0) const override;
};

#endif // BASICLOADER_H
