#include <iostream>

namespace gitee::com::ivfzhou::cpp::multiple_inheritance {
    class TestClass {
      public:
        TestClass() { std::cout << "TestClass" << std::endl; }

        TestClass(const TestClass& tc) { std::cout << "TestClass copy" << std::endl; }

        void overwrite() { std::cout << "TestClass overwrite" << std::endl; }
    };

    class TestClass0 : public virtual TestClass {
      public:
        TestClass0() { std::cout << "TestClass0" << std::endl; }

        TestClass0(TestClass& tc) : TestClass(tc) { std::cout << "TestClass0 constructor" << std::endl; }

      private:
        void overwrite() { std::cout << "TestClass overwrite" << std::endl; }
    };

    class TestClass1 : public virtual TestClass {
      public:
        TestClass1() { std::cout << "TestClass1" << std::endl; }

        TestClass1(TestClass& tc) : TestClass(tc) { std::cout << "TestClass1 constructor" << std::endl; }

        void overwrite() { std::cout << "TestClass1 overwrite" << std::endl; }
    };

    class TestClass2 : public TestClass {
      public:
        TestClass2() { std::cout << "TestClass2" << std::endl; }

        TestClass2(TestClass& tc) : TestClass(tc) { std::cout << "TestClass2 copy" << std::endl; }

        void overwrite() { std::cout << "TestClass2 overwrite" << std::endl; }
    };

    class TestClass3 : public TestClass0, public TestClass1, public TestClass2 {
      public:
        TestClass3() = default; // 虚基类从这里调用构造。

        TestClass3(TestClass& tc) : TestClass0(tc), TestClass1(tc) {}
    };
}

void TestMultipleInheritance() {
    using namespace gitee::com::ivfzhou::cpp::multiple_inheritance;
    TestClass3 tc;
    const TestClass& tc0 = static_cast<TestClass0>(tc);
    // TestClass &tc0 = tc; // ambiguous
    // tc.overwrite(); // ambiguous，与访问修饰符无关。
}

namespace gitee::com::ivfzhou::cpp::multiple_inheritance0 {
    class Worker {
        int a;

      public:
        Worker(int a);
    };

    class Singer : virtual public Worker {
        int b;

      public:
        Singer(int b, int a);
    };

    class Waiter : virtual public Worker {
        int c;

      public:
        Waiter(int c, int a);
    };

    class SingingWaiter : public Singer, public Waiter {
      public:
        SingingWaiter(int c, int b, int a);
    };

    Singer::Singer(int b, int a) : Worker(a), b(b) {}

    Worker::Worker(int a) : a(a) {}

    Waiter::Waiter(int c, int a) : Worker(a), c(c) {}

    // worker 是 virtual 所以可以在这里初始化，否则将调用默认构造函数。singer 和 waiter 中传递的 a 将不起作用
    SingingWaiter::SingingWaiter(int c, int b, int a) : Worker(a), Singer(b, a), Waiter(c, a) {}
}
