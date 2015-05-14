#include "mypenshape.h"
#include <qdebug.h>

#include <QtWidgetsDepends>

MyPenShape::MyPenShape()
{
    //qline = new Qline;
}

MyPenShape::MyPenShape(const QColor &c, int w)
{
    myPenColor = c;
    myPenWidth = w;
}


void MyPenShape::setPoint1(const QPoint &point1)
{
    p1 = point1;
    qline.setP1(p1);
    //qDebug() << "point 1";

}

void MyPenShape::setPoint2(const QPoint &point2)
{
    p2 = point2;
    qline.setP2(p2);
    //qDebug() << "point 2";
}

bool MyPenShape::setColor(const QColor &color)
{
    myPenColor = color;
}

bool MyPenShape::setWidth(const int width)
{
    myPenWidth = width;
}

void MyPenShape::print()
{
    qDebug() << qline;
    //qDebug() << qline.p2();
}

QColor MyPenShape::getColor() const
{
    return myPenColor;
}

int MyPenShape::getWidth() const
{
    return myPenWidth;
}

MyPenShape::~MyPenShape()
{

}
