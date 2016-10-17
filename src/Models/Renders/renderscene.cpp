/******************************************************************************\
*     Copyright (C) 2016 by Alexandre Rabérin                                  *
*                                                                              *
* The program is distributed under the terms of the GNU General Public License *
*                                                                              *
\******************************************************************************/

#include "renderscene.h"

#include "Models/model.h"

#include "Transforms/transform.h"

RenderScene::RenderScene(const Model& model)
    : m_model(model)
    , m_cylinderRender(RenderModel::CYLINDER)
{
}

void RenderScene::drawScene()
{
    m_cylinderRender.drawObject();
}
