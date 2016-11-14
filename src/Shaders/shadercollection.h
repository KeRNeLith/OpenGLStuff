#ifndef SHADERCOLLECTION_H
#define SHADERCOLLECTION_H

#include <map>
#include <memory>
#include <string>

#include "shaderprogram.h"

class ShaderCollection
{
private:
    static std::map< std::string, std::unique_ptr<ShaderProgram> > m_shaders;

public:
    ShaderCollection();

    static bool addOrUpdateShader(const std::string& name, const std::string& vertexShaderPath, const std::string& fragmentShaderPath);
    static std::shared_ptr<ShaderProgram> getShader(const std::string& shaderName);
};

#endif // SHADERCOLLECTION_H
