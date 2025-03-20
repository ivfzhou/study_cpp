#include <array>
#include <iostream>

namespace gitee::com::ivfzhou::cpp::tmpl {
    // 为类型和非类型提供默认值。int len
    // 是表达式参数，只能是整形、枚举、引用、指针，表达式参数不能取址和修改，表达式参数需要是常量表达式。
    template<typename T = const char, int len = 1>
    class TestClass {
        T str[len]{};

        friend std::ostream& operator<<(std::ostream& os, const TestClass& a) { return os << a.str; }

      public:
        T& operator[](int index) { return str[index]; }

        TestClass& operator=(int) {
            std::cout << "TestClass operator=(int) is called" << std::endl;
            return *this;
        }

        std::string toString() { return "TestClass"; }
    };

    // 继承写法。
    template<typename T, int len>
    class TestClass0 : public TestClass<T, len> {};

    // 显式具体化。
    template<>
    class TestClass<char, 1> {
        char str[1] = {};

        friend std::ostream& operator<<(std::ostream& os, const TestClass& a) { return os << a.str; }

      public:
        char& operator[](int index) { return str[index]; }

        std::string toString() { return "TestClass explicit definition"; }
    };

    // 部分具体化。
    template<typename T>
    class TestClass<T, 2> {
        T str[2]{};

        friend std::ostream& operator<<(std::ostream& os, const TestClass& a) { return os << a.str; }

      public:
        T& operator[](int index) { return str[index]; }

        std::string toString() { return "TestClass partial definition"; }
    };

    // 显式实例化。
    template class TestClass<char, 3>;

    template<typename T1>
    class TestClass1 {};

    // 指针优先使用。
    // template <typename T1*>
    // class TestClass1 {};

    template<typename T1, typename T2, typename T3>
    class TestClass2 {};

    template<typename T1>
    class TestClass2<T1, T1, T1*> {};

    template<typename T>
    class TestClass3 {
        template<typename Tt>
        class TestClass4 {
            void method(TestClass4 t);
        };

        TestClass4<T> tc;
    };

    // 实现方法。
    template<typename T>
    template<typename Tt>
    void TestClass3<T>::TestClass4<Tt>::method(TestClass4 t) {}

    // 模板参数。
    template<template<typename T> class TestClass6, typename E>
    class TestClass5 {
        TestClass6<E> tt;
        TestClass6<int> tt1;
    };

    // 模板函数的类型范型不能有默认值，但参数范型和类一样都可以有默认值。
    template<typename T = int, int x = 0>
    void TemplateFunc() {
        T t;
        std::cout << "TemplateFunc is called, " << "t is " << t << ", x is " << x << std::endl;
    }

    // 模板别名。
    template<typename T>
    using TemplateAlias = TestClass<T, 9>;

    // 使用 using 定义别名。
    using ARRAY10 = std::array<int, 10>;
}

void TestTemplate() {
    using namespace gitee::com::ivfzhou::cpp::tmpl;

    TemplateAlias<int> a;

    TestClass<> obj;
    std::cout << obj.toString() << std::endl;

    TestClass<char, 1> obj0;
    std::cout << obj0.toString() << std::endl;

    TestClass<const char, 2> obj1;
    std::cout << obj1.toString() << std::endl;

    TestClass obj2;
    std::cout << obj2.toString() << std::endl;

    TestClass<char, 3> obj3;
    std::cout << obj3.toString() << std::endl;

    TemplateFunc<TestClass<>, 1>();
}
