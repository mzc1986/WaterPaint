#pragma once
#include "shapes.h"

#include <QtWidgetsDepends>

class MyLineShape : public Shapes
{
public:
    QLine qline;
    MyLineShape();
    void setPoint1(QPoint p1);
    void setPoint2(QPoint p2);
    void print();
};
