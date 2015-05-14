#pragma once
#include "shapes.h"

#include <QtWidgetsDepends>

class MyLineShape : public Shapes
{
public:
    QLine qline;
    MyLineShape();

    MyLineShape(const QColor &c, int w);

    ~MyLineShape();
    void setPoint1(const QPoint& point1);
    void setPoint2(const QPoint& point2);
    bool setColor(const QColor& color);
    bool setWidth(const int width);

    //Accessors
    QColor getColor() const ; // read only function to member
    int getWidth() const;

    void print();
};
