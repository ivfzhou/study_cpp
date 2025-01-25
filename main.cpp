#include <iostream>
#include <fstream>
#include <vector>
#include <array>
#include <ctime>
#include <cstring>
#include <iomanip>
#include <MovementClass.hpp>

#include "TemplateClass.hpp"
#include "FatherClass.hpp"
#include "SonClass.hpp"
#include "FriendClass.hpp"

extern void TestAssignmentCopyOperation();

extern void TestCastVariable();

extern void TestUniversalCharacterName();

extern void TestWideCharacter();

extern void TestRawString();

extern void TestCertainLengthCharacters();

extern void TestException();

extern void TestFriendMemberOperatorOverload();

extern void TestSonClass();

extern void TestString();

extern void TestNamespace();

extern void TestPrivateExtend();

extern void TestRuntimeTypeIdentification();

extern void TestTemplateClass();

extern void TestTemplate();

extern void TestTemplateStaticMember();

extern void TestValarray();

extern void TestVariableArgument();

extern void TestMemberInitializerList();

extern void TestMultipleInheritance();

extern void TestSmartPointer();

extern void TestUpcast();

extern void TestOverrideMethod();

extern void TestTypename();

extern void TestMovementClass();

static void testConstantPointerAssignment() {
    const int x = 1;
    // int* ptr = &x; // 取址常量变量不能赋值给非 const 指针。
    const int* ptr1 = &x;
    std::cout << *ptr1 << std::endl;

    const int** ptr2;
    int* ptr3;
    // ptr2 = &ptr3; // 常量的指针的指针，赋值也要是常量的指针。
    const int* ptr4;
    ptr2 = &ptr4;
}

static void testLambdaUsage() {
    int y = 1;
    auto fn = [&](int x) {
        y = x;
    };
    fn(1234);
    std::cout << y << std::endl;
}

static void testIterator() {
    std::vector<int> v;
    v.assign(1, 1);
    for (const int& iter : v) {
        std::cout << iter << std::endl;
    }

    std::vector<int>::iterator iter;
    for (iter = v.begin(); iter != v.end(); iter++) {
        std::cout << *iter << std::endl;
    }
}

static void testLocateNew() {
    class TestClass {
    public:
        ~TestClass() {
            std::cout << "~TestClass" << std::endl;
        }
    };

    char* buf = new char[1024];
    auto tc = new(buf) TestClass;
    auto tc0 = new(buf + sizeof(TestClass)) TestClass;
    // delete tc; // error
    tc->~TestClass(); // 需要手动调用析构。
    tc0->~TestClass();
    delete[] buf;
}

static void testMacro() {
    #define FN(name) \
        std::string name = "abc"; \
        std::cout << name << std::endl;

    FN(variableName);

    std::cout << variableName << std::endl;
}

static void testNew() {
    int* ptr = new int[3]; // 没有初始化元素。
    for (int i = 0; i < 3; i++) {
        std::cout << ptr[i] << std::endl;
    }
    delete[] ptr;
    int* ptr1 = new int[3](); // 元素都是零值。
    for (int i = 0; i < 3; i++) {
        std::cout << ptr1[i] << std::endl;
    }
    delete[] ptr1;
}

using namespace gitee::com::ivfzhou::cpp;

static void testInitialization() {
    // 多种初始化方式。
    int n(5);
    std::cout << "n is " << n << std::endl;
    int x{};
    std::cout << "x is " << x << std::endl;
    int y{5};
    std::cout << "y is " << y << std::endl;
    int z = {5};
    std::cout << "x is " << z << std::endl;

    int arr[1][2] = {1, 2}; // 两个元素的数组，每个元素为 int[1]。
    int (*ptr)[2](arr);
    std::cout << "ptr is " << ptr << std::endl;

    TemplateClass<int, int> c0 = {1}; // 调用构造函数。
    TemplateClass<int, int> c1{1}; // 调用构造函数。
    TemplateClass<int, int> c2 = 1; // 一个参数的构造函数允许此法使用。
    TemplateClass<int, int> arr0[5] = {
        // 先使用默认构造函数创建，再赋值。
        TemplateClass<int, int>(1),
        // 剩下的元素使用默认构造函数。
    };
    std::cout << "c0 is " << c0 << std::endl;
    std::cout << "c1 is " << c1 << std::endl;
    std::cout << "c2 is " << c2 << std::endl;
    std::cout << "arr0[0] is " << arr0[0] << std::endl;
}

// cout 提供的控制符
static void testCoutControl() {
    int n = 32;
    std::cout << std::hex << n << std::endl; // 0x20
    std::cout << std::dec << n << std::endl; // 32
    std::cout << std::oct << n << std::endl; // 40

    std::cout << (1 > 1) << std::endl;
    std::cout.setf(std::ios_base::boolalpha);
    std::cout << (1 > 1) << std::endl; // false

    const char* str0 = "abcabc";
    const char* str1 = "defdefdef";
    const char* str2 = "highig";
    std::size_t len = std::strlen(str1);
    std::cout << len << std::endl;
    std::cout.write(str1, len + 5) << std::endl; // def hig

    std::cout << std::setw(1) << std::endl;
}

static void testUsing() {
    using std::printf;
    printf("\n");
}

// 布尔类型：
static bool t = true;
static bool f = false;

// 使用 const 值声明数组长度。
static void testConstantArrayLength() {
    const int l = 10;
    int arr[l] = {};
    std::cout << arr[9] << std::endl;
}

// 数据类型字节数
static void testTypeSize() {
    std::cout << sizeof(char) << std::endl; // 1
    std::cout << sizeof(unsigned char) << std::endl; // 1
    std::cout << sizeof(signed char) << std::endl; // 1
    std::cout << sizeof(short) << std::endl; // 2
    std::cout << sizeof(unsigned short) << std::endl; // 2
    std::cout << sizeof(int) << std::endl; // 4
    std::cout << sizeof(unsigned int) << std::endl; // 4
    std::cout << sizeof(long) << std::endl; // 8
    std::cout << sizeof(unsigned long) << std::endl; // 8
    std::cout << sizeof(long long) << std::endl; // 8
    std::cout << sizeof(unsigned long long) << std::endl; // 8
    std::cout << sizeof(float) << std::endl; // 4
    std::cout << sizeof(double) << std::endl; // 8
    std::cout << sizeof(long double) << std::endl; // 16
    std::cout << sizeof(wchar_t) << std::endl; // 2
    std::cout << sizeof(char16_t) << std::endl; // 2
    std::cout << sizeof(char32_t) << std::endl; // 4
    std::cout << sizeof(TemplateClass<int, int>) << std::endl; // 32
}

// 强制类型转换的方式
static void testForceTypeCast() {
    int x = (int)3.2; // C风格。
    int y = int(3.2); // C++风格。
    int z = static_cast<int>(3.2);
    std::cout << x << std::endl;
    std::cout << y << std::endl;
    std::cout << z << std::endl;
}

// 自动类型推断：
static auto x = 1.2E12L; // long double

static void testDiffGetGetline() {
    int x;
    std::cin >> x; // 换行符没有被吃掉。
    char chs[5];
    std::cin.getline(chs, 5); // 以读到换行符结束，并消耗该换行符。
    std::cout << chs << std::endl;
    std::cin.clear();

    char a[5];
    std::cin.get(a, 5, 'a');
    std::cout << a << std::endl;
    std::cout << std::cin.rdstate();
}

// cin 忽略了空格和换行符，按回车时才将数据发送给程序。
static void testCinEscape() {
    int count = 0;
    char c = {};
    // std::cin >> c; // 换 std::cin.get(c) 获取空格，&ch 表示函数能修改参数的值。
    // while (!std::cin.fail()) {
    while (std::cin.get(c)) {
        std::cout << c;
        count++;
        if (count > 2) break;
    }
    std::cout << count << std::endl;
}

static void testFileInputOutput() {
    std::ofstream file;
    file.open("test.txt");
    file << "hello world" << std::endl;
    file.close();

    std::ifstream file0;
    file0.open("test.txt");
    if (!file0.is_open()) exit(EXIT_FAILURE);
    std::string s;
    while (file0 >> s) {
        std::cout << s;
    }

    struct data {
        int x;
        char y;
        std::string m;
    };
    data d{.x = 1, .y = 'a', .m = "hello"};
    std::ofstream fout(R"(test.txt)");
    if (!fout.is_open()) std::exit(EXIT_FAILURE);
    fout.write((char*)(&d), sizeof(d));
    fout.close();

    std::ifstream fin(R"(test.txt)");
    if (!fin.is_open()) std::exit(EXIT_FAILURE);

    d = {};
    fin.read((char*)(&d), sizeof(d));
    fin.close();

    std::cout << d.x << d.y << d.m << std::endl;
}

struct S {
    int field;
    int field0;
};

struct S s = {.field = 1, .field0 = 2}; // 可以省去 struct 关键字。不可缩窄转换。
S s1{}; // 初始化为零值。

// 动态分配数组
static void testDynamicArray() {
    int* arr = new int[10];
    arr[1] = 999;
    int x = *(arr + 1); // 一次加一个 int 位宽。
    std::cout << x << std::endl;
    delete[] arr;
}

// 运算符优先级。
static void testOperatorPrecedence() {
    char arr[] = "abc";
    char* str = arr;
    char ch = *str++;
    std::cout << ch << *str << std::endl; // a b
}

static void testUseVector() {
    std::vector<int> vi;
    std::vector<double> vd(10); // 容量为 10。
    vd.assign(1, 1.2);
    std::cout << vd.at(0) << vd[0] << std::endl;
}

static void testUseArray() {
    std::array<int, 3> ai = {1, 2, 3}; // 长度需要是常量不能是变量。
    const std::size_t x = 10;
    std::array<int, x> a{};
    std::cout << ai.size() << ai[0] << a[0] << std::endl;
}

// 使用 ctime 库实现等待休眠。
static void testWaitTime() {
    int sec = 2;
    clock_t delay = sec * CLOCKS_PER_SEC;
    clock_t now = clock();
    while (clock() - now <= delay);
}

// 集合类 for。
static void testEspecialForLoop() {
    int arr[10] = {};
    for (int i : arr) std::cout << i << std::endl;

    for (int& i : arr) std::cout << i << std::endl;
}

// 引用变量。
static void testReferenceVariable() {
    int x = 1;
    int& y = x;
    x = 10;
    std::cout << y;
}

// 常量引用。
void testConstReference() {
    TemplateClass<int, int> x = {};
    const TemplateClass<int, int>& a = x;
    // a.publicField = 1; // 非法。
    std::cout << a.publicField << std::endl;
}

// 函数模板，表达式参数可以提供默认值，类型参数不能。
template <typename T>
static void testTemplateFunction(T t) {
    std::cout << t << std::endl;
}

// 模板函数，一个函数模板的实例。
template void testTemplateFunction<int>(int);

// 函数的参数默认值
static void testDefaultVariableFunction(int x, int y = 1, int z = 2) {
    std::cout << x << y << z << std::endl;
}

static void testClassFieldPointer() {
    // 类的数据成员的指针。
    int TemplateClass<int, int>::* ptr = &TemplateClass<int, int>::publicField;

    // 类的成员函数指针。
    void (TemplateClass<int, int>::*func)() = &TemplateClass<int, int>::method;

    // 给对象 c 的 pubField 成员赋值。
    TemplateClass<int, int> c;
    c.*ptr = 1;
    std::cout << c.publicField << std::endl;

    // 给指针对象的成员赋值。
    TemplateClass<int, int>* c0 = &c;
    c0->*ptr = 2;
    std::cout << c.publicField << std::endl;

    // 调用函数成员指针。
    (c.*func)();
    (c0->*func)();
}

// 对象不能被更新：
const TemplateClass<int, int> carr[2] = {};

static int fileVar;

// 域运算符使用全局变量：
static void testUseGlobalVar() {
    printf("%d\n", ::fileVar);
}

// c++11 空指针：
int* p = nullptr;

// 语言链接性。
extern "C" int your_linked_function(const char*, ...); // 使用 C 库的。告诉编译器如何处理在其后声明的函数或变量的链接。

static void testClass() {
    // 共享类成员。
    TemplateClass<int, int> c;
    TemplateClass<int, int> c0;
    c.hasStaticMethod(1); // 1
    c0.hasStaticMethod(1); // 2

    {
        // 自动调用构造函数。
        TemplateClass<int, int> c1;
        // 自动调用析构函数。
    }

    // 构造函数。
    TemplateClass<int, int> c2(2);
    TemplateClass<int, int> c3(c0);

    // 调用静态类成员。
    std::cout << TemplateClass<int, int>::staticField << std::endl;

    // 调用静态成员方法。
    TemplateClass<int, int>::staticMethod();

    // 调用友元函数。
    friendMethod(c3);

    // 友元类。
    FriendClass<int, int> c4;
    c4.friendClassMethod();

    // 局部类。
    class InnerClass {
    public:
        // static int x; 不能定义静态成员。
        void method() {
        };
    };
    InnerClass ic;
    ic.method();

    // 分配动态存储，调用构造函数。
    auto pc = new TemplateClass<int, int>(1);
    // 调用析构函数。
    delete pc;

    // 运算符重写。
    TemplateClass<int, int> c5(0);
    c5 = 2;
    TemplateClass<int, int> c50 = 3;

    // 类型转化函数。
    TemplateClass<int, int> c6(2);
    int x = (int)c6;
    std::cout << x << std::endl;

    const FatherClass& c7 = SonClass();

    SonClass c8;
    c8.FatherClass::virtualMethod(); // 多继承二义性。
}

// -> 表示返回值类型
auto decltypeFunction() -> decltype(1) {
    return 1;
}

static void testDecltype() {
    int z = 0;
    const int& x = z;
    decltype(x) y = z; // const int &y
    auto s = x; // int s
    z = 1;
    std::cout << y << std::endl;
    std::cout << s << std::endl;

    int m = 1;
    decltype((m)) n = z; // int&。如果表达式被括号包围，那么 decltype 会得到该表达式的引用类型。
    n = 9;
    std::cout << z << std::endl;
}

template <typename F, typename... Args>
void testVariableTemplateFunction(F&& f, Args&&... args) {
    f(std::forward<Args...>(args...));
}

static void testStdForward() {
    int x = 1;
    testVariableTemplateFunction([&](int y) { std::cout << ++y << std::endl; }, x);
    std::cout << x << std::endl;
}

// 右值，是一个临时的、非持久的值。不可寻址，可以绑定到右值引用。不能绑定到左值引用，除非是常量左值引用。
static void testRightValue() {
    int x = 1;
    int y = 2;
    int&& z = x + y;
    std::cout << z << std::endl;
    x = 4;
    y = 5;
    std::cout << z << std::endl; // 3
}

template <typename T>
static typename std::remove_reference<T>::type&& move(T&& x) {
    x++;
    return static_cast<typename std::remove_reference<T>::type&&>(x);
}


// 函数右值引用的形参，可以接收右值、左值、右值引用和左值引用类型的实参。
// 函数返回值类型为右值引用，可以用左值、右值引用和左值引用类型的实参。
static void testCommonReference() {
    int x = 1;
    move<int&>(x); // 传递左值引用。
    std::cout << x << std::endl; // 被修改了。

    int& y = x;
    move<int&>(y); // 传递左值引用。
    std::cout << x << std::endl; // 被修改了。

    int&& k = 1 + 1;
    move(k); // 右值引用。
    std::cout << k << std::endl; // 被修改了。

    move<int&&>(1 + 1); // 右值。

    int&& z = move(x); // 右值引用接收。
    std::cout << z << std::endl; // 修改的变量的值接收到了。
    x++;
    std::cout << z << std::endl; // 修改的变量接收到了。

    const int& m = move(x); // 常量左值引用接收。
    std::cout << m << std::endl; // 修改的变量的值接收到了。
    x++;
    std::cout << m << std::endl; // 修改的变量接收到了。

    int n = move(x); // 左值接收。
    std::cout << n << std::endl; // 修改的变量的值接收到了。
    x++;
    std::cout << n << std::endl; // 修改的变量没有接收到了。n 是副本。
}

static void testRightValueToLeft() {
    int x = 1;
    int& y = x;
    int&& z = y + x;
    int& m = z;
    z++;
    std::cout << m << std::endl;
}

int main(const int argv, const char* argc[]) {
    TestMovementClass();
    std::cout << "OK 完成" << std::endl;
    return 0;
}
