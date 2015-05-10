#pragma once
#include "shapes.h"

#include <QtWidgetsDepends>

class MyPenShape : public Shapes
{
public:
    QLine qline;
    MyPenShape();
    void setPoint1(QPoint p1);
    void setPoint2(QPoint p2);
    void print();
};
