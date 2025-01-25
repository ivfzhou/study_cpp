#include <memory>
#include <iostream>

namespace gitee::com::ivfzhou::cpp::smart_pointer {
    std::unique_ptr<int> getUp() {
        auto ptr = std::unique_ptr<int>(new int);
        *ptr = 10;
        return ptr;
    }

    void revUp(std::unique_ptr<int>& ptr) {
        std::cout << *ptr << std::endl;
    }
}

void TestSmartPointer() {
    using namespace gitee::com::ivfzhou::cpp::smart_pointer;
    std::unique_ptr<int> ptr1(new int); // unique_ptr 被销毁时，它所指向的对象也会被自动销毁。你不能复制或者赋值 unique_ptr，但是你可以移动它。
    std::shared_ptr<int> ptr2(new int); // 多个 shared_ptr 可以指向同一个对象，对象会在最后一个指向它的shared_ptr被销毁时自动销毁。
    auto ptr3 = ptr2;
    *ptr3 = 10;
    std::cout << *ptr2 << std::endl; // 10

    // 右值可以赋值。
    std::unique_ptr<int> ptr4 = std::unique_ptr<int>(new int);
    std::unique_ptr<int> ptr5 = getUp();
    std::cout << *ptr5 << std::endl;

    *ptr1 = 10;
    auto ptr6 = std::move(ptr1);
    std::cout << *ptr6 << std::endl;
    // *ptr1 = 10; // error

    std::unique_ptr<int[]> ptr11(new int[3]);
    revUp(ptr6);
}
