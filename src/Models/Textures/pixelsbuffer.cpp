/******************************************************************************\
*     Copyright (C) 2016 by Alexandre Rabérin                                  *
*                                                                              *
* The program is distributed under the terms of the GNU General Public License *
*                                                                              *
\******************************************************************************/

#include "pixelsbuffer.h"

#include <algorithm>

PixelsBuffer::PixelsBuffer(int width, int height, int bytesPerPixel)
    : m_width(width)
    , m_height(height)
    , m_bytesPerPixel(bytesPerPixel)
    , m_scanLineWidth(width * bytesPerPixel + (4 - (width * bytesPerPixel) %4 ) %4)
    , m_pixels(m_scanLineWidth * height, 0xff)
{
}

PixelsBuffer::PixelsBuffer(int width, int height, int bytesPerPixel, unsigned char* data)
    : m_width(width)
    , m_height(height)
    , m_bytesPerPixel(bytesPerPixel)
    , m_scanLineWidth(width * bytesPerPixel + (4 - (width * bytesPerPixel) %4 ) %4)
    , m_pixels(data, data + m_scanLineWidth * m_height)
{
}

void PixelsBuffer::setSize(int width, int height, int bytesPerPixel)
{
    m_width = width;
    m_height = height;
    m_bytesPerPixel = bytesPerPixel;
    m_scanLineWidth = width * bytesPerPixel + (4 - (width * bytesPerPixel) %4) %4;
    m_pixels = std::vector<unsigned char> (m_scanLineWidth * height, 0xff);
}

void PixelsBuffer::setPixelBytes(int x, int y, unsigned char* array)
{
    unsigned int startByte = x * m_scanLineWidth + y * m_bytesPerPixel;
    std::copy(array, array + m_bytesPerPixel, m_pixels.begin() + startByte);
}
