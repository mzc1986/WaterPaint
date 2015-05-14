#pragma once

#include <QColor>
#include <QPoint>
#include <iostream>

using namespace std;

class Shapes
{
protected:
    //These points will be shared by every object
    QPoint p1;
    QPoint p2;

    QColor myPenColor;
    int myPenWidth;

public:
    //Mutators
    virtual void setPoint1(const QPoint& point1) {};
    virtual void setPoint2(const QPoint& point2) {};
    virtual bool setColor(const QColor& color){};
    virtual bool setWidth(const int width){};

    //Accessors
    virtual QColor getColor() const {} ; // read only function to member
    virtual int getWidth() const {};
};
