/******************************************************************************\
*     Copyright (C) 2016 by Alexandre Rabérin                                  *
*                                                                              *
* The program is distributed under the terms of the GNU General Public License *
*                                                                              *
\******************************************************************************/

#include "lightsource.h"

#include <algorithm>

LightSource::LightSource()
    : m_sourcesCameraLandmark()
    , m_sourcesWorldLandmark()
{

}

bool LightSource::testDoublons(GLenum id, const std::vector<PointLightSource> vec)
{
    bool ret = false;

    auto itR = std::find_if(vec.cbegin(), vec.cend(), [&id](const PointLightSource& light)
    {
        return light.getLightId() == id;
    });

    if (itR != vec.cend())
    {
        ret = true;
    }

    return ret;
}

bool LightSource::addLightSource(LightSource::LandmarkType landmarkType, GLenum lightId,
                                 GLfloat lightPosX, GLfloat lightPosY, GLfloat lightPosZ,
                                 GLfloat diffuseIntensityR, GLfloat diffuseIntensityG, GLfloat diffuseIntensityB,
                                 GLfloat specularIntensityR, GLfloat specularIntensityG, GLfloat specularIntensityB)
{
    bool ret = false;
    if (!testDoublons(lightId, m_sourcesCameraLandmark) && !testDoublons(lightId, m_sourcesWorldLandmark))
    {
        getSourcesFromLandmark(landmarkType).push_back(PointLightSource(lightId,
                                                                       lightPosX, lightPosY, lightPosZ,
                                                                       diffuseIntensityR, diffuseIntensityG, diffuseIntensityB,
                                                                       specularIntensityR, specularIntensityG, specularIntensityB));
        ret = true;
    }

    return ret;
}

void LightSource::removeLightSource(GLenum lightId)
{
    m_sourcesCameraLandmark.erase(std::remove_if(m_sourcesCameraLandmark.begin(), m_sourcesCameraLandmark.end(), [&lightId](const PointLightSource& light)
    {
        return light.getLightId() == lightId;
    }));

    m_sourcesWorldLandmark.erase(std::remove_if(m_sourcesWorldLandmark.begin(), m_sourcesWorldLandmark.end(), [&lightId](const PointLightSource& light)
    {
        return light.getLightId() == lightId;
    }));
}

void LightSource::applyLightPositions(LightSource::LandmarkType type)
{
    auto& sources = getSourcesFromLandmark(type);
    std::for_each(sources.begin(), sources.end(), [](const PointLightSource& light)
    {
       light.applyLightPointPosition();
    });
}

void LightSource::applyLightIntensities()
{
    std::for_each(m_sourcesCameraLandmark.begin(), m_sourcesCameraLandmark.end(), [](const PointLightSource& light)
    {
       light.applyLightPointIntensity();
    });

    std::for_each(m_sourcesWorldLandmark.begin(), m_sourcesWorldLandmark.end(), [](const PointLightSource& light)
    {
       light.applyLightPointIntensity();
    });
}

void LightSource::disableLightSources(LightSource::LandmarkType type)
{
    auto& sources = getSourcesFromLandmark(type);
    std::for_each(sources.begin(), sources.end(), [](const PointLightSource& light)
    {
       light.disableLightPoint();
    });
}

std::vector<PointLightSource>& LightSource::getSourcesFromLandmark(LightSource::LandmarkType type)
{
    if (type == LightSource::LandmarkType::CAMERA)
    {
        return m_sourcesCameraLandmark;
    }
    else
    {
        return m_sourcesWorldLandmark;
    }
}

const std::vector<PointLightSource>& LightSource::getSourcesFromLandmark(LightSource::LandmarkType type) const
{
    return getSourcesFromLandmark(type);
}