#include <iostream>

namespace cn_ivfzhou_cpp {
    class TestClass20 {
    public:
        void m();
    };

    class TestClass21 : public TestClass20 {
        void m();
    };

    class TestClass22 : public TestClass21 {

    };

    void TestClass20::m() {
        std::cout << "20";
    }

    void TestClass21::m() {
        std::cout << "21";
    }
}

void TestClass20() {
    cn_ivfzhou_cpp::TestClass22 c22;
    // c22.m();
    ((cn_ivfzhou_cpp::TestClass20) c22).m();
}
