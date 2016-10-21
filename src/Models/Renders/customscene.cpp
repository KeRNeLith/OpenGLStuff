#include "customscene.h"

#include "Models/model.h"

#include "Transforms/transform.h"

CustomScene::CustomScene(const Model& model)
    : RenderScene(model)
    , m_cylinderRender(RenderModel::CYLINDER, m_model.getTexture())
{

}

void CustomScene::drawScene() const
{
    m_cylinderRender.drawObject();
}
