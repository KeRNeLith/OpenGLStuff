/******************************************************************************\
*     Copyright (C) 2016 by Adrien Pierreval                                   *
*                                                                              *
* The program is distributed under the terms of the GNU General Public License *
*                                                                              *
\******************************************************************************/

#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include "Tools/pixelbuffer.h"


/**
 * @brief The TextureManager class Gère
 */
class TextureManager {
    GLuint m_textId;            ///< Identifiant de texture

    PixelBuffer m_buffer;       ///< Buffer unique réutilisé à chaque nouvel affichage

    protected:
        SDL_Surface* CreeSurface(const char* path);

    public:
        TextureManager(const char * filePath);
        ~TextureManager();

        void SelectTexture2D() const;
        void CreeBufferFromPicture(const char * path);
        void CreeTexture2D();

};

#endif // TEXTUREMANAGER_H
