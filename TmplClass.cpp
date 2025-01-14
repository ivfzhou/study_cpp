#include <iostream>

template<typename T, typename E> void friendMethod(TmplClass<T, E> &c) {
    // 访问Class的私有成员
    std::cout << c.privateField << std::endl;
}

template<typename T, typename E> void operator-(TmplClass<T, E> &c) {
    c.privateField -= c.privateField;
    c.publicField -= c.publicField;
}

template<typename T, typename E> std::ostream &operator<<(std::ostream &os, TmplClass<T, E> &c) { return os; }

// 静态成员初始化在类体外
template<typename T, typename E> int TmplClass<T, E>::staticField = 0;

template<typename T, typename E> const int TmplClass<T, E>::constStaticField = 0;

// 冒号后面是常量成员的初始化，初始化执行顺序与成员在类中定义顺序相关，在类创建时处理
template<typename T, typename E> TmplClass<T, E>::TmplClass() : constField(0), constReferenceField(constField) {
    privateField = 0;
    publicField = 0;
    protectedField = 0;
}

template<typename T, typename E> TmplClass<T, E>::TmplClass(int pubField) : constField(pubField), constReferenceField(constField) {
    TmplClass::publicField = pubField;
    privateField = 0;
    protectedField = 0;
}

template<typename T, typename E> TmplClass<T, E>::TmplClass(const TmplClass<T, E> &c) : constField(c.publicField), constReferenceField(c.publicField) {
    privateField = c.privateField;
    publicField = c.publicField;
    protectedField = c.protectedField;
}

template<typename T, typename E> TmplClass<T, E>::~TmplClass() = default;


// 类方法实现
template<typename T, typename E> void TmplClass<T, E>::method() {}

template<typename T, typename E> void TmplClass<T, E>::hasStaticMethod(int incr) {
    static int x = 0;
    x += incr;
}

// 静态成员函数
template<typename T, typename E> void TmplClass<T, E>::staticMethod() {}

template<typename T, typename E> void TmplClass<T, E>::constMethod() const {
    // this->method(); // 非法
}

template<typename T, typename E> TmplClass<T, E> &TmplClass<T, E>::operator=(int x) {
    publicField = x;
    return *this;
}

template<typename T, typename E> TmplClass<T, E> TmplClass<T, E>::operator++() {
    return TmplClass<T, E>();
}

template<typename T, typename E> TmplClass<T, E>::operator int() {
    return publicField;
}

template<typename T, typename E> TmplClass<T, E> & TmplClass<T, E>::operator=(const TmplClass<T, E> &c) /* = default */ {
    if (this == &c) return *this; // 自己给自己赋值。
    return *this;
}

template<typename T, typename E> void TmplClass<T, E>::operator()() {}

template<typename T, typename E> E TmplClass<T, E>::tmplMethod(T) {
    E e;
    return e;
}

template<typename T, typename E> void TmplClass<T, E>::InnerClass::innerClassMethod() {}


template<typename T, typename E> inline void operator*(const TmplClass<T, E> &, const TmplClass<T, E> &) {}
