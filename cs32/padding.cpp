#include <iostream>

using namespace std;

struct S1 { // [a a a a], [b b c d]
    int a; // 4 bytes
    short b; // 2 bytes;
    char c; // 1 byte;
    char d; // 1 byte;
};

struct S2 { // [a _ _ _], [b b b b], [c _ d d]
    char a; // 1 byte;
    int b; // 4 bytes;
    char c; // 2 bytes;
    short d; // 1 byte;
};

struct S3 { // [a _ _ _ b b b b], [c c c c c c c c], [d _ _ _ _ _ _ _]
    char a; // 1 byte;
    int b; // 4 bytes;
    double c; // 1 byte;
    char d; // 8 bytes;
};

int main() {
    S1 s1;
    S2 s2;
    S3 s3;
    cout << sizeof(s1) << endl;
    cout << sizeof(s2) << endl; // time-space tradeoff
    cout << sizeof(s3) << endl;

    cout << &s1.a << " " << &s1.b << " " << reinterpret_cast<void*>(&s1.c) << " " << reinterpret_cast<void*>(&s1.d) << endl;
    cout << reinterpret_cast<void*>(&s2.a) << " " << &s2.b << " " << reinterpret_cast<void*>(&s2.c) << " " << &s2.d << endl;
    cout << reinterpret_cast<void*>(&s3.a) << " " << &s3.b << " " << &s3.c << " " << reinterpret_cast<void*>(&s3.d) << endl;

    return 0;
}