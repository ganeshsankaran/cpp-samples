#ifndef _PERSON_H_
#define _PERSON_H_

// Base/parent class for Student
class Person {
public:
    Person(std::string name, int age);
    virtual ~Person();
    std::string getName();
    int getAge();
    void setName(std::string name);
    void setAge(int age);
    virtual std::string str(); // turn on polymorphism
private:
    std::string name;
    int age;
// protected can be accessed by derived/child/subclasses
};

#endif