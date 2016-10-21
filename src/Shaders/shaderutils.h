/******************************************************************************\
*     Copyright (C) 2016 by Alexandre Rabérin                                  *
*                                                                              *
* The program is distributed under the terms of the GNU General Public License *
*                                                                              *
\******************************************************************************/

#ifndef SHADERUTILS_H
#define SHADERUTILS_H

#include <string>

#include <GL/glut.h>

/**
 * @brief The ShaderUtils class Gère des fonctionnalités basiques d'interactions avec les shaders.
 * Lecture des fichiers shader, compilation des programmes shaders, etc.
 */
class ShaderUtils
{
private:
    /**
     * @brief Affiche l'emplacement d'où provient l'erreur OpenGL qui est survenue.
     * @param file Fichier qui contient le code d'où a été générée l'erreur.
     * @param line Ligne ayant provoqué l'erreur.
     * @return 1 s'il y a eu une erreur, sinon 0.
     */
    static int printOpenglError(const std::string& file, int line);

    /**
     * @brief Affiche les erreurs liées au shader correspondant à l'id passé en paramètre.
     * @param shader Id du shader.
     */
    static void printShaderInfoLog(GLuint shader);

    /**
     * @brief Affiche les erreurs liées au programme OpenGL correspondant à l'id passé en paramètre.
     * @param program Id du programme OpenGL.
     */
    static void printProgramInfoLog(GLuint program);

    /**
     * @brief Charge un fichier shader et retourne son contenu.
     * @param filename Chemin vers le fichier shader.
     * @return Contenu du fichier shader.
     */
    static std::string loadShaderSource(const std::string& filename);

public:
    /**
     * @brief Charge et crée un programme OpenGL (vertex shader et fragment shader).
     * @param progID ID du programme.
     * @param vertexID ID du vertex shader.
     * @param fragID ID du fragment shader.
     * @param vertexSourceFile Nom du fichier contenant les sources du vertex shader.
     * @param fragmentSourceFile Nom du fichier contenant les sources du fragment shader.
     */
    static void createShadersProgram(GLuint& progID, GLuint& vertexID, GLuint& fragID,
                                     const std::string& vertexSourceFile,
                                     const std::string& fragmentSourceFile);

    /**
     * @brief Définit le programme OpenGL à utiliser.
     * Note : Au préalable il faut récupérer un id de programme OpenGL via createShadersProgram.
     * @param progId Id du programme OpenGL.
     */
    static void useShaderProgram(GLuint progId);

    /**
     * @brief Supprime le programme OpenGL spécifié.
     * @param progId Id du programme OpenGL.
     */
    static void removeShaderProgram(GLuint progId);
};

#endif // SHADERUTILS_H
