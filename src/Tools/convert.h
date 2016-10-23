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

#include <glm/glm.hpp>

/// Déclarations
/**
 * @brief Convertit en radian une valeur en degrées.
 * @param x Angle en degrée.
 * @return Angle en radians.
 */
template <typename T>
inline double toRad(const T& x)
{
    return x * M_PI / double(180);
}

template <typename T>
/**
 * @brief Convertit une std::array de 3 éléments en un vec3 de la bibliothèque GLM.
 * @param vec Tableau à convertir.
 * @return Tableau convertit en vec3.
 */
glm::vec3 toGLMVec3(const std::array<T, 3>& vec);

/// Définitions
template <typename T>
glm::vec3 toGLMVec3(const std::array<T, 3>& vec)
{
    return glm::vec3(vec[0], vec[1], vec[2]);
}

#endif // CONVERT_H
