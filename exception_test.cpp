#include <exception>
#include <iostream>

static int exception_message = 1;

static int divide(int x, int y) {
    if (y == 0) throw exception_message;
    return x / y;
}

// 关键字表示不会出现异常。
static void nonThrowFunction() noexcept {}

static void terminateHandler() { std::cout << "exit" << std::endl; }

void TestException() {
    std::set_terminate(terminateHandler);
    try {
        divide(1, 0);
    } catch (const char* msg) {
        // 按顺序匹配。
        std::cout << msg << std::endl;
    } catch (int& e) {
        e = e + 1;
        std::cout << "catch int&, exception_message is " << exception_message << std::endl; // 1
    } catch (int* err) {
        *err = *err + 1;
        std::cout << "catch int*, exception_message is " << exception_message << std::endl; // 2
    } catch (...) {
        // 捕获所有异常。
    }

    int* ptr = new (std::nothrow) int[9999999999999999];
    if (!ptr) {
        std::cout << "failed to new" << std::endl;
    }
}
