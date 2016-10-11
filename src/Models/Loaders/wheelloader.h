#ifndef WHEELLOADER_H
#define WHEELLOADER_H

#include "loader.h"

/**
 * @brief The WheelLoader class Gère un modèle 3D en forme de roue de voiture.
 * Note : Largeur 0.5, Rayon 1, Axe de symétrie : axe Z, formée de 12 quads.
 */
class WheelLoader
        : public Loader
{
public:
    /**
     * @brief Constructeur.
     */
    WheelLoader();

    /**
     * @brief Destructeur.
     */
    virtual ~WheelLoader();

    /**
     * @brief See Loader#meshCount()
     */
    unsigned int meshCount() const override;
    /**
     * @brief See Loader#modes()
     */
    GLenum modes(int meshIndex = 0) const override;
    /**
     * @brief See Loader#vertices(int)
     */
    const std::vector< GLfloat* >& vertices(int meshIndex = 0) const override;
    /**
     * @brief See Loader#faces(int)
     */
    const std::vector< std::vector<unsigned int> >& faces(int meshIndex = 0) const override;
};

#endif // WHEELLOADER_H
