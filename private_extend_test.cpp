#include <iostream>

namespace gitee::com::ivfzhou::cpp::private_extend {
    class TestClass {
      public:
        friend std::ostream& operator<<(std::ostream&, const TestClass&);

        void method() {}
    };

    std::ostream& operator<<(std::ostream& os, const TestClass&) { return os << "TestClass"; }

    class TestClass0 : TestClass {
      public:
        friend std::ostream& operator<<(std::ostream&, const TestClass0&);

        using TestClass::method; // 使用父类成员做为本类成员。
    };

    std::ostream& operator<<(std::ostream& os, const TestClass0& tc) {
        return os << "TestClass0 << " << static_cast<const TestClass&>(tc);
    }
}

void TestPrivateExtend() {
    using namespace gitee::com::ivfzhou::cpp::private_extend;
    TestClass0 tc;
    std::cout << tc << std::endl;

    // TestClass &tc0 = tc; // 私有继承不能指向派生类。

    tc.method();
}
