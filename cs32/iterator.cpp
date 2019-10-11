#include <iostream>
#include <vector>
#include <string>

using namespace std;

void ex1() {
    vector<int> v;

    for(int i = 0; i < 5; i++) {
        v.push_back(i);
    }

    for(vector<int>::iterator i = v.begin(); i < v.end(); i++) {
        cout << *i << " ";
    }
    cout << endl;
}

void ex2() {
    vector<string> v;
    v.push_back("a");
    v.push_back("b");
    for(vector<string>::iterator i = v.begin(); i < v.end(); i++) {
        cout << *i << " " << i->size() << endl;
    }
}
int main() {
    ex2();
    return 0;
}