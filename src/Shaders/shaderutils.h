#ifndef SHADERUTILS_H
#define SHADERUTILS_H

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
};

#endif // SHADERUTILS_H
