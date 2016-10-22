/******************************************************************************\
*     Copyright (C) 2016 by Alexandre Rabérin                                  *
*                                                                              *
* The program is distributed under the terms of the GNU General Public License *
*                                                                              *
\******************************************************************************/

#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <string>

#include <SDL2/SDL.h>

#include <GL/glut.h>

#include "Models/Textures/pixelsbuffer.h"

/**
 * @brief The TextureManager class Gère les opérations liées aux textures.
 */
class TextureManager
{
private:
    GLuint m_textureId;     ///< Id de texture.

    PixelsBuffer m_buffer;  ///< Buffer de la texture.

    /**
     * @brief Crée une surface SDL permettant le chargement d'un fichier BMP.
     * @param filePath Chemin vers le fichier image à charger.
     * @return Surface correspondant à l'image chargée.
     */
    SDL_Surface* createSurface(const std::string& filePath);

public:
    /**
     * @brief Constructeur.
     * @param filePath Chemin vers le fichier image à charger.
     */
    TextureManager(const std::string& filePath);

    /**
     * @brief Destructeur.
     */
    ~TextureManager();

    /**
     * @brief Sélectionne la texture.
     */
    void selectTexture2D() const;

    /**
     * @brief Alloue le buffer correspondant à l'image chargée.
     * @param filePath Chemin vers le fichier image à charger.
     */
    void createBufferFromPicture(const std::string& filePath);

    /**
     * @brief Crée une texture 2D en mémoire vidéo à partir du buffer de pixels de la texture.
     * @preliminary Le buffer m_buffer doit avoir été rempli avec les données d'une image ou texture.
     */
    void createTexture2D();
};

#endif // TEXTUREMANAGER_H
