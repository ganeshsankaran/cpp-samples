#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_

#include "shape.h" 

class Rectangle : public Shape {
public:
    Rectangle(double length, double width);
    virtual double area();
private:
    double length;
    double width;
};

#endif