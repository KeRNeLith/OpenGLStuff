#ifndef SHADERCOLLECTION_H
#define SHADERCOLLECTION_H

#include <map>
#include <memory>
#include <string>

#include "shaderprogram.h"

/**
 * @brief The ShaderCollection class Stocke une collection de shader nommés.
 */
class ShaderCollection
{
private:
    static std::map< std::string, std::shared_ptr<ShaderProgram> > m_shaders;   ///< Associe un programme OpenGL à un nom.

public:
    ShaderCollection() = default;

    /**
     * @brief Ajoute ou met à jour un programme OpenGL correspondant au nom passé en paramètre.
     * @param name Nom attribué au programme.
     * @param vertexShaderPath Chemin vers le fichier source du vertex shader.
     * @param fragmentShaderPath Chemin vers le fichier source du fragment shader.
     * @return True si le nom de shader était déjà utilisé.
     */
    static bool addOrUpdateShader(const std::string& name, const std::string& vertexShaderPath, const std::string& fragmentShaderPath);

    /**
     * @brief Récupère un pointeur sur le shader correspondant au nom shaderName.
     * @param shaderName Nom du shader.
     * @return Programme OpenGL.
     */
    static std::shared_ptr<ShaderProgram> getShader(const std::string& shaderName);
};

#endif // SHADERCOLLECTION_H
