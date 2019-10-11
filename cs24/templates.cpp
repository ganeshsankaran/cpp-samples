#include <iostream>
#include <string>
using namespace std;

template <typename T>
T maximum(T a, T b) {
    if(a > b) {
        return a;
    }
    return b;
}

template <typename T> // include .cpp file in header if doing just skeleton
class Pair {
public: 
    Pair(T first, T second) {
        this->first = first;
        this->second = second;
    }
    void setFirst(T value) {
        first = value;
    }
    void setSecond(T value) {
        second = value;
    }
    T getFirst() {
        return first;
    }
    T getSecond() {
        return second;
    }
private:
    T first;
    T second;
};
int main() {
    Pair<int>* p1 = new Pair<int>(1,2);
    Pair<string>* p2 = new Pair<string>("one", "two");
    cout << "(" << p1->getFirst() << ", " << p1->getSecond() << ")" << endl;
    cout << "(" << p2->getFirst() << ", " << p2->getSecond() << ")" << endl;
    return 0;
}