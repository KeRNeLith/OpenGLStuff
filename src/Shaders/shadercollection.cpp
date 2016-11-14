#include "shadercollection.h"

// Static init
std::map< std::string, std::shared_ptr<ShaderProgram> > ShaderCollection::m_shaders;

bool ShaderCollection::addOrUpdateShader(const std::string& name, const std::string& vertexShaderPath, const std::string& fragmentShaderPath)
{
    bool ret = false;

    auto itF = m_shaders.find(name);
    if (itF != m_shaders.cend())
    {
        ret = true;
    }

    m_shaders[name] = std::shared_ptr<ShaderProgram>(new ShaderProgram(vertexShaderPath, fragmentShaderPath));

    return ret;
}

std::shared_ptr<ShaderProgram> ShaderCollection::getShader(const std::string& shaderName)
{
    std::shared_ptr<ShaderProgram> program = nullptr;

    auto itF = m_shaders.find(shaderName);
    if (itF != m_shaders.cend())
    {
        program = itF->second;
    }

    return program;
}
