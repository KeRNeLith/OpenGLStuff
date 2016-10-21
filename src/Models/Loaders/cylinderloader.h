/******************************************************************************\
*     Copyright (C) 2016 by Alexandre Rabérin                                  *
*                                                                              *
* The program is distributed under the terms of the GNU General Public License *
*                                                                              *
\******************************************************************************/

#ifndef CYLINDERLOADER_H
#define CYLINDERLOADER_H

#include "basicloader.h"

/**
 * @brief The CylinderLoader class Gère un modèle 3D en forme de cylindre.
 * Par défaut : Hauteur 4, Rayon 2, Axe de symétrie : axe Z, formée de 50 méridiens.
 */
class CylinderLoader
        : public BasicLoader
{
private:
    const double m_height;              ///< Hauteur du cylindre.
    const double m_radius;              ///< Rayon du cylindre.
    const unsigned int m_nbMeridians;   ///< Nombre de méridiens voulus pour le cylindre.

public:
    /**
     * @brief Constructeur.
     * @param height Hauteur du cylindre.
     * @param radius Rayon du cylindre.
     * @param nbMeridians Nombre de méridiens pour former le cylindre.
     */
    CylinderLoader(double height = 4, double radius = 2, unsigned int nbMeridians = 50);
    // Interdit la copie
    CylinderLoader(const CylinderLoader& other) = delete;
    CylinderLoader& operator= (const CylinderLoader& other) = delete;

    /**
     * @brief See Loader#meshCount()
     */
    unsigned int meshCount() const override;
    /**
     * @brief See Loader#modes()
     */
    GLenum mode(int meshIndex = 0) const override;
};

#endif // CYLINDERLOADER_H
