#include "customscene.h"

#include "Models/model.h"

#include "Transforms/transform.h"

CustomScene::CustomScene(const Model &model)
    : RenderScene(model)
    , m_cylinderRender(RenderModel::CYLINDER)
{

}

void CustomScene::drawScene() const
{
    m_cylinderRender.drawObject();
}
