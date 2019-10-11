#ifndef _ADT_H_
#define _ADT_H_

#include <iostream>
using namespace std;

class Date {
public:
    Date(); // default constructor (must be declared if there is a parametrized constructor)
    Date(int month, int day); // parametrized constructor
    void setDateFromStdin();
    int getMonth() const; 
    // const causes compile-time error whenever function tries to modify a member variable
    int getDay() const;
private:
    int mm;
    int dd;
};

Date::Date() { // use :: (scope operator)
    mm = 1;
    dd = 1;
}

Date::Date(int month, int day) {
    mm = month;
    dd = day;
}

/* 
constructor with initialization list
use this to initialize a constant member variable

Date::Date(int month, int day): mm(month), dd(day) {
    // nothing in the body
}
*/

void Date::setDateFromStdin() {
    cin >> mm >> dd;
}

int Date::getMonth() const {
    return mm;
}

int Date::getDay() const {
    return dd;
}

int main() {
    Date today(1,7);
    Date birthday;
    cout << "What is your birthday?" << endl;
    birthday.setDateFromStdin();

    if(today.getMonth() == birthday.getMonth() && today.getDay() == birthday.getDay()) {
        cout << "Happy birthday!" << endl;
    }
    else {
        cout << "Oh well" << endl;
    }
    return 0;
}

#endif
