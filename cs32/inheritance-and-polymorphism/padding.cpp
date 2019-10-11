#include <iostream>
using namespace std;


class X {
public:
    int a;
    short b;
    X() {
        a = 0;
        b = 0;
    }
};

class Y : public X { // essentially padding a, b, c, and d together as one block, not two
public:
    short c;
    short d;
    Y() : X() {
        c = 0;
        d = 0;
    }
};

int main() {
    X x1;
    Y y1;
    X x2 = y1;

    cout << "-----x1-----" << endl;
    cout << &x1.a << endl;
    cout << &x1.b << endl;
    cout << "-----y1-----" << endl;
    cout << &y1.a << endl;
    cout << &y1.b << endl;
    cout << &y1.c << endl;
    cout << &y1.d << endl;
    cout << "-----x2-----" << endl;
    cout << &x2.a << endl;
    cout << &x2.b << endl;
    return 0;
}
