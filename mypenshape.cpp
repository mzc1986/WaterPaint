#include "mypenshape.h"
#include <qdebug.h>

#include <QtWidgetsDepends>

MyPenShape::MyPenShape()
{
    //qline = new Qline;
}

void MyPenShape::setPoint1(QPoint p1)
{
    qline.setP1(p1);
    //qDebug() << "point 1";

}

void MyPenShape::setPoint2(QPoint p2)
{
    qline.setP2(p2);
    //qDebug() << "point 2";
}

void MyPenShape::print()
{
    qDebug() << qline;
    //qDebug() << qline.p2();
}
