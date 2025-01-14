#include <iostream>

namespace locate_new {
    class TestClass {
      public:
        ~TestClass() {
            std::cout << "deconstructor" << std::endl;
        }
    };

    void test() {
        char *buf = new char[1024];
        auto tc = new(buf) TestClass;
        auto tc0 = new(buf + sizeof(TestClass)) TestClass;
        //delete tc; // error
        tc->~TestClass(); // 需要手动调用析构
        tc0->~TestClass();
        delete[] buf;
    }

}
