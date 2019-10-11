#include <iostream>
#include "square.h"
using namespace std;

Square::Square(double side) {
    this->side = side;
}

double Square::area() {
    cout << "SQUARE: area" << endl;
    return side * side;
}