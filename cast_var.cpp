#include <iostream>

namespace cast_var {

    static void add(const int *ptr_x, int delta) {
        int *ptr_x_c = const_cast<int *>(ptr_x);
        *ptr_x_c += delta;
    }

    void testCVT() {
        // const_cast<>去除变量的const，但不能改变真const变量的值。
        {
            const int x = 20;
            int y = 20;
            add(&x, 10);
            add(&y, 10);
            std::cout << x << std::endl;
            std::cout << y << std::endl;
        }

        // static_cast
        {
            float x = 1.1;
            int y = static_cast<int>(x);
            std::cout << y << std::endl; // 1

            enum {
                One
            };
            int z = static_cast<int>(One);
            std::cout << z << std::endl;

            int m = 10;
            void *ptr = &m;
            int *n = static_cast<int *>(ptr);
            std::cout << *n << std::endl;

            class Base {};
            class Derived : public Base {};
            Base b;
            auto d = static_cast<Derived>(b);
            std::cout << typeid(d).name() << std::endl;
        }

        // reinterpret_cast
        {
            struct Data {
                char x;
                char y;
                char z;
                char m;
            };
            Data d = {.x = 0, .y = 0, .z = 0, .m = 1};
            int *x = reinterpret_cast<int *>(&d);
            std::cout << x << std::endl;
            std::cout << *x << std::endl;
        }

        // volatile_cast __unaligned_cast
    }

}
