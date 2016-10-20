/******************************************************************************\
*     Copyright (C) 2016 by Adrien Pierreval                                   *
*                                                                              *
* The program is distributed under the terms of the GNU General Public License *
*                                                                              *
\******************************************************************************/

#ifndef PIXELBUFFER_H
#define PIXELBUFFER_H

#include <vector>

/**
 * @brief The PixelBuffer class Gère le stockage d'un buffer de pixels (BITMAP)
 * dans le but d'en faire une texture.
 */
class PixelBuffer{

    int m_width;                                ///< Largeur de la texture
    int m_height;                               ///< Hauteur de la texture
    int m_bytesPerPixel;                        ///< Nombre d'octets par pixel
    int m_scanLineWidth;                        ///< Largeur d'une scanline doit être multiple de 4

    std::vector<unsigned char> m_pixels;        ///< Couleurs des pixels dans un tableau contigu.

private:

    /**
     * @brief Constructeur par défaut : inaccessible
     */
    PixelBuffer() :
        m_width(0),
        m_height(0),
        m_bytesPerPixel(0),
        m_scanLineWidth(0),
        m_pixels()
    { }

    public:
        /**
         * @brief Constructeur avec fond blanc
         */
        PixelBuffer(int width, int height, int bytesPerPixel) :
            m_width(width),
            m_height(height),
            m_bytesPerPixel(bytesPerPixel),
            m_scanLineWidth(width * bytesPerPixel + (4 - (width * bytesPerPixel) % 4) % 4),
            m_pixels(m_scanLineWidth * height, 0xff)
        {}

        /**
         * @brief Constructeur en copiant un buffer
         */
        PixelBuffer(int width, int height, int bytesPerPixel, unsigned char * data) :
            m_width(width),
            m_height(height),
            m_bytesPerPixel(bytesPerPixel),
            m_scanLineWidth(width * bytesPerPixel + (4 - (width * bytesPerPixel) % 4) % 4),
            m_pixels(m_scanLineWidth * height, 0xff)
        {
            memcpy (m_pixels.data(), data, m_scanLineWidth * height);
        }

        /**
         * @brief Modifie la taille du buffer
         * @return true si la dimension du buffer suffit
         */
        void setSize(int width, int height, int bytesPerPixel) {
            m_width = width;
            m_height = height;
            m_bytesPerPixel = bytesPerPixel;
            m_scanLineWidth = width * bytesPerPixel + (4 - (width * bytesPerPixel) % 4) % 4;
            m_pixels = std::vector<unsigned char> (m_scanLineWidth * height, 0xff);
        }

        /**
         * @brief Récupère la longueur du buffer
         * @return Longueur du buffer
         */
        int getWidth() {
            return m_width;
        }

        /**
         * @brief Récupère la hauteur du buffer
         * @return Hauteur du buffer
         *
         */
        int getHeight() {
            return m_height;
        }

        /**
         * @brief Récupère le nombre d'octets par pixel
         * @return Nombre d'octets par pixel
         */
        int getBytesPerPixel() {
            return m_bytesPerPixel;
        }

        /**
         * @brief Change un pixel à une position donnée
         */
        void setPixelBytes(int x, int y, unsigned char * array) {
            int startByte = x * m_scanLineWidth + y * m_bytesPerPixel;
            memcpy(m_pixels.data() + startByte, array, m_bytesPerPixel);
        }

        /**
         * @brief Accès au pixel via un pointeur
         * @return Un pointeur sur le tableau de pixels
         */
        unsigned char * getRawData() {
            return m_pixels.data();
        }
};

#endif
