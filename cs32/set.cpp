#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
    set<string> s;
    s.insert("Harry");
    s.insert("Hermione");
    s.insert("Ron");

    for(set<string>::iterator i = s.begin(); i != s.end(); i++) {
        cout << *i << ", ";
    }
    cout << endl;
}