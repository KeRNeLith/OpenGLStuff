#include "objectdatastorage.h"

ObjectDataStorage::ObjectDataStorage(const std::vector<GLfloat>& v,
                                     const std::vector< GLfloat >& n,
                                     const std::vector<unsigned int>& f,
                                     const std::vector<GLfloat>& tc)
    : m_vertices(v)
    , m_normals(n)
    , m_faces(f)
    , m_texCoords(tc)
{

}

ObjectDataStorage::ObjectDataStorage(const Loader& loader, unsigned int index)
    : ObjectDataStorage(loader.vertices(index), loader.normals(index), loader.faces(index), loader.texCoords(index))
{

}
