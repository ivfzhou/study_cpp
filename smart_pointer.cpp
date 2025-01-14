#include <memory>
#include <iostream>

namespace smart_pointer {

    std::unique_ptr<int> get_up() {
        auto ptr = std::unique_ptr<int>(new int);
        *ptr = 10;
        return ptr;
    }

    void rev_up(std::unique_ptr<int> &ptr) {
        std::cout << *ptr << std::endl;
    }

    void test() {
        std::unique_ptr<int> ptr_i(new int);
        std::shared_ptr<int> ptr_j(new int);
        auto ptr_k = ptr_j;
        *ptr_k = 10;
        std::cout << *ptr_j << std::endl; // 10

        // 右值可以赋值
        std::unique_ptr<int> ptr_z = std::unique_ptr<int>(new int);
        std::unique_ptr<int> ptr_d = get_up();
        std::cout << *ptr_d << std::endl;

        *ptr_i = 10;
        auto ptr_v = std::move(ptr_i);
        std::cout << *ptr_v << std::endl;
        // *ptr_i = 10; error

        std::unique_ptr<int[]> ptr_g(new int[3]);

        rev_up(ptr_v);
    }
}
