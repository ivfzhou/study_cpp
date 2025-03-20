#include <iostream>

namespace gitee::com::ivfzhou::cpp::override_method_test {
    class TestClass {
      public:
        void m();
    };

    class TestClass1 : public TestClass {
        void m();
    };

    class TestClass2 : public TestClass1 {};

    void TestClass::m() { std::cout << "TestClass" << std::endl; }

    void TestClass1::m() { std::cout << "TestClass1" << std::endl; }
}

void TestOverrideMethod() {
    using namespace gitee::com::ivfzhou::cpp::override_method_test;
    TestClass2 c22;
    // c22.m();
    static_cast<TestClass>(c22).m();
}
