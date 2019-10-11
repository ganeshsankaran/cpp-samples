#include <iostream>
#include "shape.h"
#include "rectangle.h"
#include "square.h"

using namespace std;

int main() {
    // Shape s;
    // Shape shapes[2];

    Rectangle r1(2,5);
    Square s1(2);

    cout << r1.area() << endl;
    cout << s1.area() << endl;

    Rectangle* r2 = new Rectangle(3,4);
    Square* s2 = new Square(3);

    cout << r2->area() << endl;
    cout << s2->area() << endl;
    cout << "---Array of Shapes---" << endl;
    Shape* shapes[2];
    shapes[0] = new Rectangle(9, 11);
    shapes[1] = new Square(10);

    cout << shapes[0]->area() << endl;
    cout << shapes[1]->area() << endl;

    return 0;
}