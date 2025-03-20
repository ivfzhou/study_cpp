#include <iostream>
#include <valarray>

namespace gitee::com::ivfzhou::cpp::valarray_usage {
    class TestClass {
      public:
        int x = 0;

        TestClass operator+=(const TestClass& tc) const {
            TestClass tc0;
            tc0.x = this->x + tc.x;
            return tc0;
        }

        friend std::ostream& operator<<(std::ostream& os, const TestClass& tc) { return os << tc.x; }
    };
}

void TestValarray() {
    using namespace gitee::com::ivfzhou::cpp::valarray_usage;
    std::valarray<TestClass> arr(3);
    arr[0].x = 1;
    std::cout << arr.sum() << std::endl;
}
