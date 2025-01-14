#include <iostream>
#include <string>

#include "assign_copy_operate.hpp"

namespace assign_copy_operate {
    TestClass::TestClass(int x, std::string name) : x(x), name(name) {
        std::cout << "TestClass constructor " << name << " " << x << std::endl;
    }

    TestClass::TestClass() {
        std::cout << "TestClass default constructor " << std::endl;
    }

    TestClass::TestClass(const TestClass &tc) {
        std::cout << "TestClass copy constructor " << tc.name << " " << tc.x << std::endl;
        this->x = tc.x;
        this->name = tc.name + "_copied";
    }

    TestClass &TestClass::operator=(const TestClass &tc) {
        std::cout << "TestClass assign operate " << name << " = " << tc.name << std::endl;
        this->name = tc.name + "_assigned";
        this->x = tc.x;
        return *this;
    }

    TestClass TestClass::operator+(const TestClass &tc) const {
        std::cout << "TestClass add operate " << name << " + " << tc.name << std::endl;
        TestClass tc0(this->x + tc.x, name + "+" + tc.name);
        return tc0;
    }

    TestClass::~TestClass() {
        std::cout << "TestClass deconstructor " << name << " " << x << std::endl;
    }

    /*
    1. TestClass constructor tc0 1
    2. TestClass constructor tc1 2
    3. TestClass add operate tc0 + tc1
    4. TestClass constructor tc0+tc1 3
    5. TestClass copy constructor tc0+tc1 3
    6. TestClass default constructor
    7. TestClass assign operate  = tc1
    8. TestClass deconstructor tc1_assigned 2
    9. TestClass deconstructor tc0+tc1 3
    10. TestClass deconstructor tc1 2
    11. TestClass deconstructor tc0 1
    12. TestClass deconstructor tc0+tc1_copied 3
    */
    void test() {
        assign_copy_operate::TestClass *tc;
        {
            assign_copy_operate::TestClass tc0(1, "tc0"), tc1(2, "tc1"); // 1 2
            auto tc3 = assign_copy_operate::TestClass(tc0 + tc1); // 3 4
            tc = new assign_copy_operate::TestClass(tc3); // 5
            assign_copy_operate::TestClass tc4; // 6
            tc4 = tc1; // 7
        } // 8 9 19 11 12
        delete tc; // 13
    }
}
