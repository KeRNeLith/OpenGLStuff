/******************************************************************************\
*     Copyright (C) 2016 by Alexandre Rabérin                                  * 
*                                                                              * 
* The program is distributed under the terms of the GNU General Public License * 
*                                                                              * 
\******************************************************************************/

#include "rendermodel.h"

#include "Models/Loaders/assimploader.h"
#include "Models/Loaders/cylinderloader.h"

RenderModel::RenderModel(RenderModel::ModelType type, const std::shared_ptr<TextureManager>& texture)
    // Read the given file with some example postprocessing
    : m_object(loadObject(type))
    , m_vertexBufferObjectIDs(m_object->meshCount())
    , m_elementBufferObjectIDs(m_object->meshCount())
{
    if (texture)
    {
        m_object->setTexture(texture);
    }

    const unsigned int nbMesh = m_object->meshCount();
    for (unsigned int i = 0 ; i < nbMesh ; ++i)
    {
        createVBOs(GL_STATIC_DRAW, i);
    }
}

RenderModel::RenderModel(const std::string& filename)
    : m_object(new AssimpLoader(filename))
    , m_vertexBufferObjectIDs(m_object->meshCount())
    , m_elementBufferObjectIDs(m_object->meshCount())
{
    const unsigned int nbMesh = m_object->meshCount();
    for (unsigned int i = 0 ; i < nbMesh ; ++i)
    {
        createVBOs(GL_STATIC_DRAW, i);
    }
}

RenderModel::~RenderModel()
{
    glDeleteBuffers(m_object->meshCount(), m_vertexBufferObjectIDs.data());
    glDeleteBuffers(m_object->meshCount(), m_elementBufferObjectIDs.data());
}

Loader* RenderModel::loadObject(RenderModel::ModelType type)
{
    switch (type)
    {
    case RenderModel::CYLINDER:
        return new CylinderLoader();
    default:
        return new CylinderLoader();
    }
}

void RenderModel::createVBOs(GLenum usage, int meshIndex)
{
    ///////////////////////////////////////////////////////
    /// Envoi des sommets vers des buffers en mémoire vidéo
    ///////////////////////////////////////////////////////

    /// Allocations des buffers
    // Création d'un ID de buffer (VBO)
    glGenBuffers(1, &m_vertexBufferObjectIDs[meshIndex]);

    // Sélectionne le buffer
    glBindBuffer(GL_ARRAY_BUFFER, m_vertexBufferObjectIDs[meshIndex]);

    // Alloue le buffer des données (sommets, etc.)
    glBufferData(GL_ARRAY_BUFFER,
                 sizeof(GLfloat) * m_object->vertices(meshIndex).size() /* Taille total du buffer en octets (toutes données confonfues */,
                 nullptr,
                 usage);

    /// Transfert des données
    // Transfert les sommets de la RAM vers le buffer vidéo
    glBufferSubData(GL_ARRAY_BUFFER,
                    0 /* Offset des données dans le buffer */,
                    sizeof(GLfloat) * m_object->vertices(meshIndex).size() /* Taille des données en octet */,
                    m_object->vertices(meshIndex).data());

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
    glGenBuffers(1, &m_elementBufferObjectIDs[meshIndex]);

    // Sélection le buffer
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_elementBufferObjectIDs[meshIndex]);

    // Alloue et initialise le buffer avec les données des indices des sommets par face
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,
                 sizeof(GLuint) * m_object->faces(meshIndex).size() /* Taille en octets des indices de sommets des faces */,
                 m_object->faces(meshIndex).data(),
                 usage);
}

void RenderModel::enableVBOs(int meshIndex) const
{
    // Activation du tableau des sommets
    glEnableVertexAttribArray(0);

    // On indique de quel buffer proviennent les sommets
    glBindBuffer(GL_ARRAY_BUFFER, m_vertexBufferObjectIDs[meshIndex]);
    // On indique de quel buffer proviennent les indices des sommets
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_elementBufferObjectIDs[meshIndex]);

    // Spécifie l'emplacement des données des sommets et leur format
    glVertexAttribPointer(0 /* Buffer objet utilisé */,
                          3 /* 3 sommets par face */,
                          GL_FLOAT,
                          GL_FALSE,
                          0,
                          nullptr /* Pas d'offset */);
}

void RenderModel::init()
{
    glEnable(GL_DEPTH_TEST);

    // Réglage de la couleur de fond
    glClearColor(0.0, 0.0, 0.0, 1.0);
}

void RenderModel::initView()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void RenderModel::drawObject() const
{
    const auto numMesh = m_object->meshCount();
    // Pour chaque objets de la scène
    for (unsigned int m = 0 ; m < numMesh ; ++m)
    {
        if (m_object->hasTexture())
        {
            glEnable(GL_TEXTURE_2D);
            m_object->selectTexture();
        }

        // Active les VBO pour l'affichage
        enableVBOs(m);

        // Dessin
        glDrawElements(m_object->mode(m),
                       GLsizei(m_object->vertices(m).size()) /* Nombre d'éléments */,
                       GL_UNSIGNED_INT,
                       nullptr);

        glDisable(GL_TEXTURE_2D);
    }
}
