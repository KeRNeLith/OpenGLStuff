/******************************************************************************\
*     Copyright (C) 2016 by Adrien Pierreval                                   *
*                                                                              *
* The program is distributed under the terms of the GNU General Public License *
*                                                                              *
\******************************************************************************/

#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <iostream>
#include <GL/glut.h>
#include <SDL/SDL.h>

#include "Tools/pixelbuffer.h"



/**
 * @brief The TextureManager class Gère
 */
class TextureManager {
    private:
        GLuint m_texId;             ///< Identifiant de texture
        PixelBuffer m_buffer;       ///< Buffer unique réutilisé à chaque nouvel affichage

        /**
         * @brief creeSurface Crée une surface SDL à partir du fichier BMP fourni.
         * @param path Chemin vers le fichier BMP contenant la texture.
         */
        SDL_Surface * creeSurface(const char* path);

    public:
        /**
         * @brief Constructeur initialise une texture dans un buffer.
         * @param filePath Chemin vers la texture à charger.
         */
        TextureManager(const char * filePath);

        /**
         * @brief Destructeur : décharge une texture de la mémoire.
         */
        ~TextureManager();

        /**
         * @brief selectTexture2D Sélectionne une texture.
         */
        void selectTexture2D() const;

        /**
         * @brief Met l'image donnée en argument dans un buffer en mémoire.
         * @param path Chemin vers la texture à charger
         */
        void creeBufferFromPicture(const char * path);

        /**
         * @brief creeTexture2D Crée une texture 2D en mémoire vidéo à partir
         * du buffer en variable globale. Le buffer en question doit avoir été rempli
         * avec des pixels avec @libk<Cree_RGBA_buffer_with_text>
         */
        void creeTexture2D();
};

#endif // TEXTUREMANAGER_H
