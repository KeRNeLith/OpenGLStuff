#include "teapot.h"

#include <GL/glut.h>

Teapot::Teapot(const Model& model)
    : RenderScene(model)
{

}

void Teapot::drawScene()
{
    glutSolidTeapot(10);
}
