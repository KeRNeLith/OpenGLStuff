#include "wheelloader.h"

WheelLoader::WheelLoader()
    : Loader()
{
    // TODO
}

WheelLoader::~WheelLoader()
{
}


unsigned int WheelLoader::meshCount() const
{
    return 1;
}

GLenum WheelLoader::modes(int /*meshIndex*/) const
{
    return GL_QUADS;
}

const std::vector< GLfloat* >& WheelLoader::vertices(int /*meshIndex*/) const
{
    return std::move(std::vector< GLfloat* >());    // TEMPORARY => just for compilation
}

const std::vector< std::vector<unsigned int> >& WheelLoader::faces(int /*meshIndex*/) const
{
    return std::move(std::vector< std::vector<unsigned int> >()); // TEMPORARY => just for compilation
}
