#include "customscene.h"

#include "Transforms/transform.h"

CustomScene::CustomScene(const Model& model)
    : RenderScene(model)
    , m_object("data/fichiers3DS/Audi_tt.3ds")
{

}

void CustomScene::drawScene()
{
    GeometricTransform::pushMatrix();

    GeometricTransform::rotate(-80.0, 1.0, 0.0, 0.0);
    GeometricTransform::rotate(30.0, 0.0, .0, 1.0);

    m_object.drawObject();

    GeometricTransform::popMatrix();
}
