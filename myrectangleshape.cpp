#include "myrectangleshape.h"
#include "qdebug.h"

MyRectangleShape::MyRectangleShape()
{

}

MyRectangleShape::MyRectangleShape(const QColor &c, int w)
{
    myPenColor = c;
    myPenWidth = w;
}

void MyRectangleShape::setPoint1(const QPoint &point1)
{
    p1 = point1;
    qRect.setTopLeft(p1);
}

void MyRectangleShape::setPoint2(const QPoint &point2)
{
    p2 = point2;
    qRect.setBottomRight(p2);
}

bool MyRectangleShape::setColor(const QColor &color)
{
    myPenColor = color;
    return true;
}

bool MyRectangleShape::setWidth(const int width)
{
    myPenWidth = width;
    return true;
}

QColor MyRectangleShape::getColor() const
{
    return myPenColor;
}

int MyRectangleShape::getWidth() const
{
    return myPenWidth;
}

MyRectangleShape::~MyRectangleShape()
{

}
