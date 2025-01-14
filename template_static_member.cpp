#include <iostream>

namespace template_static_member {
    template<typename T> class TestClass {
        static int count;
      public :

        TestClass() {
            std::cout << ++count << std::endl;
        }
    };

    template<typename T> int TestClass<T>::count = 0;

    // 具体化，每一个特定的具体化都有自己的静态成员
    template<> class TestClass<int> {
        static int count;
      public :
        TestClass() {
            std::cout << "具体化" << std::endl;
            std::cout << ++count << std::endl;
        }
    };

    int TestClass<int>::count = 0;

    void test() {
        TestClass<int> c1;
        TestClass<double> c2;
        TestClass<int> c3;
    }
}
