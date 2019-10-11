#include <iostream>
#include <string>
#include <map>
#include <utility> // pair values

using namespace std;

int main() {
    map<int, string> students; // <key type, value type>

    students[0] = "Bob";
    students[10] = "Joe";
    students[20] = "John";
    // ordered by keys (red-black tree under the hood)
    
    cout << students[10] << endl;

    if(students.find(1) == students.end()) { // find key 1
        cout << "Can't find key of 1" << endl;
    }
    else {
        cout << students[1] << endl;
    }

    students.insert(pair<int, string>(3, "Tom"));
    students.insert(pair<int, string>(10, "Mike")); // key of 10 already used
    cout << students[3] << endl;
    cout << students[10] << endl;

    students[10] = "Mike"; // actually overwrites
    cout << students[10] << endl;

    students.erase(20);

    for(map<int, string>::iterator i = students.begin(); i != students.end(); i++) {
        cout << i->first << ", " << i->second << endl;
    }
    return 0;
}