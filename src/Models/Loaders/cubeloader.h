/******************************************************************************\
*     Copyright (C) 2016 by Alexandre Rabérin                                  *
*                                                                              *
* The program is distributed under the terms of the GNU General Public License *
*                                                                              *
\******************************************************************************/

#ifndef CUBELOADER_H
#define CUBELOADER_H

#include "basicloader.h"

/**
 * @brief The CubeLoader class Gère un modèle 3D en forme de cube.
 */
class CubeLoader
        : public BasicLoader
{
private:
    double m_width;     ///< Largeur du côté du carré.

public:
    /**
     * @brief Constructeur.
     * @param width Dimension du cube.
     */
    CubeLoader(double width = 1);
    // Interdit la copie
    CubeLoader(const CubeLoader& other) = delete;
    CubeLoader& operator= (const CubeLoader& other) = delete;

    /**
     * @brief See Loader#meshCount()
     */
    unsigned int meshCount() const override;
    /**
     * @brief See Loader#modes()
     */
    GLenum modes(int meshIndex = 0) const override;
};

#endif // CUBELOADER_H
