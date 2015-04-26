#pragma once
#include "shapes.h"
#include <QRect>


class MyEllipseShape : public Shapes
{
public:
    QRect qEllipse;
    MyEllipseShape();
    void setPoint1(QPoint p1);
    void setPoint2(QPoint p2);
};
