namespace gitee::com::ivfzhou::cpp::upcast_test {
    class TestClass {
    public:
        // 析构函数定义成抽象的
        virtual ~TestClass() = 0;
    };

    class TestClass1 : public TestClass {};

    class TestClass2 : public TestClass {};

    class TestClass3 : public TestClass1, public TestClass2 {};

    // 抽象析构函数实现
    TestClass::~TestClass() = default;
}

void TestUpcast() {
    using namespace gitee::com::ivfzhou::cpp::upcast_test;
    TestClass3 t13;
    // TestClass *t10 = &t13; // t13 有两个基类，不能赋值，须强转。
    TestClass* t10 = static_cast<TestClass1*>(&t13);
}
