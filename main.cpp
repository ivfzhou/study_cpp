#include <iostream>

#include "TmplClass.hpp"

namespace assign_copy_operate {
    extern void test();
}
namespace cast_var {
    extern void testCVT();
}
namespace character {
    extern void universalCharacterName();
    extern void weightChar();
    extern void rawString();
    extern void chars();
}
namespace exception {
    extern void test();
}
namespace friend_member_operator_overload {
    extern void test();
}
namespace iterator {
    extern void test();
}
namespace locate_new {
    extern void test();
}
namespace macro_test {
    extern void test();
}
namespace member_initializer_list {
    extern void test();
}
namespace multiple_inheritance {
    extern void test();
}
extern void test();
namespace private_extend {
    extern void test();
}
namespace rtti {
    extern void test();
}
namespace smart_pointer {
    extern void test();
}
extern void testClass();
extern void testString();
namespace cn_ivfzhou_cpp {
    extern void initialization();
    extern void coutCtl();
    extern void use();
    extern void escape();
    extern void constArrayLength();
    extern void typeSize();
    extern void forceTypeChange();
    extern void initString();
    extern void diffGetGetline();
    extern void anonymousUnion();
    extern void initPointer();
    extern void dynamicArray();
    extern void operatorPrecedence();
    extern void useVector();
    extern void useArray();
    extern void boolPrint();
    extern void wait();
    extern void especialForLoop();
    extern void cinEscape();
    extern void fileIO();
    extern void refVar();
    extern void ptrAdd();
    template<typename T> extern void tmplFun(T t);
    extern void defaultVarFunc(int x, int y = 1, int z = 2);
    extern void classFieldPointer();
    extern void thisUsage();
    extern void constRef();
    extern void constPtr();
    extern void testClass();
    extern void friendOverload();
    extern void incrTest();
    extern void testVirtualMethod();
    extern void testPureVirtualMethod();
    extern void useGlobalVar();
    extern void testIsAStaticVar();
    extern TmplClass<int, int> returnClass();
    extern void classInit();
    extern void testDecltype();
    extern void testCout();
    extern void testCin();
    extern void test_fio();
    extern void test_exit();
    extern auto fund() -> decltype(1);
    extern void test_rv();
    extern void testAuto();
    template<typename F, typename ...Args> extern void variable_template(F &&f, Args &&...args);
    extern void test_vt();
}
namespace template_ {
    extern void test();
}
namespace template_static_member {
    extern void test();
}
extern void TestC();
extern void TestClass20();
namespace valarray_usage {
    extern void test();
}
namespace value_pass {
    extern void test();
}
namespace vararg_test {
    extern void test();
}

/*
 * 1. 自动变量、寄存器变量、内部静态变量、外部静态变量、内部静态函数、外部函数。
 * */
int main(const int argv, const char *argc[]) {

    std::cout << "exit ok" << std::endl;
    return 0;
}
