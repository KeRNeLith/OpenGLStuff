/******************************************************************************\
*     Copyright (C) 2016 by Alexandre Rabérin                                  *
*                                                                              *
* The program is distributed under the terms of the GNU General Public License *
*                                                                              *
\******************************************************************************/

#include "pointlightsource.h"

PointLightSource::PointLightSource( GLenum lightId,
                                    GLfloat posX, GLfloat posY, GLfloat posZ,
                                    GLfloat diffuseIntensityR, GLfloat diffuseIntensityG, GLfloat diffuseIntensityB,
                                    GLfloat specularIntensityR, GLfloat specularIntensityG, GLfloat specularIntensityB)
    : m_lightId(lightId)
    , m_position({{ posX, posY, posZ, 1.0 }})
    , m_diffuseIntensity({{ diffuseIntensityR, diffuseIntensityG, diffuseIntensityB, 1.0f }})
    , m_specularIntensity({{ specularIntensityR, specularIntensityG, specularIntensityB, 1.0f }})
{
}

void PointLightSource::init()
{
    // Elimination des parties cachées
    glEnable(GL_DEPTH_TEST);
    // Active l'éclairage
    glEnable(GL_LIGHTING);

    // Modèle local
    glLightModelf(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
    // Lissage de Phong
    glShadeModel(GL_SMOOTH);

    // Intensité de la lumière ambiante
    GLfloat sceneAmbientIntensity[] = { 0.2f, 0.2f, 0.2f, 1.0f };
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, sceneAmbientIntensity);
}

void PointLightSource::applyLightPointPosition(GLenum lightId, const std::array<GLfloat, 4>& position)
{
    glLightfv(lightId, GL_POSITION, position.data());
}

void PointLightSource::applyLightPointIntensity(GLenum lightId, const std::array<GLfloat, 4>& diffuseIntensity, const std::array<GLfloat, 4>& specularIntensity)
{
    glLightfv(lightId, GL_DIFFUSE, diffuseIntensity.data());
    glLightfv(lightId, GL_SPECULAR, specularIntensity.data());
    enableLightPoint(lightId);
}

void PointLightSource::applyLightPointPosition() const
{
    PointLightSource::applyLightPointPosition(m_lightId, m_position);
}

void PointLightSource::applyLightPointIntensity() const
{
    PointLightSource::applyLightPointIntensity(m_lightId, m_diffuseIntensity, m_specularIntensity);
}

void PointLightSource::setLightPointIntensities(const std::array<GLfloat, 4>& diffuseIntensity, const std::array<GLfloat, 4>& specularIntensity)
{
    setLightPointDiffuseIntensity(diffuseIntensity);
    setLightPointSpecularIntensity(specularIntensity);
}

void PointLightSource::enableLightPoint(GLint lightId)
{
    glEnable(lightId);
}

void PointLightSource::disableLightPoint(GLint lightId)
{
    glDisable(lightId);
}

void PointLightSource::disableLightPoint() const
{
    PointLightSource::disableLightPoint(m_lightId);
}
