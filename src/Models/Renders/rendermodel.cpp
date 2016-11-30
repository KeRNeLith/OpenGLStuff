/******************************************************************************\
*     Copyright (C) 2016 by Alexandre Rabérin                                  * 
*                                                                              * 
* The program is distributed under the terms of the GNU General Public License * 
*                                                                              * 
\******************************************************************************/

#include "rendermodel.h"

#include "Models/Loaders/assimploader.h"
#include "Models/Loaders/cylinderloader.h"

RenderModel::RenderModel(const std::shared_ptr<ShaderProgram>& shader, const ObjectDataStorage& data)
    : m_mode(GL_TRIANGLES)
    , m_nbElements(GLsizei(data.vertices().size()))
    , m_vertexBufferObjectID(0)
    , m_elementBufferObjectID(0)
    , m_shader(shader)
    , m_data(data)
{
    createVBOs(GL_STATIC_DRAW);
}

RenderModel::RenderModel(const std::shared_ptr<ShaderProgram>& shader, const Loader& loader, unsigned int meshIndex)
    : RenderModel(shader, ObjectDataStorage(loader, meshIndex))
{
    m_mode = loader.mode(meshIndex);
}

RenderModel::~RenderModel()
{
    glDeleteBuffers(1, &m_vertexBufferObjectID);
    glDeleteBuffers(1, &m_elementBufferObjectID);
}

void RenderModel::createVBOs(GLenum usage)
{
    ///////////////////////////////////////////////////////
    /// Envoi des sommets vers des buffers en mémoire vidéo
    ///////////////////////////////////////////////////////

    /// Allocations des buffers
    // Création d'un ID de buffer (VBO)
    glGenBuffers(1, &m_vertexBufferObjectID);

    // Sélectionne le buffer
    glBindBuffer(GL_ARRAY_BUFFER, m_vertexBufferObjectID);

    // Alloue le buffer des données (sommets, etc.)
    glBufferData(GL_ARRAY_BUFFER,
                 sizeof(GLfloat) * m_data.vertices().size() /* Taille total du buffer en octets (toutes données confonfues */,
                 nullptr,
                 usage);

    /// Transfert des données
    // Transfert les sommets de la RAM vers le buffer vidéo
    glBufferSubData(GL_ARRAY_BUFFER,
                    0 /* Offset des données dans le buffer */,
                    sizeof(GLfloat) * m_data.vertices().size() /* Taille des données en octet */,
                    m_data.vertices().data());

    /// Correspondance des données
    // Spécifie l'emplacement des données des sommets
    glVertexAttribPointer(0 /* Numéro sous buffer */,
                          3 /* 3 sommets par faces */,
                          GL_FLOAT,
                          GL_FALSE,
                          0,
                          nullptr /* Pas d'offset */);

    /////////////////////////////////////////////////////////////////////////////////////////
    /// Envoi des indices des sommet définissants les faces vers des buffers en mémoire vidéo
    /////////////////////////////////////////////////////////////////////////////////////////

    // Création d'un ID de buffer
    glGenBuffers(1, &m_elementBufferObjectID);

    // Sélection le buffer
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_elementBufferObjectID);

    // Alloue et initialise le buffer avec les données des indices des sommets par face
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,
                 sizeof(GLuint) * m_data.faces().size() /* Taille en octets des indices de sommets des faces */,
                 m_data.faces().data(),
                 usage);
}

void RenderModel::enableVBOs() const
{
    // Activation du tableau des sommets
    glEnableVertexAttribArray(0);

    // On indique de quel buffer proviennent les sommets
    glBindBuffer(GL_ARRAY_BUFFER, m_vertexBufferObjectID);
    // On indique de quel buffer proviennent les indices des sommets
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_elementBufferObjectID);

    // Spécifie l'emplacement des données des sommets et leur format
    glVertexAttribPointer(0 /* Buffer objet utilisé */,
                          3 /* 3 sommets par face */,
                          GL_FLOAT,
                          GL_FALSE,
                          0,
                          nullptr /* Pas d'offset */);
}

void RenderModel::drawObject() const
{
    // Not Handled for the moment
    /*if (m_object->hasTexture())
    {
        glEnable(GL_TEXTURE_2D);
        m_object->selectTexture();
    }*/

    // Active les VBO pour l'affichage
    enableVBOs();

    // Dessin
    glDrawElements(m_mode,
                   m_nbElements,
                   GL_UNSIGNED_INT,
                   nullptr);

    //glDisable(GL_TEXTURE_2D);
}

void RenderModel::init()
{
    glEnable(GL_DEPTH_TEST);

    // Réglage de la couleur de fond
    glClearColor(0.0, 0.0, 0.0, 1.0);
}

void RenderModel::resetView()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
