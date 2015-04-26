#include "myellipseshape.h"

MyEllipseShape::MyEllipseShape()
{
}

void MyEllipseShape::setPoint1(QPoint p1)
{
    qEllipse.setTopLeft(p1);
}

void MyEllipseShape::setPoint2(QPoint p2)
{
    qEllipse.setBottomRight(p2);
}
