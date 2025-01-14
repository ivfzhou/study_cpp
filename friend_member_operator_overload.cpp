#include <iostream>

#include "friend_member_operator_overload.hpp"

namespace friend_member_operator_overload {
    TestClass operator+(int x, const TestClass &ts) {
        TestClass c{};
        c.x = ts.x + x;
        std::cout << "友元加" << std::endl;
        return c;
    }

    std::ostream &operator<<(std::ostream &os, const TestClass &tc) {
        os << tc.x;
        return os;
    }

    TestClass::TestClass() = default;

    TestClass::TestClass(int x) : x(x) {
        std::cout << "构造-int转对象" << std::endl;
    }

    TestClass TestClass::operator+(int x) const {
        TestClass c;
        c.x = this->x + x;
        std::cout << "成员加int" << std::endl;
        return c;
    }

    TestClass TestClass::operator+(const TestClass &tc) const {
        TestClass c{};
        c.x = this->x + tc.x;
        std::cout << "成员加obj" << std::endl;
        return c;
    }

    void test() {
        TestClass tc;
        TestClass tc0 = tc + 1; // operator+(int)
        std::cout << tc0 << std::endl;
        TestClass tc1 = 1 + tc;
        std::cout << tc1 << std::endl;
    }
}
