#ifndef _SQUARE_H_
#define _SQUARE_H_

#include "shape.h"
class Square : public Shape {
public:
    Square(double side);
    virtual double area();
private:
    double side;
};

#endif