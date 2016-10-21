/******************************************************************************\
*     Copyright (C) 2016 by Alexandre Rabérin                                  *
*                                                                              *
* The program is distributed under the terms of the GNU General Public License *
*                                                                              *
\******************************************************************************/

#ifndef PIXELSBUFFER_H
#define PIXELSBUFFER_H

#include <vector>

/**
 * @brief The PixelsBuffer class Gère le stockage d'un buffer de pixels (Bitmap) dans le but de le transformer en une texture.
 */
class PixelsBuffer
{
    unsigned int m_width;   ///< Largeur du buffer (en pixels).
    unsigned int m_height;  ///< Hauteur du buffer (en pixels).
    unsigned int m_bytesPerPixel;   ///< Nombre d'octets par pixel.
    unsigned int m_scanLineWidth;   ///< Largeur d'une scanline (doit être multiple de 4).

    std::vector<unsigned char> m_pixels;    ///< Tableaux des couleurs des pixels (tableau contigu).

public:

    /**
     * @brief Constructeur produisant un fond de texture blanc.
     * @param width Largeur de l'image.
     * @param height Hauteur de l'image.
     * @param bytesPerPixel Nombre d'octets par pixel.
     */
    PixelsBuffer(int width, int height, int bytesPerPixel);

    /**
     * @brief Constructeur produisant une texture à partir d'un buffer d'entré.
     * @param width Largeur de l'image.
     * @param height Hauteur de l'image.
     * @param bytesPerPixel Nombre d'octets par pixel.
     * @param data Buffer de pixels.
     */
    PixelsBuffer(int width, int height, int bytesPerPixel, unsigned char* data);

    /**
     * @brief Modifie la taille du buffer de pixels.
     * @param width Largeur de l'image.
     * @param height Hauteur de l'image.
     * @param bytesPerPixel Nombre d'octets par pixel.
     */
    void setSize(int width, int height, int bytesPerPixel);

    /**
     * @brief Met à jour les valeurs du pixel (x, y).
     * @param x Coordonnée X du pixel dans l'image.
     * @param y Coordonnée Y du pixel dans l'image.
     * @param array Valeurs à affecter au pixel (x, y).
     */
    void setPixelBytes(int x, int y, unsigned char* array);

    // Accesseurs
    /**
     * @brief Récupère la largeur de l'image.
     * @return Largeur de l'image.
     */
    int getWidth() const
    {
        return m_width;
    }

    /**
     * @brief Récupère la hauteur de l'image.
     * @return Hauteur de l'image.
     */
    int getHeight() const
    {
        return m_height;
    }

    /**
     * @brief Récupère le nombre d'octets par pixel de l'image.
     * @return Nombre d'octets par pixel.
     */
    int getBytesPerPixel() const
    {
        return m_bytesPerPixel;
    }

    /**
     * @brief Accès au données brutes des pixels du buffer.
     * @return Pointeur sur les données des pixels.
     */
    unsigned char* getRawData()
    {
        return m_pixels.data();
    }
};

#endif // PIXELSBUFFER_H
