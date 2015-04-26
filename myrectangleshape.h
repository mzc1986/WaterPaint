#pragma once
#include "shapes.h"

#include <QRect>

class MyRectangleShape : public Shapes
{
public:
    QRect qRect;
    MyRectangleShape();
    void setPoint1(QPoint p1);
    void setPoint2(QPoint p2);
};
