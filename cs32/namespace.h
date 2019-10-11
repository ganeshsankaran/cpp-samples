#ifndef _NAMESPACE_H_ // header guards prevent double inclusion
#define _NAMESPACE_H_

#include <iostream>

namespace ns {
    void foo() {
        std::cout << "foo was called in namespace ns" << std::endl;
    }
    void bar() {
        std::cout << "bar was called in namespace ns" << std::endl;
    }
}

#endif
