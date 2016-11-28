/******************************************************************************\
*     Copyright (C) 2016 by Alexandre Rabérin                                  *
*                                                                              *
* The program is distributed under the terms of the GNU General Public License *
*                                                                              *
\******************************************************************************/

#ifndef SHADERPROGRAM_H
#define SHADERPROGRAM_H

#include <memory>
#include <string>

#include <GLES3/gl3.h>

#include "Camera/camera.h"

/**
 * @brief The ShaderProgram class Gère la création et l'utilisation d'un programme OpenGL (Shader).
 */
class ShaderProgram
{
private:
    GLuint m_programId; ///< Id du programme shader.

    static std::shared_ptr<Camera> m_camera;    ///< Caméra en cours d'utilisation (gérant la visualisation et la projection).

    /**
     * @brief Charge un fichier shader et retourne son contenu.
     * @param filename Chemin vers le fichier shader.
     * @return Contenu du fichier shader.
     */
    std::string loadShaderSource(const std::string& filename);

    /**
     * @brief Affiche l'emplacement d'où provient l'erreur OpenGL qui est survenue.
     * @param file Fichier qui contient le code d'où a été générée l'erreur.
     * @param line Ligne ayant provoqué l'erreur.
     */
    void printOpenGLError(const std::string& file, int line);

    /**
     * @brief Vérifie l'état de compilation du shader spécifié.
     * @param shaderId Id du shader.
     * @return GL_TRUE si la compilation a réussi, sinon GL_FALSE.
     */
    GLint checkShaderState(GLint shaderId);

    /**
     * @brief Vérifie l'état du programme.
     * @return GL_TRUE si la compilation a réussi, sinon GL_FALSE.
     */
    GLint checkProgramState();

public:
    /**
     * @brief Constructeur.
     * Crée et initialise un programme OpenGL.
     * @param vertexShader Chemin vers le vertex shader.
     * @param fragmentShader Chemin vers le fragment shader.
     */
    ShaderProgram(const std::string& vertexShader, const std::string& fragmentShader);

    // Interdit la copie
    ShaderProgram(const ShaderProgram& other) = delete;
    ShaderProgram& operator=(const ShaderProgram& other) = delete;

    /**
     * @brief Destructeur.
     */
    ~ShaderProgram();

    /**
     * @brief Rend le programme courant actif.
     */
    void useProgram();

    // Accesseur / Setters
    /**
     * @brief Récupère l'id du programme OpenGL (Shader).
     * @return Id du programme.
     */
    GLuint getProgramId() const
    {
        return m_programId;
    }

    /**
     * @brief Met à jour la caméra utilisé par les shaders.
     * @param camera Nouvelle caméra.
     */
    static void setCamera(const std::shared_ptr<Camera>& camera)
    {
        m_camera = camera;
    }
};

#endif // SHADERPROGRAM_H
