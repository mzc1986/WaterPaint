#pragma once
#include "shapes.h"
#include <QRect>


class MyEllipseShape : public Shapes
{
public:
    QRect qEllipse;
    MyEllipseShape();

    MyEllipseShape(const QColor &c, int w);

    ~MyEllipseShape();
    void setPoint1(const QPoint& point1);
    void setPoint2(const QPoint& point2);
    bool setColor(const QColor& color);
    bool setWidth(const int width);

    //Accessors
    QColor getColor() const ; // read only function to member
    int getWidth() const;
};
