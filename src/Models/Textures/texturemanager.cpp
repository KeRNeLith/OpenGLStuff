#include "texturemanager.h"

TextureManager::TextureManager(const char * filePath)
  :m_texId(0),
  m_buffer(0, 0, 0)
{ 
  creeBufferFromPicture(filePath);
  creeTexture2D();
}

TextureManager::~TextureManager() {
  glDeleteTextures(1, &m_texId);
}

void TextureManager::selectTexture2D() const {
  glBindTexture(GL_TEXTURE_2D, m_texId);
}

SDL_Surface* TextureManager::creeSurface(const char * path) {
  // Vérification de l'extension du fichier
  if(strlen(path) < 5 ||
    (strcmp(".bmp", path + (strlen(path) -4)) &&
    strcmp(".BMP", path + (strlen(path) - 4)))) {
        std::cerr << "Erreur d'ouverture de fichier BMP : " << path << std::endl;
  }

  SDL_Surface * surface = SDL_LoadBMP(path);
  if(!surface) {
    std::cerr << "Erreur d'ouverture de fichier BMP : " << path
      << " (Echec de SDL_LoadBMP)" << std::endl;
  }

  return surface;
}

void TextureManager::creeBufferFromPicture(const char * path) {
  // Chargement de l'image au format BMP
  SDL_Surface * surface = creeSurface(path);

  // Creaton d'un buffer maison à partir de la surface SDL
  m_buffer = PixelBuffer(surface->w, surface->h, /*surface->format->BytesPerPixel*/ 4, (uint8_t *) surface->pixels);

  std::cout << surface->pixels <<std::endl;

  // Libération de la surface
  SDL_FreeSurface(surface);
}

void TextureManager::creeTexture2D() {
  // Au cas où la texture existe déjà
  glDeleteTextures(1, &m_texId);

  // Génération de l'ID de texture et sélection
  glGenTextures(1, &m_texId);
  selectTexture2D();    // Pour modifier la texture en mémoire vidéo

  // Paramètres de filtres linéaires
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

  GLint mode;
  switch(m_buffer.getBytesPerPixel()) {
    case 1:
      mode = GL_LUMINANCE;
      break;
    case 3:
      mode = GL_RGB;
      break;
    case 4:
      mode = GL_RGBA;
      break;
    default:
      std::cerr << "Nombre de bits par pixels non géré !" << std::endl;
      return; 
  }

  // Transfert de la texture en mémoire vidéo
  glTexImage2D(GL_TEXTURE_2D, 0, mode, m_buffer.getWidth(), m_buffer.getHeight(),
    0, mode, GL_UNSIGNED_BYTE, m_buffer.getRawData());
  glBindTexture(GL_TEXTURE_2D, m_texId);
}