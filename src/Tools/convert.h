#ifndef CONVERT_H
#define CONVERT_H

#include <array>

#include <glm/glm.hpp>

template <typename T>
glm::vec3 toGLMVec3(const std::array<T, 3>& vec);

template <typename T>
glm::vec3 toGLMVec3(const std::array<T, 3>& vec)
{
    return glm::vec3(vec[0], vec[1], vec[2]);
}

#endif // CONVERT_H
