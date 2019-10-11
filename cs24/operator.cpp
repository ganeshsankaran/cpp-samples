#include <iostream>
#include <string>

using namespace std;

class point {
public:
    point();
    point(double x0, double y0);
    void shift(double deltax, double deltay);
    void invert();
    double getx() const;
    double gety() const;
    friend point operator +(const point& p1, const point& p2);
private:
    double x;
    double y;
};

point::point() {
    x = 0.0;
    y = 0.0;
}

point::point(double x0, double y0) {
    x = x0;
    y = y0;
}

void point::shift(double deltax, double deltay) {
    x += deltax;
    y += deltay;
}

void point::invert() {
    double tmp = x;
    x = y;
    y = tmp;
}

double point::getx() const {
    return x;
}

double point::gety() const {
    return y;
}

point operator +(const point& p1, const point& p2) { // use friend keyword in class to access member variables
    point p;
    p.x = p1.getx() + p2.getx();
    p.y = p1.gety() + p2.gety();
    return p;
}

/*
point operator +(const point& p1, const point& p2) {
    point p(p1);
    p.shift(p2.getx(), p2.gety());
    return p;
}
*/

bool operator ==(const point& p1, const point& p2) { // pass by reference
    return p1.getx() == p2.getx() && p1.gety() == p2.gety();
}

ostream& operator <<(ostream& out, const point p) { // out is actually cout. there can only be one instance of cout
    out << "(" << p.getx() << ", " << p.gety() << ")" << endl;
    return out;
}

int main() {
    point p1;
    point p2(p1);
    p2.shift(6.9, 66.6);
    point p3(100, 200);
    point p4 = p2 + p3;

    if(p1 == p2) {
        cout << "These points are equal!" << endl;
    }

    cout << p4 << endl;



}
/*
int main() {
    string s1, s2, s3;
    s1 = "Hello"; // copy assignment
    s2 = " World"; // another copy assignment
    s3 = s1 + s2; // operator + has been overloaded
    cout << s3; // operator << has been overloaded to work with an object of ostream
    cout << endl;
    return 0;
}
*/