/******************************************************************************\
*     Copyright (C) 2016 by Alexandre Rabérin                                  *
*                                                                              *
* The program is distributed under the terms of the GNU General Public License *
*                                                                              *
\******************************************************************************/

#ifndef CONVERT_H
#define CONVERT_H

#include <cmath>

#include <array>

template <typename T>
/**
 * @brief Convertit les coordonnées sphériques en paramètres en coordonnées cartésiennes.
 * @param coords Coordonnées à convertir.
 * @return Coordonnées Sphériques.
 */
std::array<T, 3> convertFromSphericalToCartesien(const std::array<T, 3>& coords);

/**
 * @brief Convertit en radian une valeur en degrées.
 * @param x Angle en degrée.
 * @return Angle en radians.
 */
inline double toRad(const double x)
{
    return x * M_PI / double(180);
}

template <typename T>
std::array<T, 3> convertFromSphericalToCartesien(const std::array<T, 3>& coords)
{
    // Conversion en coordonnées cartésiennes
    return {{
                coords[0] * std::sin(toRad(coords[2])) * std::cos(toRad(coords[1])),
                coords[0] * std::sin(toRad(coords[2])) * std::sin(toRad(coords[1])),
                coords[0] * std::cos(toRad(coords[2]))
            }};
}

#endif // CONVERT_H
