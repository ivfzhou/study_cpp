#ifndef ASSIGN_COPY_OPERATE
#define ASSIGN_COPY_OPERATE

#include <string>

namespace assign_copy_operate {
    class TestClass {
      public:

        int x = 1;

        std::string name = "";

        explicit TestClass(int x, std::string name);

        explicit TestClass();

        // copy constructor
        TestClass(const TestClass &);

        // assign operate
        TestClass &operator=(const TestClass &);

        TestClass operator+(const TestClass &) const;

        ~TestClass();
    };
}

#endif
