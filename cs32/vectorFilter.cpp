#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <class T>
void print(vector<T>& v) {
    for(size_t i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

template <class T>
bool equal(T x, T y) {
    return x == y;
}

template <class T>
bool unequal(T x, T y) {
    return x != y;
}

template <class T>
vector<T> filterVector(vector<T> v, T value, bool(*filterFunction)(T, T)) {
    vector<T> result;
    for(size_t i = 0; i < v.size(); i++) {
        if(filterFunction(v[i], value)) {
            result.push_back(v[i]);
        }
    }
    return result;
}

void ex1() {
    vector<string> v1;
    v1.push_back("s1");
    v1.push_back("s2");
    v1.push_back("s3");
    v1.push_back("s4");
    string remove = "s2";
    print(v1);
    vector<string> v2 = filterVector(v1, remove, unequal);
    print(v2);
}

void ex2() {
    vector<int> v3;
    v3.push_back(1);
    v3.push_back(2);
    v3.push_back(1);
    print(v3);
    vector<int> v4 = filterVector(v3, 1, equal);
    print(v4);
}

int main() {
    ex1();
    ex2();
    return 0;
}