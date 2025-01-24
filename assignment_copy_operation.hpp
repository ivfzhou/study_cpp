#ifndef GITEE_COM_IVFZHOU_CPP_ASSIGNMENT_COPY_OPERATION
#define GITEE_COM_IVFZHOU_CPP_ASSIGNMENT_COPY_OPERATION

#include <string>

namespace gitee::com::ivfzhou::cpp::assignment_copy_operation {
    class TestClass {
    public:
        int x = 0;

        std::string name = "";

        TestClass();

        // 复制构造方法。
        TestClass(const TestClass&);

        // 赋值运算符。
        TestClass& operator=(const TestClass&);

        TestClass(int x, std::string name);

        TestClass operator+(const TestClass&) const;

        ~TestClass();
    };
}

#endif
