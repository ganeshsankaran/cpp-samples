
#ifndef _STUDENT_H_
#define _STUDENT_H_

#include "person.h"

// derived/child/subclass for Person class
class Student : public Person { // public inheritance (public->public, protected->protected)
public:
    Student(std::string name, int age, int id);
    virtual ~Student();
    std::string getName();
    int getAge();
    int getId();
    void setId(int id);
    virtual std::string str(); // carry over virtual for good style
private:
    int id;
};

#endif