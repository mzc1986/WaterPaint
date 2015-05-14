#include "mylineshape.h"
#include <qdebug.h>
MyLineShape::MyLineShape()
{

}

MyLineShape::MyLineShape(const QColor &c, int w)
{
    myPenColor = c;
    myPenWidth = w;
}

void MyLineShape::setPoint1(const QPoint &point1)
{
    p1 = point1;
    qline.setP1(p1);
    //qDebug() << "point 1";

}

void MyLineShape::setPoint2(const QPoint &point2)
{
    p2 = point2;
    qline.setP2(p2);
    //qDebug() << "point 2";
}

bool MyLineShape::setColor(const QColor &color)
{
    myPenColor = color;
}

bool MyLineShape::setWidth(const int width)
{
    myPenWidth = width;
}

void MyLineShape::print()
{
    qDebug() << qline;
    //qDebug() << qline.p2();
}

QColor MyLineShape::getColor() const
{
    return myPenColor;
}

int MyLineShape::getWidth() const
{
    return myPenWidth;
}

MyLineShape::~MyLineShape()
{

}
