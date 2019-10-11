#include <iostream>
#include <string>
#include "person.h"
#include "student.h"

using namespace std; 


void functionByValue(Person p) {
    cout << p.str() << endl;
}

void functionByReference(Person& p) {
    cout << p.str() << endl;
}


int main() {
    
    Student s1("Bob", 16, 123);
    Person p1 = s1; // A student is a person
    cout << p1.str() << endl; // PERSON str
    Person* p2 = new Person("Joe", 21);
    cout << p2->str() << endl;
    Student* s2 = new Student("Joe", 21, 234);
    cout << s2->str() << endl; // STUDENT str
    Person* p3 = s2; // memory slicing doesn't happen on the heap
    cout << p3->str() << endl; // STUDENT str

    cout << "-----" << endl;
    functionByValue(s1);
    functionByReference(s1);
    functionByValue(*s2);
    functionByReference(*s2);

    cout << "-----" << endl;
    delete p2;
    delete s2;

    return 0;
}