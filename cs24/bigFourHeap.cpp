// *this* is a pointer to the object

#include <iostream>
using namespace std;

class Person {
public:
    Person();
    Person(string newName);
    ~Person(); // destructor
    Person(Person& src); // copy constructor

    void setName(string newName);
    string getName() const;

private:
    string* name;
};

Person::Person() {
    cout << "---CONSTRUCTOR---" << endl;
}

Person::Person(string newName) {
    cout << "---CONSTRUCTOR---" << endl;
    name = new string;
    *name = newName;
}

// doesn't actually destroy. Just runs before the object is destroyed
Person::~Person() { 
    cout << "---DESTRUCTOR---" << endl;
    delete name;
}

// default copy constructor only does a shallow copy
// pointers to member variables on heap are copied, meaning objects can share the same member variables
Person::Person(Person& src) { // pass by reference; otherwise, you have an infinite loop of calling copy constructors
    name = src.name;
}

void Person::setName(string newName) {
    *name = newName;
}

string Person::getName() const {
    return *name;
}

int main() {
    Person p1("Bob");
    Person* p2 = new Person("Joe");
    Person p3(p1); // 
    Person* p4 = new Person(p2);

    cout << p1.getName() << endl;
    cout << p2->getName() << endl;
}