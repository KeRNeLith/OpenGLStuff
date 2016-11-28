#ifndef SHADERUTILS_H
#define SHADERUTILS_H

#include <glm/glm.hpp>  // Librairie Maths pour les matrices

#include "Shaders/shaderprogram.h"

/**
 * @brief The ShaderUtils class Classe utilitaire de gestion des communications entre un programme et un programme shader.
 */
class ShaderUtils
{
public:
    /**
     * @brief Met à jour la matrice de projection utilisé par le programme shader spécifié.
     * @param program Programme shader.
     * @param projection Matrice de projection.
     */
    static void sendProjectionMatrix(const ShaderProgram& program, const glm::mat4& projection);

    /**
     * @brief Met à jour la matrice de visualisation utilisé par le programme shader spécifié.
     * @param program Programme shader.
     * @param visualisation Matrice de visualisation.
     */
    static void sendVisualisationMatrix(const ShaderProgram& program, const glm::mat4& visualisation);

    /**
     * @brief Met à jour la matrice de modélisation utilisé par le programme shader spécifié.
     * @param program Programme shader.
     * @param modelisation Matrice de modélisation.
     */
    static void sendModelisationMatrix(const ShaderProgram& program, const glm::mat4& modelisation);
};

#endif // SHADERUTILS_H
