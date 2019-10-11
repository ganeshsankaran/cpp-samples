#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int square(int x) {
    return x * x; 
}

template <class T>
void print(vector<T>& v) {
    for(size_t i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

void ex1() {
    string s = "abcd";
    transform(s.begin(), s.end(), s.begin(), ::toupper); // naming conflict
    cout << s << endl;
}

void ex2() {
    vector<int> v;
    for(int i = 10; i <= 15; i++) {
        v.push_back(i);
    }
    print(v);
    transform(v.begin(), v.end(), v.begin(), square);
    print(v);

    cout << reinterpret_cast<void*>(square) << endl; // where the function exists in a lower level representation
}

int main() {
    ex1();
    ex2();

    int (*fp1)(int);
    fp1 = square;
    cout << (*fp1)(2) << " is the same as " << fp1(2) << endl;
    return 0;
}