#ifndef SHADERUTILS_H
#define SHADERUTILS_H

#include <glm/glm.hpp>  // Librairie Maths pour les matrices
#include <glm/gtc/type_ptr.hpp> // Accès bas niveau au données

#include "Shaders/shaderprogram.h"

#include "Tools/singleton.h"

/**
 * @brief The ShaderUtils class Classe utilitaire de gestion des communications entre un programme et un programme shader.
 */
class ShaderUtils
        : public Singleton<ShaderUtils>
{
    friend class Singleton<ShaderUtils>;

private:
    std::shared_ptr<ShaderProgram> m_shader;        ///< Shader actif, nullptr si aucun shader n'est actif.

    /**
     * @brief Constructeur.
     */
    ShaderUtils();

    /**
     * @brief Destructeur.
     */
    ~ShaderUtils();

public:
    /**
     * @brief Définit le programme shader qui va être actif.
     * A utiliser pour changer le programme shader sur lequel seront envoyées les informations.
     * @param shaderProg Programme shader.
     */
    void setActiveShaderProgram(const std::shared_ptr<ShaderProgram>& shaderProg);

    /**
     * @brief Cette fonction se charge de communiquer aux shader la tranformation à appliquer aux objets.
     * Pour cela elle s'appui sur une matrice de projection, une matrice de visualisation et enfin une matrice de modélisation.
     * Elle réalise l'opération suivante :
     * tranformationFinale = projection * visualisation * modélisation
     * @param projection Matrice de projection.
     * @param visualisation Matrice de visualisation.
     * @param modelisation Matrice de modélisation.
     */
    void sendTransformMatrix(const glm::mat4& projection, const glm::mat4& visualisation, const glm::mat4& modelisation);
};

#endif // SHADERUTILS_H
