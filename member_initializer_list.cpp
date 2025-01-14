#include <iostream>

#include "member_initializer_list.hpp"

namespace member_initializer_list {
    TestClass::TestClass(int x) : x(x) {}

    void test() {
        TestClass tc(1);
        std::cout << tc.getY() << std::endl;
        std::cout << tc.getX() << std::endl;
    }
}
