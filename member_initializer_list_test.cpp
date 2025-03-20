#include <iostream>

namespace gitee::com::ivfzhou::cpp::member_initializer_list {
    class TestClass {
        int x = 0; // 相当于初始化列表。
        const int y = 10;

      public:
        explicit TestClass(int);

        int getY() const { return y; }

        int getX() const { return x; }
    };


    TestClass::TestClass(int x) : x(x) {}
}

void TestMemberInitializerList() {
    using namespace gitee::com::ivfzhou::cpp::member_initializer_list;
    TestClass tc(1);
    std::cout << tc.getY() << std::endl;
    std::cout << tc.getX() << std::endl;
}
