#include <iostream>
#include <string>
#include "namespace.h"

using namespace std;
using namespace ns;

void foo() { // ::foo()
    cout << "foo was called in namespace std" << endl;
}

class string {
};

int main() {
    ::foo(); // use the global namespace
    ns::foo(); 
    bar();
    ::string x;
    std::string y;
    return 0;
}