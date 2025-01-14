#include <array>
#include <codecvt>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <locale>
#include <new>
#include <string>
#include <vector>

// c的标准库文件
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>

#include "FatherClass.hpp"
#include "FriendClass.hpp"
#include "SonClass.hpp"
#include "TmplClass.hpp"
#include "header.h"

namespace cn_ivfzhou_cpp {
    // using 编译指令
    using namespace std;

    void initialization() {
        int n(5);
        cout << n << endl;
        int x{};
        cout << x << endl;
        int y{5};
        cout << y << endl;
        int z = {5};
        cout << z << endl;

        int arr[1][2] = {1, 2}; // 两个元素的数组，每个元素为int[1]
        int(*ptr)[2](arr);
        cout << ptr << endl;

        TmplClass<int, int> c0 = {1}; // 调用构造函数
        TmplClass<int, int> c1{1};    // 调用构造函数
        TmplClass<int, int> c2 = 1;   // 一个参数的构造函数允许此法使用
        TmplClass<int, int> arr0[5] = {
                TmplClass<int, int>(1),
                // 剩下的元素使用默认构造函数
        };
        cout << c0 << endl;
        cout << c1 << endl;
        cout << c2 << endl;
        cout << arr0[0] << endl;
    }

    // cout 提供的控制符
    void coutCtl() {
        int n = 32;
        cout << hex << n << endl; // 0x20
        cout << dec << n << endl; // 32
        cout << oct << n << endl; // 40
    }

    // 使用名字空间的情形
    void use() {
        // 1
        using namespace std;

        // 2
        std::cout << endl;

        // 3 using 声明
        using std::printf;
        printf("\n");
    }

    // 特殊转义序列
    void escape() {
        char question = '\?';
        cout << question << endl; // ?
        char back = '\x08';
        cout << back << endl;
        char newline = '\012';
        cout << newline << endl;
    }

    // 布尔类型：bool b = true; bool c = false;

    // 使用const值声明数组长度
    void constArrayLength() {
        const int l = 10;
        int arr[l] = {};
        cout << arr[9] << endl;
    }

    // E表示法的数字都以浮点数存储。

    // 数据类型字节数
    void typeSize() {
        cout << sizeof(char) << endl;                // 1
        cout << sizeof(unsigned char) << endl;       // 1
        cout << sizeof(signed char) << endl;         // 1
        cout << sizeof(short) << endl;               // 2
        cout << sizeof(unsigned short) << endl;      // 2
        cout << sizeof(int) << endl;                 // 4
        cout << sizeof(unsigned int) << endl;        // 4
        cout << sizeof(long) << endl;                // 8
        cout << sizeof(unsigned long) << endl;       // 8
        cout << sizeof(long long) << endl;           // 8
        cout << sizeof(unsigned long long) << endl;  // 8
        cout << sizeof(float) << endl;               // 4
        cout << sizeof(double) << endl;              // 8
        cout << sizeof(long double) << endl;         // 16
        cout << sizeof(wchar_t) << endl;             // 2
        cout << sizeof(char16_t) << endl;            // 2
        cout << sizeof(char32_t) << endl;            // 4
        cout << sizeof(TmplClass<int, int>) << endl; // 12
    }

    // 使用{}初始化数字更严格，它不允许narrow，{}里面的值要是常量。

    // 强制类型转换的方式
    void forceTypeChange() {
        int x = (int) 3.2; // C风格
        int y = int(3.2); // C++风格
        int z = static_cast<int>(3.2);
        cout << x << endl;
        cout << y << endl;
        cout << z << endl;
    }

    // 自动类型推断，auto x = 1.2E12L; // long double

    // int arr[10] = {} // 数组所有元素初始化为0

    // 数组的初始化列表{}中不可缩窄转换。

    // 初始化string对象
    void initString() {
        string str{"hello"};
        cout << str << endl;
    }

    void diffGetGetline() {
        int x;
        cin >> x; // 换行符没有被吃掉
        char chs[5];
        cin.getline(chs, 5); // 以读到换行符结束，并消耗该换行符。
        cout << chs << endl;
        cin.clear();
    }

    // 结构
    struct Struct {
        int field;
        int field0;
    };

    struct Struct ss = {.field = 1, .field0 = 2}; // 可以省去struct关键字。不可缩窄转换。
    Struct s1{};                                  // 初始化为零值。

    // 匿名共用体
    void anonymousUnion() {
        struct Struct {
            union {
                int field;
                char field0;
            };
        };
        Struct sq{};
        sq.field = 1;
        cout << sq.field << endl;
    }

    // 使用指针前应当一同为其分配一个确定适当的地址。可以安全的delete一个空指针。
    void initPointer() {
        int *ptr = new int;
        *ptr = 123;
        cout << *ptr << endl
             << ptr << endl;
        delete ptr; // 释放由new分配的内存
    }

    // 动态分配数组
    void dynamicArray() {
        int *arr = new int[10];
        arr[1] = 999;
        int x = *(arr + 1); // 一次加一个int位宽
        cout << x << endl;
        delete[] arr;
    }

    // 运算符优先级
    void operatorPrecedence() {
        char arr[] = "abc";
        char *str = arr;
        char ch = *str++;
        cout << ch << *str << endl; // a b
    }

    // vector
    void useVector() {
        vector<int> vi;
        vector<double> vd(10); // 容量为10
        vd.assign(1, 1.2);
        cout << vd.at(0) << vd[0] << endl;
    }

    void useArray() {
        array<int, 3> ai = {1, 2, 3}; // 长度需要是常量不能是变量。
        const std::size_t x = 10;
        array<int, x> a{};
        cout << ai.size() << ai[0] << a[0] << endl;
    }

    // 输出打印布尔值
    void boolPrint() {
        cout << (1 > 1) << endl;
        cout.setf(ios_base::boolalpha);
        cout << (1 > 1) << endl; // false
    }

    // 使用ctime库实现等待休眠
    void wait() {
        int sec = 2;
        clock_t delay = sec * CLOCKS_PER_SEC;
        clock_t now = clock();
        while (clock() - now <= delay);
    }

    // 集合类for
    void especialForLoop() {
        int arr[10] = {};
        for (int i: arr)
            cout << i << endl;

        for (int &i: arr)
            cout << i << endl;
    }

    // cin忽略了空格和换行符，按回车时才将数据发送给程序
    void cinEscape() {
        int count = 0;
        char c = {};
        // cin >> c; // 换cin.get(c)获取空格，&ch表示函数能修改参数的值。
        // while (!cin.fail()) {
        while (cin.get(c)) {
            cout << c;
            count++;
            if (count > 2) break;
        }
        cout << count << endl;
    }

    void fileIO() {
        ofstream file;
        file.open("test.txt");
        file << "hello world" << endl;
        file.close();

        ifstream file0;
        file0.open("test.txt");
        if (!file0.is_open()) exit(EXIT_FAILURE);
        string s;
        while (file0 >> s) {
            cout << s;
        }
    }

    // 引用变量
    void refVar() {
        int x = 1;
        int &y = x;
        x = 10;
        std::cout << y;
    }

    // 指针加减
    void ptrAdd() {
        int arr[3] = {1, 2, 3};
        int *p1 = arr;
        int *p2 = &arr[2];
        std::cout << p2 - p1 << std::endl; // 2
    }

    // 函数模板，表达式参数可以提供默认值，类型参数不能。
    template<typename T> void tmplFun(T t) {
        std::cout << t << std::endl;
    }
    // 模板函数，一个函数模板的实例
    template void tmplFun<int>(int);

    // 函数的参数默认值
    void defaultVarFunc(int x, int y = 1, int z = 2) {
        std::cout << x << y << z << std::endl;
    }

    void classFieldPointer() {
        // 类的数据成员的指针
        int TmplClass<int, int>::*ptr = &TmplClass<int, int>::publicField;

        // 类的成员函数指针
        void (TmplClass<int, int>::*func)() = &TmplClass<int, int>::method;

        // 给对象c的pubField成员赋值
        TmplClass<int, int> c;
        c.*ptr = 1;
        std::cout << c.publicField << std::endl;

        // 给指针对象的成员赋值
        TmplClass<int, int> *c0 = &c;
        c0->*ptr = 2;
        std::cout << c.publicField << std::endl;

        // 调用函数成员指针
        (c.*func)();
        (c0->*func)();
    }

    void thisUsage() {
        class Class {
          public:
            int field;

            void method(Class &c) {
                *this = c;
            }

            explicit Class(int field) { this->field = field; }
        };
        Class c(1);
        Class c1(2);
        std::cout << c.field << std::endl;
        c.method(c1);
        std::cout << c.field << std::endl;
    }

    // 对象不能被更新
    // const Class<int, int> carr[2] = {};

    // 常引用
    void constRef() {
        TmplClass<int, int> x = {};
        const TmplClass<int, int> &a = x;
        // a.publicField = 1; // 非法
        cout << a.publicField << endl;
    }

    void constPtr() {
        const int var = 1;
        // int *ptr = &var; // 非法，const地址不能赋值给非const指针
        const int *ptr1 = &var;

        const int **pptr = &ptr1; // const作用于int。
        int *ptr0{};
        // pptr = &ptr0; // 非法，非const指针地址不能赋值给const指针
        cout << pptr << ptr0 << endl;
    }

    void testClass() {
        // 共享类成员
        TmplClass<int, int> c;
        TmplClass<int, int> c0;
        c.hasStaticMethod(1);  // 1
        c0.hasStaticMethod(1); // 2

        {
            // 自动调用构造函数
            TmplClass<int, int> c1;
            // 自动调用析构函数
        }

        // 构造函数
        TmplClass<int, int> c2(2);
        TmplClass<int, int> c3(c0);

        // 调用静态类成员
        std::cout << TmplClass<int, int>::staticField << std::endl;

        // 调用静态成员函数
        TmplClass<int, int>::staticMethod();

        // 调用友元函数
        friendMethod(c3);

        // 友元类
        FriendClass<int, int> c4;
        c4.friendClassMethod();

        // 局部类
        class InnerClass {
          public:
            // static int x; 不能定义静态成员
            void method() {};
        };
        InnerClass ic;
        ic.method();

        // 分配动态存储，调用构造函数
        auto pc = new TmplClass<int, int>(1);
        // 调用析构函数
        delete pc;

        // 运算符重写
        TmplClass<int, int> c5(0);
        c5 = 2;
        TmplClass<int, int> c50 = 3;

        // 类型转化函数
        TmplClass<int, int> c6(2);
        int x = (int) c6;
        cout << x << endl;

        const FatherClass &c7 = SonClass();

        SonClass c8;
        c8.FatherClass::method(); // 多继承二义性
    }

    // 友元函数重载
    void friendOverload() {
        TmplClass<int, int> c{};
        -c;
        std::cout << c.publicField;
    }

    void incrTest() {
        TmplClass<int, int> c;
        ++c;
        c.operator++();
    }

    void testVirtualMethod() {
        SonClass sc;
        // 须要是指针或者引用才能动态联编
        FatherClass &fc = sc;
        fc.virtualMethod();
    }

    void testPureVirtualMethod() {
        SonClass sc;
        FatherClass &fc = sc;
        fc.pureVirtualMethod();
    }

    // 域运算符使用全局变量
    void useGlobalVar() {
        printf("%d\n", ::fileVar);
    }

    extern int isAStaticVar;

    extern int externalVar;

    void testIsAStaticVar() {
        // printf("%d\n", isAStaticVar); // isAStaticVar 内部链接无法编译
        printf("%d\n", externalVar);
        // externalVar++; // error
        printf("%d\n", externalVar);
    }

    // 语言链接性
    extern "C" int printf(const char *, ...); // 使用C库的
    extern "C++" int printf_();               // 使用C++库的

    int *xx = new int;
    int *xx0 = new int(1);                                // 指针指向地址块为1 c++98
    int *xx1 = new int{1};                                // c++11
    int *xx2 = new int[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 0}; // c++11

    TmplClass<int, int> returnClass() {
        TmplClass<int, int> cl;
        return cl;
    }

    void classInit() {
        TmplClass<int, int> c = TmplClass<int, int>(1);
        TmplClass<int, int> c1 = c;

        SonClass cf(1);
        cf = SonClass(2); // 临时变量赋值

        // 先使用默认构造函数创建，再赋值
        SonClass arr[1] = {
                SonClass(1, std::string("ha")),
        };
    }

    // c++11 空指针
    int *p = nullptr;

    void testDecltype() {
        int z = 0;
        const int &x = z;
        decltype(x) y = z; // const int &y
        auto s = x;        // int s
        z = 1;
        std::cout << y << std::endl;
        std::cout << s << std::endl;

        int m = 1;
        decltype((m)) n = z; // int &
        n = 9;
        std::cout << z << std::endl;
    }

    void testCout() {
        const char *str0 = "abcabc";
        const char *str1 = "defdefdef";
        const char *str2 = "highig";
        std::size_t len = std::strlen(str1);
        std::cout << len << std::endl;
        std::cout.write(str1, len + 5) << std::endl; // def hig

        std::cout << std::setw(1) << std::endl;
    }

    void testCin() {
        char a[5];
        std::cin.get(a, 5, 'a');
        std::cout << a << std::endl;
        std::cout << std::cin.rdstate();
    }

    void test_fio() {
        struct data {
            int x;
            char y;
            std::string m;
        };
        data d{.x = 1, .y = 'a', .m = "hello"};
        std::ofstream fout(R"(C:\Users\v_ivfzhou\src\cpp\test.txt)");
        if (!fout.is_open()) std::exit(EXIT_FAILURE);
        fout.write((char *) (&d), sizeof(d));
        fout.close();

        std::ifstream fin(R"(C:\Users\v_ivfzhou\src\cpp\test.txt)");
        if (!fin.is_open()) std::exit(EXIT_FAILURE);

        d = {};
        fin.read((char *) (&d), sizeof(d));
        fin.close();

        std::cout << d.x << d.y << d.m << std::endl;
    }

    static void exit(int) {}

    void test_exit() {
        using namespace std;
        exit(1);
    }

    // -> 表示返回值类型
    auto fund() -> decltype(1) {
        return 1;
    }

    // 枚举定义，struct可换class
    enum struct EM {
        O
    };
    // 枚举使用
    EM c = EM::O;

    static void test_rv0(int &&z) {
        z++;
    }

    // 右值
    void test_rv() {
        int x = 1;
        int y = 2;
        int &&z = x + y;
        cout << z << endl;
        x = 4;
        y = 5;
        test_rv0(x+y);
        cout << z << endl;
    }

    static int &returnIntRef() {
        static int x = 1;
        std::cout << x << std::endl;
        return x;
    }

    void testAuto() {
        int x = 0;
        auto &y = returnIntRef();
        y = 2;
        returnIntRef();
        std::cout << y << std::endl;
    }

    template<typename F, typename ...Args> void variable_template(F &&f, Args &&...args) {
        f(std::forward<Args...>(args...));
    }

    void test_vt() {
        int x = 1;
        variable_template([&](int y) { std::cout << ++y << std::endl; }, x);
        std::cout << x << std::endl;
    }

}
