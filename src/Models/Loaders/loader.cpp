/******************************************************************************\
*     Copyright (C) 2016 by Alexandre Rabérin                                  *
*                                                                              *
* The program is distributed under the terms of the GNU General Public License *
*                                                                              *
\******************************************************************************/

#include "loader.h"

Loader::Loader(TextureManager* texture)
    : m_texture(texture)
{
}

Loader::~Loader()
{
}

void Loader::selectTexture() const
{
    m_texture->selectTexture2D();
}
