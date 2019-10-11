#include <iostream>
#include <vector> // container

using namespace std;

template<class T> 
void print(vector<T> &v) {
    for(size_t i = 0; i < v.size(); i++) { // size_t is like int, but it has all values addressable in memory for any system
        cout << v[i] << " ";
    }
    cout << endl;
}

void ex1() {
    vector<int> v;

    for(int i = 0; i < 5; i++) {
        v.push_back(i);
    }
    print(v);

    for(int i = 0; i < v.size(); i++) {
        v[i] *= 2;
    }
    print(v);

    cout << v[4] << " = " << v.at(4) << endl;
    cout << v[5] << /* " ? " << v.at(5) << */ endl;

    v.pop_back();
    print(v);
}

void ex2() {
    vector<int> v1(5, 1);
    vector<int> v2(10, 1);
    cout << sizeof(v1) << " " << sizeof(v2) << endl; // just the size of the vector (pointer, etc) on the stack, not the heap
}

void ex3() {
    vector<int>* v = new vector<int>(5, 1);
    print(*v);
    cout << v->size() << endl;
    cout << sizeof(v) << endl;
}

int main() {
    ex3();
    return 0;
}



