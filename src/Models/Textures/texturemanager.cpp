/******************************************************************************\
*     Copyright (C) 2016 by Alexandre Rabérin                                  *
*                                                                              *
* The program is distributed under the terms of the GNU General Public License *
*                                                                              *
\******************************************************************************/

#include "texturemanager.h"

#include <iostream>

#include "Tools/stringalgorithms.h"

TextureManager::TextureManager(const std::string& filePath)
    : m_textureId(0)
    , m_buffer(0, 0, 0)
{
    createBufferFromPicture(filePath);
}

TextureManager::~TextureManager()
{
    glDeleteTextures(1, &m_textureId);
}

SDL_Surface* TextureManager::createSurface(const std::string& filePath)
{
    SDL_Surface* surface = nullptr;

    if (endsWith(toLower(filePath), std::string(".bmp")))
    {
        surface = SDL_LoadBMP(filePath.c_str());

        if (!surface)
        {
            std::cerr << "Erreur lors du chargement du fichier bmp : " << filePath << "." << std::endl;
        }
    }
    else
    {
        std::cerr << "Le fichier texture n'est pas un fichier au format bmp." << std::endl;
    }

    return surface;
}

void TextureManager::selectTexture2D() const
{
    glBindTexture(GL_TEXTURE_2D, m_textureId);
}

void TextureManager::createBufferFromPicture(const std::string& filePath)
{
    // Chargement du fichier image
    SDL_Surface* surface = createSurface(filePath);

    // Alloue le buffer de texture avec l'image chargée.
    m_buffer = PixelsBuffer(surface->w, surface->h, surface->format->BytesPerPixel, (uint8_t*) surface->pixels);

    // Désalloue la surface SDL
    SDL_FreeSurface(surface);
}

void TextureManager::createTexture2D()
{
    // Supprime la texture si elle existait déjà
    glDeleteTextures(1, &m_textureId);

    // Génération de l'id de texture et la sélectionne
    glGenTextures(1, &m_textureId);
    selectTexture2D();  // Pour modifier la texture dans la mémoire vidéo

    // Paramètres de filtres linéaires appliqués à la texture
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // Sélection du mode de texture (Noir&Blanc, couleur, couleur + transparence)
    GLint mode;
    switch (m_buffer.getBytesPerPixel())
    {
    case 1:
        mode = GL_LUMINANCE;
        break;
    case 3:
        mode = GL_RG8;
        break;
    case 4:
        mode = GL_RGBA;
        break;
    default:
        std::cerr << "Nombre de bits par pixels non géré" << std::endl;
        return;
    }

    // Transfert la texture dans la mémoire vidéo
    glTexImage2D(GL_TEXTURE_2D, 0, mode,
                 m_buffer.getWidth(), m_buffer.getHeight(),
                 0, mode,
                 GL_UNSIGNED_BYTE, m_buffer.getRawData());

    glBindTexture(GL_TEXTURE_2D, m_textureId);
}
