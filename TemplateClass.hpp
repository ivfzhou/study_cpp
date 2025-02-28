#ifndef GITEE_COM_IVFZHOU_CPP_TMPL_CLASS
#define GITEE_COM_IVFZHOU_CPP_TMPL_CLASS

#include <iostream>

namespace gitee::com::ivfzhou::cpp {
    // 向前声明。
    template <typename T, typename E>
    class FriendClass;

    // 模板类。
    // =、复制构造和析构默认提供。
    template <typename T, typename E>
    class TemplateClass {
        // 友元类，这个类的所有成员函数都是友元函数了。
        friend class FriendClass<T, E>;

        // 友元函数。
        template <typename A, typename B>
        friend void friendMethod(TemplateClass<A, B>&);

        // 友元函数重载运算符。
        template <typename A, typename B>
        friend void operator-(TemplateClass<A, B>&);

        template <typename A, typename B>
        friend std::ostream& operator<<(std::ostream&, TemplateClass<A, B>&);

        // 友元方法。
        template <typename A, typename B>
        friend void FriendClass<A, B>::friendClassMethod();

    public:
        const static int constStaticField;

        static int staticField;

        const int constField; // 整形或者枚举 const 可以在声明中初始化。

        const int& constReferenceField;

        int publicField;

        // 构造函数，创建对象时自动调用。
        TemplateClass();

        // 重载构造函数，只有一个参数等价于类型转换函数。
        // explicit 表示不自动转换类型。
        TemplateClass(int);

        // 复制构造函数，不编写，系统默认提供。当把一个对象赋值给另一个对象时会使用。
        TemplateClass(const TemplateClass&);

        // 析构函数，没有参数，只能定义一个，类被释放时自动调用。
        ~TemplateClass();

        void method();

        // 在类体中实现方法，属于内联函数。
        void inlineMethod() {}

        void hasStaticMethod(int incr);

        // 类可以直接调用。
        static void staticMethod();

        // 常成员函数，能区分重载，函数内 this 指针指向值是常量，只能调用常成员函数。
        void constMethod() const;

        // 运算符重写。
        TemplateClass& operator=(int);

        // 前缀自增。
        TemplateClass operator++(/* int 加 int 变后缀自增 */);

        // int x = TemplateClass();
        // int x = static_cast<int>(TemplateClass());
        // 类型转化函数，不能是静态的。
        explicit operator int();

        // 默认提供赋值运算符。
        TemplateClass& operator=(const TemplateClass&);

        // TemplateClass tc;
        // tc();
        void operator()();

        // 模板函数。
        E tmplMethod(T);

        // 嵌套类
        class InnerClass {
        public:
            void innerClassMethod();
        };

        // 默认私有。
    private:
        int privateField;

    protected:
        int protectedField;
    };

    // 非成员运算符重载函数。
    template <typename T, typename E>
    void operator*(const TemplateClass<T, E>&, const TemplateClass<T, E>&);
}

#include "TemplateClass.tpp"

#endif
