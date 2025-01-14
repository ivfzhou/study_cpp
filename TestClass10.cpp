namespace cn_ivfzhou_cpp {
    class TestClass10 {
      public:
        // 析构函数定义成抽象的
        // virtual ~TestClass10() = 0;
    };

    class TestClass11 : public TestClass10 {};

    class TestClass12 : public TestClass10 {};

    class TestClass13 : public TestClass11, public TestClass12 {};
}

// 抽象析构函数实现
// cn_ivfzhou_cpp::TestClass10::~TestClass10() {}

void TestC() {
    cn_ivfzhou_cpp::TestClass13 t13;
    // cn_ivfzhou_cpp::TestClass10 *t10 = &t13; // t13有两个基类，不能赋值，须强转
    cn_ivfzhou_cpp::TestClass10 *t10 = (cn_ivfzhou_cpp::TestClass11 *) &t13;
}
