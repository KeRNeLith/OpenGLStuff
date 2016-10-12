#include "cubeloader.h"

CubeLoader::CubeLoader(double width)
    : BasicLoader()
    , m_width(width)
{
    // Création des vertices
    GLfloat* vertex1 = new GLfloat[3] {  -GLfloat(m_width/double(2)), GLfloat(m_width/double(2)), -GLfloat(m_width/double(2)) };
    m_vertices.push_back(vertex1);

    GLfloat* vertex2 = new GLfloat[3] {  GLfloat(m_width/double(2)), GLfloat(m_width/double(2)), -GLfloat(m_width/double(2)) };
    m_vertices.push_back(vertex2);

    GLfloat* vertex3 = new GLfloat[3] {  GLfloat(m_width/double(2)), GLfloat(m_width/double(2)), GLfloat(m_width/double(2)) };
    m_vertices.push_back(vertex3);

    GLfloat* vertex4 = new GLfloat[3] {  -GLfloat(m_width/double(2)), GLfloat(m_width/double(2)), GLfloat(m_width/double(2)) };
    m_vertices.push_back(vertex4);

    GLfloat* vertex5 = new GLfloat[3] {  -GLfloat(m_width/double(2)), -GLfloat(m_width/double(2)), -GLfloat(m_width/double(2)) };
    m_vertices.push_back(vertex5);

    GLfloat* vertex6 = new GLfloat[3] {  GLfloat(m_width/double(2)), -GLfloat(m_width/double(2)), -GLfloat(m_width/double(2)) };
    m_vertices.push_back(vertex6);

    GLfloat* vertex7 = new GLfloat[3] {  GLfloat(m_width/double(2)), -GLfloat(m_width/double(2)), GLfloat(m_width/double(2)) };
    m_vertices.push_back(vertex7);

    GLfloat* vertex8 = new GLfloat[3] {  -GLfloat(m_width/double(2)), -GLfloat(m_width/double(2)), GLfloat(m_width/double(2)) };
    m_vertices.push_back(vertex8);

    // Création des faces
    m_faces = {
                { 0, 1, 2, 3 },
                { 2, 1, 5, 6 },
                { 3, 2, 6, 7 },
                { 4, 5, 6, 7 },
                { 0, 3, 7, 4 },
                { 1, 0, 4, 5 },
              };
}

unsigned int CubeLoader::meshCount() const
{
    return 1;
}

GLenum CubeLoader::modes(int /*meshIndex*/) const
{
    return GL_QUADS;
}
