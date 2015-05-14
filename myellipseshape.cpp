#include "myellipseshape.h"

MyEllipseShape::MyEllipseShape()
{
}

MyEllipseShape::MyEllipseShape(const QColor &c, int w)
{
    myPenColor = c;
    myPenWidth = w;
}

void MyEllipseShape::setPoint1(const QPoint &point1)
{
    p1 = point1;
    qEllipse.setTopLeft(p1);
}

void MyEllipseShape::setPoint2(const QPoint &point2)
{
    p2 = point2;
    qEllipse.setBottomRight(p2);
}

bool MyEllipseShape::setColor(const QColor &color)
{
    myPenColor = color;
}

bool MyEllipseShape::setWidth(const int width)
{
    myPenWidth = width;
}

QColor MyEllipseShape::getColor() const
{
    return myPenColor;
}

int MyEllipseShape::getWidth() const
{
    return myPenWidth;
}


MyEllipseShape::~MyEllipseShape()
{

}
