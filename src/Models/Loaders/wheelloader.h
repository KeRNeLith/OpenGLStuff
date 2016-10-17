/******************************************************************************\
*     Copyright (C) 2016 by Alexandre Rabérin                                  *
*                                                                              *
* The program is distributed under the terms of the GNU General Public License *
*                                                                              *
\******************************************************************************/

#ifndef WHEELLOADER_H
#define WHEELLOADER_H

#include "basicloader.h"

/**
 * @brief The WheelLoader class Gère un modèle 3D en forme de roue de voiture.
 * Par défaut : Largeur 0.5, Rayon 1, Axe de symétrie : axe Z, formée de 12 quads.
 */
class WheelLoader
        : public BasicLoader
{
private:
    const double m_width;               ///< Largeur de la roue.
    const double m_radius;              ///< Rayon de la roue.
    const unsigned int m_nbQuads;       ///< Nombre de quads voulus pour la roue.

public:
    /**
     * @brief Constructeur.
     * @param width Largeur de la roue.
     * @param radius Rayon de la roue.
     * @param nbQuads Nombre de quads pour former la roue.
     */
    WheelLoader(double width = 0.5, double radius = 1, unsigned int nbQuads = 12);
    // Interdit la copie
    WheelLoader(const WheelLoader& other) = delete;
    WheelLoader& operator= (const WheelLoader& other) = delete;

    /**
     * @brief See Loader#meshCount()
     */
    unsigned int meshCount() const override;
    /**
     * @brief See Loader#modes()
     */
    GLenum modes(int meshIndex = 0) const override;
};

#endif // WHEELLOADER_H