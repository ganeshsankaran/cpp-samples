#include <iostream>
#include <unordered_map> // hash table with chaining
#include <utility> // for pair

using namespace std;

int main() {
    unordered_map<int, string> students;

    students[0] = "Bob";
    students[2] = "Joe";
    students[5] = "Jim";

    cout << students[0] << endl;
    if(students.find(1) != students.end()) {
        cout << students[1] << endl;
    }
    else {
        cout << "Can't find ID = 1" << endl;
    }

    students.insert(pair<int, string>(2, "John")); // doesn't overwrite
    students[2] = "John";

    unordered_map<int, string>::iterator p = students.find(5);
    students.erase(p);

    for(unordered_map<int, string>::iterator i = students.begin(); i != students.end(); i++) {
        cout << i->first << " " << i->second << endl;
    }
    return 0;
}