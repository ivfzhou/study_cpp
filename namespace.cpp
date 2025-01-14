namespace ns {
    int s;

    void afunc();
}

namespace ns { // 可多次定义同名命名空间
    int x;
}

namespace ns1 { // 可在另一个空间中实现
    void afunc() {}

    namespace ns2 {
    } // 可在内部定义名字空间
}

namespace ns3 { // 引用其它命名空间
    using ns::afunc;
    using namespace ns1::ns2;
}

// 命名空间别名
namespace ns4 = ns3;

// 匿名空间，内部链接，本文件里可见
namespace {
    int nvar;
}

// 调用空间内容语法
void test() {
    nvar = 9;
    // s = 9; // error
    ns::s = 9;
}
