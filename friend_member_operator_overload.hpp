#ifndef GITEE_COM_IVFZHOU_CPP_FRIEND_MEMBER_OPERATOR_OVERLOAD
#define GITEE_COM_IVFZHOU_CPP_FRIEND_MEMBER_OPERATOR_OVERLOAD

#include <iostream>

namespace gitee::com::ivfzhou::cpp::friend_member_operator_overload {
    class TestClass {
        friend TestClass operator+(int, const TestClass&);

        friend std::ostream& operator<<(std::ostream&, const TestClass&);

        int x = 0;

    public:
        TestClass();

        explicit TestClass(int);

        TestClass operator+(int) const;

        TestClass operator+(const TestClass&) const;
    };
}

#endif
