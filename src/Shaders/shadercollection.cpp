#include "shadercollection.h"

std::map< std::string, std::unique_ptr<ShaderProgram> > ShaderCollection::m_shaders;

ShaderCollection::ShaderCollection()
{

}

bool ShaderCollection::addOrUpdateShader(const std::string& name, const std::string& vertexShaderPath, const std::string& fragmentShaderPath)
{
    bool ret = false;

    auto itF = m_shaders.find(name);
    if (itF != m_shaders.cend())
    {
        ret = true;
    }

    m_shaders[name] = std::unique_ptr<ShaderProgram>(new ShaderProgram(vertexShaderPath, fragmentShaderPath));

    return ret;
}

std::shared_ptr<ShaderProgram> ShaderCollection::getShader(const std::string& shaderName)
{
    std::shared_ptr<ShaderProgram> program = nullptr;

    auto itF = m_shaders.find(shaderName);
    if (itF != m_shaders.cend())
    {
        program = std::move(itF->second);
    }

    return program;
}
