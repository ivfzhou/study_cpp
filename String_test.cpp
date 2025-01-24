#include <iostream>
#include <ostream>
#include <string>

#include <String.hpp>

using namespace gitee::com::ivfzhou::cpp;

static String returnStr() {
    String s("abc");
    return s;
}

void TestString() {
    std::cout << returnStr() << std::endl;
    std::cout << std::endl << "===" << std::endl << std::endl;

    {
        String s("abc"); // 调用复制构造。
        String s0(s);
        std::string str("def");
        String s1(str);
        std::cout << "s is " << s << std::endl;
        std::cout << "s0 is " << s0 << std::endl;
        std::cout << "s1 is " << s1 << std::endl;
    }

    std::cout << std::endl << "===" << std::endl << std::endl;

    {
        String s;
        s = "abc"; // 调用成员赋值运算符。写成一行将调用单参数的构造函数，但由于构造函数加了 explicit，不能写成一行，
        String s0;
        s0 = s;
        std::string str("def");
        String s1;
        s1 = str;
        std::cout << "s is " << s << std::endl;
        std::cout << "s0 is " << s0 << std::endl;
        std::cout << "s1 is " << s1 << std::endl;
        String s2 = s + s0 + s1;
        std::cout << "s2 is " << s2 << std::endl;
    }

    std::cout << std::endl << "===" << std::endl << std::endl;

    {
        String s;
        s = "abc";
    }
}
