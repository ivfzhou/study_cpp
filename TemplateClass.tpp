#include <iostream>

#include "TemplateClass.hpp"

namespace gitee::com::ivfzhou::cpp {
    template <typename T, typename E>
    void friendMethod(TemplateClass<T, E>& c) {
        // 访问 Class 的私有成员。
        std::cout << c.privateField << std::endl;
    }

    template <typename T, typename E>
    void operator-(TemplateClass<T, E>& c) {
        c.privateField -= c.privateField;
        c.publicField -= c.publicField;
    }

    template <typename T, typename E>
    std::ostream& operator<<(std::ostream& os, TemplateClass<T, E>&) { return os; }

    // 静态成员初始化在类体外。
    template <typename T, typename E>
    int TemplateClass<T, E>::staticField = 0;

    template <typename T, typename E>
    const int TemplateClass<T, E>::constStaticField = 0;

    // 冒号后面是常量成员的初始化，初始化执行顺序与成员在类中定义顺序相关，在类创建时处理。
    template <typename T, typename E>
    TemplateClass<T, E>::TemplateClass() : constField(0), constReferenceField(constField) {
        privateField = 0;
        publicField = 0;
        protectedField = 0;
    }

    template <typename T, typename E>
    TemplateClass<T, E>::TemplateClass(int pubField) : constField(pubField), constReferenceField(constField) {
        publicField = pubField;
        privateField = 0;
        protectedField = 0;
    }

    template <typename T, typename E>
    TemplateClass<T, E>::TemplateClass(const TemplateClass& c) : constField(c.publicField),
                                                                 constReferenceField(c.publicField) {
        privateField = c.privateField;
        publicField = c.publicField;
        protectedField = c.protectedField;
    }

    template <typename T, typename E>
    TemplateClass<T, E>::~TemplateClass() = default;

    // 类方法实现。
    template <typename T, typename E>
    void TemplateClass<T, E>::method() {}

    template <typename T, typename E>
    void TemplateClass<T, E>::hasStaticMethod(int incr) {
        static int x = 0;
        x += incr;
    }

    // 静态成员函数。
    template <typename T, typename E>
    void TemplateClass<T, E>::staticMethod() {}

    template <typename T, typename E>
    void TemplateClass<T, E>::constMethod() const {
        // this->method(); // 非法。
    }

    template <typename T, typename E>
    TemplateClass<T, E>& TemplateClass<T, E>::operator=(int x) {
        publicField = x;
        return *this;
    }

    template <typename T, typename E>
    TemplateClass<T, E> TemplateClass<T, E>::operator++() {
        return TemplateClass();
    }

    template <typename T, typename E>
    TemplateClass<T, E>::operator int() {
        std::cout << "operator int()" << std::endl;
        return publicField;
    }

    template <typename T, typename E>
    TemplateClass<T, E>& TemplateClass<T, E>::operator=(const TemplateClass& c) {
        if (this == &c) return *this; // 自己给自己赋值。
        return *this;
    }

    template <typename T, typename E>
    void TemplateClass<T, E>::operator()() {
        std::cout << "operator()" << std::endl;
    }

    template <typename T, typename E>
    E TemplateClass<T, E>::tmplMethod(T) {
        E e = {};
        return e;
    }

    template <typename T, typename E>
    void TemplateClass<T, E>::InnerClass::innerClassMethod() {}


    template <typename T, typename E>
    void operator*(const TemplateClass<T, E>&, const TemplateClass<T, E>&) {}
}
