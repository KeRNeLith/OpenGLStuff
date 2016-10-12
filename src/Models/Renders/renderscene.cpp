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
    , m_wheelRender()
{
}

void RenderScene::drawAxle()
{
    // Dessin des roues
    GeometricTransform::pushMatrix();
    const std::array<double, 3>& wheelRotationAxis = m_model.getWheelRotationAxis();
    GeometricTransform::rotate(m_model.getWheelAngle(), wheelRotationAxis[0], wheelRotationAxis[1], wheelRotationAxis[2]);

    GeometricTransform::pushMatrix();
    GeometricTransform::translate(-5.0, 0, 0);

    m_wheelRender.drawObject();

    GeometricTransform::popMatrix();
    GeometricTransform::pushMatrix();

    GeometricTransform::translate(5.0, 0.0, 0.0);
    m_wheelRender.drawObject();

    GeometricTransform::popMatrix();

    // Dessin essieu
    glLineWidth(5);
    glBegin(GL_LINES);
    glVertex3f(-5.0, 0.0, 0.0);
    glVertex3f(5, 0.0, 0.0);
    glEnd();
    glLineWidth(1);

    GeometricTransform::popMatrix();
}

void RenderScene::drawScene()
{
    drawAxle();
}
