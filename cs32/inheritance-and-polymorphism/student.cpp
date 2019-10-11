#include <iostream>
#include <string>
#include "student.h"

using namespace std;

Student::Student(string name, int age, int id) : Person(name, age) {
    cout << "STUDENT: CONSTRUCTOR" << endl;
    this->id = id;
}

Student::~Student() {
    cout << "STUDENT: DESTRUCTOR" << endl;
}

string Student::getName() {
    return Person::getName();
}

int Student::getAge() {
    return Person::getAge();
}

int Student::getId() {
    return this->id;
}

void Student::setId(int id) {
    this->id = id;
}

string Student::str() {
    return "STUDENT: " + this->getName() + ", " + to_string(this->getAge()) + ", " + to_string(this->id);
}
