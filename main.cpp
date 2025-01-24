#include <iostream>

static void testConstantPointerAssignment() {
    const int x = 1;
    // int* ptr = &x; // 取址常量变量不能赋值给非 const 指针。
    const int* ptr1 = &x;
    std::cout << *ptr1 << std::endl;

    const int** ptr2;
    int* ptr3;
    // ptr2 = &ptr3; // 常量的指针的指针，赋值也要是常量的指针。
    const int* ptr4;
    ptr2 = &ptr4;
}

static void testLambdaUsage() {
    int y = 1;
    auto fn = [&](int x) {
        y = x;
    };
    fn(1234);
    std::cout << y << std::endl;
}

int main(const int argv, const char* argc[]) {
    testLambdaUsage();
    std::cout << "OK 完成" << std::endl;
    return 0;
}
