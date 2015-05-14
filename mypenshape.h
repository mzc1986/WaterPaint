#pragma once
#include "shapes.h"

#include <QtWidgetsDepends>

class MyPenShape : public Shapes
{
public:
    QLine qline;
    MyPenShape();
    //parameterized constructor
    MyPenShape(const QColor& c, int w);

    //destructor
    ~MyPenShape();
    void setPoint1(const QPoint& point1);
    void setPoint2(const QPoint& point2);

    //Mutators
    bool setColor(const QColor& color);
    bool setWidth(const int width);

    //Accessors
    QColor getColor() const; // read only function to member
    int getWidth() const;

    void print();
};
