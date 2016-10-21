/******************************************************************************\
*     Copyright (C) 2016 by Alexandre Rabérin                                  *
*                                                                              *
* The program is distributed under the terms of the GNU General Public License *
*                                                                              *
\******************************************************************************/

#include "shaderutils.h"

#include <iostream>
#include <fstream>

#include <GLES3/gl3.h>

#define printOpenGLError() printOpenglError(__FILE__, __LINE__)

int ShaderUtils::printOpenglError(const std::string& file, int line)
{
    // Retourne 1 s'il y a eu une erreur OpenGL, sinon 0
    GLenum glErr;
    int retCode = 0;

    glErr = glGetError();
    while (glErr != GL_NO_ERROR)
    {
        std::cerr << "Erreur OpenGL dans le fichier " << file << " à la ligne " << line << std::endl << "Erreur : " << gluErrorString(glErr);
        retCode = 1;
        glErr = glGetError();
    }

    return retCode;
}

void ShaderUtils::printShaderInfoLog(GLuint shader)
{
    int infoLogLen = 0;
    int charsWritten = 0;
    GLchar* infoLog;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &infoLogLen);

    printOpenGLError();

    if (infoLogLen != GL_TRUE)
    {
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLogLen);

        infoLog = (GLchar*) malloc (infoLogLen + 1);
        if (infoLog == NULL)
        {
            std::cerr << "ERREUR: Impossible d'allouer le buffer de log d'erreur" << std::endl;
            return;
        }

        glGetShaderInfoLog(shader, infoLogLen, &charsWritten, infoLog);
        std::cerr << "InfoLog Shader: " << infoLog << std::endl;
        free(infoLog);

        glDeleteShader(shader);
    }

    printOpenGLError();
}

void ShaderUtils::printProgramInfoLog(GLuint program)
{
    int infoLogLen = 0;
    int charsWritten = 0;
    GLchar* infoLog;
    glGetProgramiv(program, GL_LINK_STATUS, &infoLogLen);

    printOpenGLError();

    if (infoLogLen != GL_TRUE)
    {
        glGetProgramiv(program, GL_INFO_LOG_LENGTH, &infoLogLen);
        infoLog = (GLchar*) malloc (infoLogLen + 1);
        if (infoLog == NULL)
        {
            std::cerr << "ERREUR: Impossible d'allouer le buffer de log d'erreur" << std::endl;
            return;
        }

        glGetProgramInfoLog(program, infoLogLen, &charsWritten, infoLog);
        std::cerr << "InfoLog Program: " << infoLog << std::endl;
        free(infoLog);

        glDeleteProgram(program);
    }

    printOpenGLError();
}

std::string ShaderUtils::loadShaderSource(const std::string& filename)
{
    std::string content;

    std::ifstream ifs(filename, std::ios::in);

    if (ifs.is_open())
    {
        content = std::string(  (std::istreambuf_iterator<char>(ifs)),
                                (std::istreambuf_iterator<char>()));
    }
    else
    {
        std::cerr << "Impossible d'ouvrir le fichier shader : " << filename << std::endl;
    }

    ifs.close();

    return content;
}

void ShaderUtils::createShadersProgram( GLuint& progID, GLuint& vertexID, GLuint& fragID,
                                        const std::string& vertexSourceFile,
                                        const std::string& fragmentSourceFile)
{
    // Génère les Ids des shaders
    vertexID = glCreateShader(GL_VERTEX_SHADER);
    fragID = glCreateShader(GL_FRAGMENT_SHADER);

    // Charge les codes sources des shaders
    std::string vertexSource = ShaderUtils::loadShaderSource(vertexSourceFile);
    std::string fragmentSource = ShaderUtils::loadShaderSource(fragmentSourceFile);

    // Définit les codes sources des shaders
    const char* vertexStr = vertexSource.data();
    glShaderSource(vertexID, 1, &vertexStr, nullptr);

    const char* fragmentStr = fragmentSource.data();
    glShaderSource(fragID, 1, &fragmentStr, nullptr);

    // Compilation du vertex shader
    glCompileShader(vertexID);

    // Vérification de la compilation du vertex shader
    printShaderInfoLog(vertexID);

    // Compilation du fragment shader
    glCompileShader(fragID);

    // Vérification de la compilation du fragment shader
    printShaderInfoLog(fragID);

    // Création du programme OpenGL avec ses shaders
    progID = glCreateProgram();

    // Définit les shaders associés au programme
    glAttachShader(progID, vertexID);
    glAttachShader(progID, fragID);

    // Termine la compilation du programme
    glLinkProgram(progID);

    // Vérification de l'état du programme OpenGL
    printProgramInfoLog(progID);
}

void ShaderUtils::useShaderProgram(GLuint progId)
{
    glUseProgram(progId);
}

void ShaderUtils::removeShaderProgram(GLuint progId)
{
    glDeleteProgram(progId);
}
