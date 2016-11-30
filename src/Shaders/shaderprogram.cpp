/******************************************************************************\
*     Copyright (C) 2016 by Alexandre Rabérin                                  *
*                                                                              *
* The program is distributed under the terms of the GNU General Public License *
*                                                                              *
\******************************************************************************/

#include "shaderprogram.h"

#include <assert.h>
#include <iostream>
#include <fstream>
#include <vector>

#include <GL/glut.h>

#include "shaderutils.h"

// Static init
std::shared_ptr<Camera> ShaderProgram::m_camera = nullptr;

#define getOpenGLError() printOpenGLError(__FILE__, __LINE__)

ShaderProgram::ShaderProgram(const std::string& vertexShader, const std::string& fragmentShader)
    : m_programId(0)
{
    // Génère les Ids des shaders
    GLuint vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
    getOpenGLError();
    GLuint fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
    getOpenGLError();

    // Charge les codes sources des shaders
    std::string vertexSource = loadShaderSource(vertexShader);
    std::string fragmentSource = loadShaderSource(fragmentShader);

    // Définit les codes sources des shaders
    const char* vertexStr = vertexSource.data();
    glShaderSource(vertexShaderID, 1, &vertexStr, nullptr);
    getOpenGLError();

    const char* fragmentStr = fragmentSource.data();
    glShaderSource(fragmentShaderID, 1, &fragmentStr, nullptr);
    getOpenGLError();

    // Compilation du vertex shader
    glCompileShader(vertexShaderID);
    getOpenGLError();

    // Vérification de la compilation du vertex shader
    checkShaderState(vertexShaderID);

    // Compilation du fragment shader
    glCompileShader(fragmentShaderID);
    getOpenGLError();

    // Vérification de la compilation du fragment shader
    checkShaderState(fragmentShaderID);

    // Création du programme OpenGL avec ses shaders
    m_programId = glCreateProgram();
    getOpenGLError();

    // Définit les shaders associés au programme
    glAttachShader(m_programId, vertexShaderID);
    getOpenGLError();

    glAttachShader(m_programId, fragmentShaderID);
    getOpenGLError();

    // Termine la compilation du programme
    glLinkProgram(m_programId);
    getOpenGLError();

    // Vérification de l'état du programme OpenGL
    checkProgramState();

    // Détachement des shaders
    glDetachShader(m_programId, vertexShaderID);
    getOpenGLError();

    glDetachShader(m_programId, fragmentShaderID);
    getOpenGLError();

    // et suppression des shaders
    glDeleteShader(vertexShaderID);
    getOpenGLError();

    glDeleteShader(fragmentShaderID);
    getOpenGLError();
}

ShaderProgram::~ShaderProgram()
{
    glDeleteProgram(m_programId);
}

std::string ShaderProgram::loadShaderSource(const std::string& filename)
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

void ShaderProgram::printOpenGLError(const std::string& file, int line)
{
    GLenum glErr = glGetError();
    if (glErr != GL_NO_ERROR)
    {
        std::cerr << "Erreur OpenGL dans le fichier " << file << " à la ligne " << line << std::endl << "Erreur : " << gluErrorString(glErr);
        assert(false);
    }
}

GLint ShaderProgram::checkShaderState(GLint shaderId)
{
    GLint status = GL_FALSE;
    glGetShaderiv(shaderId, GL_COMPILE_STATUS, &status);
    getOpenGLError();

    if (status != GL_TRUE)
    {
        int infoLogLength = 0;
        glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &infoLogLength);

        if (infoLogLength > 0)
        {
            std::vector<char> shaderErrorMessage(infoLogLength + 1);
            glGetShaderInfoLog(shaderId, infoLogLength, NULL, &shaderErrorMessage[0]);
            std::cerr << &shaderErrorMessage[0] << std::endl;
        }

        getOpenGLError();
    }

    return status;
}

GLint ShaderProgram::checkProgramState()
{
    GLint status = GL_FALSE;
    glGetProgramiv(m_programId, GL_LINK_STATUS, &status);
    getOpenGLError();

    if (status != GL_TRUE)
    {
        int infoLogLength = 0;
        glGetProgramiv(m_programId, GL_INFO_LOG_LENGTH, &infoLogLength);

        if (infoLogLength > 0)
        {
            std::vector<char> programErrorMessage(infoLogLength + 1);
            glGetProgramInfoLog(m_programId, infoLogLength, NULL, &programErrorMessage[0]);
            std::cerr << &programErrorMessage[0] << std::endl;
        }

        getOpenGLError();
    }

    return status;
}

void ShaderProgram::useProgram() const
{
    glUseProgram(m_programId);

    // Envoi les matrices de projection et visualisation
    if (m_camera)
    {
        ShaderUtils::sendProjectionMatrix(*this, m_camera->getProjection());
        ShaderUtils::sendVisualisationMatrix(*this, m_camera->getVisualisation());
    }
    // Cas où aucune caméra n'est utilisé => ne devrait jamais arrivé
    else
    {
        ShaderUtils::sendProjectionMatrix(*this, glm::mat4(1.0));
        ShaderUtils::sendVisualisationMatrix(*this, glm::mat4(1.0));
    }
}
