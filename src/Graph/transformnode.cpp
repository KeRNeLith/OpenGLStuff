#include "transformnode.h"

TransformNode::TransformNode()
    : m_transform(1.0)
{

}

void TransformNode::apply()
{
    //glPushMatrix();
    //glLoadMatrix( (float*)m_fvMatrix );

    Node::apply();

    //glPopMatrix();
}
