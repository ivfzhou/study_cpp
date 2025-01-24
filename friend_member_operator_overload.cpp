#include <iostream>

#include "friend_member_operator_overload.hpp"

namespace gitee::com::ivfzhou::cpp::friend_member_operator_overload {
    TestClass operator+(int x, const TestClass& ts) {
        TestClass c;
        c.x = ts.x + x;
        std::cout << "TestClass operator+" << std::endl;
        return c;
    }

    std::ostream& operator<<(std::ostream& os, const TestClass& tc) {
        os << tc.x;
        return os;
    }

    TestClass::TestClass() = default;

    TestClass::TestClass(int x) : x(x) {
        std::cout << "TestClass x" << std::endl;
    }

    TestClass TestClass::operator+(int x) const {
        TestClass c;
        c.x = this->x + x;
        std::cout << "TestClass::operator+ x" << std::endl;
        return c;
    }

    TestClass TestClass::operator+(const TestClass& tc) const {
        TestClass c;
        c.x = this->x + tc.x;
        std::cout << "TestClass::operator+ tc" << std::endl;
        return c;
    }
}
