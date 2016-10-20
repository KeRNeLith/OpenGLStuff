#ifndef GENERAL_H
#define GENERAL_H

#include <algorithm>

template <typename T>
/**
 * @brief clip Fait en sorte de maintenir la valeur n dans l'intervalle [lower, upper].
 * @param n Valeur à traiter.
 * @param lower Borne inférieure.
 * @param upper Borne supérieure.
 * @return Valeur placée dans l'intervalle.
 */
T clip(const T& n, const T& lower, const T& upper)
{
    return std::max(lower, std::min(n, upper));
}

#endif // GENERAL_H
