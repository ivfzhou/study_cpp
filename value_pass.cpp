#include <iostream>

namespace value_pass {
    class TestClass {
      public:
        ~TestClass() {
            std::cout << "destruct" << std::endl;
        }

        TestClass() {
            std::cout << "construct" << std::endl;
        }
    };

    TestClass get() {
        auto c = TestClass();
        std::cout << "do something" << std::endl;
        return c;
    }

    void test() {
        TestClass c = get();
    }
}
