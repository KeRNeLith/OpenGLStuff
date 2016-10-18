/******************************************************************************\
*     Copyright (C) 2016 by Alexandre Rabérin                                  *
*                                                                              *
* The program is distributed under the terms of the GNU General Public License *
*                                                                              *
\******************************************************************************/

#ifndef LIGHTSOURCE_H
#define LIGHTSOURCE_H

#include <vector>

#include "pointlightsource.h"

/**
 * @brief The LightSource class Gère le stockage des sources de lumières de la scène.
 */
class LightSource
{
public:
    /**
     * @brief The LandmarkType enum Représente le type de repère à utiliser pour le placement des sources lumineuses.
     */
    enum LandmarkType
    {
        CAMERA,
        WORLD
    };

private:
    std::vector<PointLightSource> m_sourcesCameraLandmark;  ///< Sources de lumières dans le repère de la caméra.
    std::vector<PointLightSource> m_sourcesWorldLandmark;   ///< Sources de lumières dans le repère monde.

    /**
     * @brief Test si une lumière contenue dans vec possède l'id id.
     * @param id Id de lumière recherché.
     * @param vec Tableau de source lumineuse.
     * @return True si l'id est déjà présent.
     */
    bool testDoublons(GLenum id, const std::vector<PointLightSource> vec);

    /**
     * @brief Récupère le tableaux des sources lumineuse, soit dans le repère monde soit dans le repère caméra.
     * @param type Type de repère.
     * @return Tableau des sources lumineuse.
     */
    std::vector<PointLightSource>& getSourcesFromLandmark(LightSource::LandmarkType type);

public:
    /**
     * @brief Constructeur.
     */
    LightSource();

    /**
     * @brief Ajoute une source lumineuse.
     * @param landmarkType Type de repère dans lequel placé la source.
     * @param lightId Id de la lumière.
     * @param lightPosX Position X de la source lumineuse.
     * @param lightPosY Position Y de la source lumineuse.
     * @param lightPosZ Position Z de la source lumineuse.
     * @param diffuseIntensityR Intensité diffuse sur la composante rouge.
     * @param diffuseIntensityG Gntensité diffuse sur la composante vert.
     * @param diffuseIntensityB Intensité diffuse sur la composante bleu.
     * @param specularIntensityR Intensité spéculaire sur la composante rouge.
     * @param specularIntensityG Intensité spéculaire sur la composante vert.
     * @param specularIntensityB Intensité spéculaire sur la composante bleu.
     * @return True si la source a pu être ajoutée, sinon faux dans le cas où l'id de lumière est déjà utilisé.
     */
    bool addLightSource(LightSource::LandmarkType landmarkType, GLenum lightId,
                        GLfloat lightPosX, GLfloat lightPosY, GLfloat lightPosZ,
                        GLfloat diffuseIntensityR = 0.4f, GLfloat diffuseIntensityG = 0.4f, GLfloat diffuseIntensityB = 0.4f,
                        GLfloat specularIntensityR = 0.4f, GLfloat specularIntensityG = 0.4f, GLfloat specularIntensityB = 0.4f);

    /**
     * @brief Supprime la source lumineuse correspondant à l'id lightId.
     * @param lightId Id de la source lumineuse.
     */
    void removeLightSource(GLenum lightId);

    /**
     * @brief Positionne toute les sources lumineuses dans le repère spécifié.
     * @param type Type de repère à utiliser.
     */
    void applyLightPositions(LightSource::LandmarkType type);

    /**
     * @brief Applique les intensités de toutes les sources lumineuses.
     */
    void applyLightIntensities();

    /**
     * @brief Désactive toute les sources lumineuses du repère spécifié.
     * @param type Type de repère cible.
     */
    void disableLightSources(LightSource::LandmarkType type);

    /**
     * @brief Récupère le tableaux des sources lumineuse, soit dans le repère monde soit dans le repère caméra.
     * @param type Type de repère.
     * @return Tableau des sources lumineuse.
     */
    const std::vector<PointLightSource>& getSourcesFromLandmark(LightSource::LandmarkType type) const;
};

#endif // LIGHTSOURCE_H
