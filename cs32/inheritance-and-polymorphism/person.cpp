#include <iostream>
#include <string>
#include "person.h"

using namespace std;

Person::Person(string name, int age) {
    cout << "PERSON: CONSTRUCTOR" << endl;
    this->name = name;
    this->age = age;
}

Person::~Person() {
    cout << "PERSON: DESTRUCTOR" << endl;
}
string Person::getName() {
    return name;
}

int Person::getAge() {
    return age;
}

void Person::setName(string name) {
    this->name = name;
}

void Person::setAge(int age) {
    this->age = age;
}

string Person::str() {
    return "PERSON: " + this->name + ", " + to_string(this->age);
}