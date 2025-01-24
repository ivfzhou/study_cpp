#include <iostream>
#include <string>

#include "assignment_copy_operation.hpp"

namespace gitee::com::ivfzhou::cpp::assignment_copy_operation {
    TestClass::TestClass() {
        std::cout << "TestClass" << std::endl;
    }

    TestClass::TestClass(const TestClass& tc) {
        std::cout << "TestClass tc" << tc.name << " " << tc.x << std::endl;
        this->x = tc.x;
        this->name = tc.name + "_copied";
    }

    TestClass& TestClass::operator=(const TestClass& tc) {
        std::cout << "TestClass::operator= " << name << " = " << tc.name << std::endl;
        this->name = tc.name + "_assigned";
        this->x = tc.x;
        return *this;
    }

    TestClass::TestClass(int x, std::string name) : x(x), name(name) {
        std::cout << "TestClass x, name " << name << " " << x << std::endl;
    }

    TestClass TestClass::operator+(const TestClass& tc) const {
        std::cout << "TestClass::operator+ " << name << " + " << tc.name << std::endl;
        TestClass tc0(x + tc.x, name + "+" + tc.name);
        return tc0;
    }

    TestClass::~TestClass() {
        std::cout << "~TestClass " << name << " " << x << std::endl;
    }
}
