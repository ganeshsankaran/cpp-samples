#include <iostream>
using namespace std;

class Person {
public:
    Person();
    Person(string newName);
    ~Person(); // destructor
    Person(Person& src);
    void setName(string newName);
    string getName() const;

private:
    string name;
};

Person::Person() {
    cout << "---CONSTRUCTOR---" << endl;
}

Person::Person(string newName) {
    cout << "---CONSTRUCTOR---" << endl;
    name = newName;
}

Person::~Person() { // doesn't actually destroy. Just runs before the object is destroyed
    cout << "---DESTRUCTOR---" << endl;
}

Person::Person(Person& src)

void Person::setName(string newName) {
    name = newName;
}

string Person::getName() const {
    return name;
}

int main() {
    Person p1("Bob");
    cout << p1.getName() << endl;
}