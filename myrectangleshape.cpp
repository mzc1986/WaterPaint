#include "myrectangleshape.h"
#include "qdebug.h"

MyRectangleShape::MyRectangleShape()
{
}


void MyRectangleShape::setPoint1(QPoint p1)
{
    qRect.setTopLeft(p1);
    //qDebug() << "rect 1";
}

void MyRectangleShape::setPoint2(QPoint p2)
{
    qRect.setBottomRight(p2);
    //qDebug() << "rect 1";
}
