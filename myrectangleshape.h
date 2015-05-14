#pragma once
#include "shapes.h"

#include <QRect>

class MyRectangleShape : public Shapes
{

public:
    QRect qRect;

    //default constructor
    MyRectangleShape();
    //parameterized constructor
    MyRectangleShape(const QColor& c, int w);
    //destructor
    ~MyRectangleShape();

    //Mutators
    void setPoint1(const QPoint& point1);
    void setPoint2(const QPoint& point2);
    bool setColor(const QColor& color);
    bool setWidth(const int width);

    //Accessors
    QColor getColor() const; // read only function to member
    int getWidth() const;
};
