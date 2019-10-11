#include <iostream>
using namespace std;

class NegativeValueException {};
class ZeroValueException {};
class DivideByZeroException {};

double divide(int num, int denom) throw(DivideByZeroException) {
    if(!denom) {
        throw DivideByZeroException();
    }
    return num / (double) denom;
}

int main(int argc, char* argv[]) {
    int value = atoi(argv[1]);
    try {
        if(value < 0) {
            throw NegativeValueException();
        }
        else if(value == 0) {
            throw ZeroValueException();
        }
        cout << "The integer entered is " << value << endl;
    }
    catch(NegativeValueException e) {
        cerr << "ERROR: The integer entered is negative" << endl;
    }
    catch(ZeroValueException e) {
        cerr << "ERROR: The integer entered is zero" << endl;
    }
    try {
        cout << "1 / " << value << " = " << divide(1, value) << endl;
    }
    catch(...) {
        cerr << "ERROR: cannot divide by zero" << endl;
    }
    return 0;
}

