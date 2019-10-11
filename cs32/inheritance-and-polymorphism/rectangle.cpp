#include <iostream>
#include "rectangle.h"
using namespace std;

Rectangle::Rectangle(double length, double width) {
    this->length = length;
    this->width = width;
}

double Rectangle::area() {
    cout << "RECTANGLE: area" << endl;
    return length * width;
}
