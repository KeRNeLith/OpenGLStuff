#ifndef CONVERT_H
#define CONVERT_H

#include <cmath>

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

#endif // CONVERT_H
