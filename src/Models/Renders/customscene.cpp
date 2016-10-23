#include "customscene.h"

#include "Models/model.h"

#include "Transforms/transform.h"

CustomScene::CustomScene(const Model& model)
    : RenderScene(model)
    , m_objectRender("data/fichiers3DS/Audi_tt.3ds")
    //, m_objectRender(RenderModel::CYLINDER)
{

}

void CustomScene::drawScene() const
{
    m_objectRender.drawObject();
}
