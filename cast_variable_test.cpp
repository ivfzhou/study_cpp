#include <iostream>

static void add(const int* ptr, int delta) {
    int* ptr1 = const_cast<int*>(ptr);
    *ptr1 += delta;
    std::cout << "*ptr1 is " << *ptr1 << std::endl;
}

void TestCastVariable() {
    // const_cast<> 去除变量的 const，但不能改变真 const 变量的值。
    {
        const int x = 20;
        int y = 20;
        add(&x, 10);
        add(&y, 10);
        std::cout << "x is " << x << std::endl;
        std::cout << "y is " << y << std::endl;
    }

    // static_cast
    {
        float x = 1.1;
        int y = static_cast<int>(x);
        std::cout << "y is " << y << std::endl; // 1

        enum {
            One
        };
        int z = static_cast<int>(One);
        std::cout << "z is " << z << std::endl;

        int m = 10;
        void* ptr = &m;
        int* n = static_cast<int*>(ptr);
        std::cout << "*n is " << *n << std::endl;

        class Base {};
        class Derived : public Base {};
        Base b;
        Derived d = static_cast<Derived>(b);
        std::cout << "typeid(d).name() is " << typeid(d).name() << std::endl;
    }

    // dynamic_cast
    {
        class Base {
        public:
            virtual ~Base() {}
        };
        class Derived : public Base {
        public :
            Derived() {}
        };
        Base* base = new Derived();
        Derived* derived = dynamic_cast<Derived*>(base);
        std::cout << "typeid(derived).name() is " << typeid(derived).name() << std::endl;
        delete base;
    }

    // reinterpret_cast
    {
        struct Data {
            int x;
            char y;
            char z;
            char m;
        };
        Data data = {.x = 1, .y = 2, .z = 3, .m = 4};
        int* x = reinterpret_cast<int*>(&data);
        std::cout << "x is " << x << std::endl;
        std::cout << "*x is " << *x << std::endl;
    }
}
