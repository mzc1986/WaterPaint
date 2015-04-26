#include "mylineshape.h"
#include <qdebug.h>
MyLineShape::MyLineShape()
{

}

void MyLineShape::setPoint1(QPoint p1)
{
    qline.setP1(p1);
    //qDebug() << "point 1";

}

void MyLineShape::setPoint2(QPoint p2)
{
    qline.setP2(p2);
    //qDebug() << "point 2";
}

void MyLineShape::print()
{
    qDebug() << qline.p1();
    qDebug() << qline.p2();
}
