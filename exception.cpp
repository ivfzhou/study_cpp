#include <iostream>
#include <exception>

namespace exception {
    static int exp = 1;

    static int divide(int x, int y) {
        if (y == 0) throw &exp;
        return x / y;
    }

    // 关键字表示不会出现异常
    static void fn() noexcept {}

    static void terminateHandler() {
        std::cout << "exit" << std::endl;
    }

    static const char *str() {
        // char cs[] = {'a', 'b', 'c', '\0'};
        // char *cs = "abc";
        return "abc";
    }

    void test() {
        std::set_terminate(terminateHandler);
        try {
            divide(1, 0);
        } catch (const char *msg) { // 按顺序匹配
            std::cout << msg << std::endl;
        } catch (int &e) {
            e++;
            std::cout << exp << std::endl; // 1
        } catch (...) { // 捕获所有异常

        }

        std::cout << str() << std::endl;

        int *ptr = new(std::nothrow) int[9999999999999999];
        if (!ptr) {
            std::cout << "fail" << std::endl;
        }
    }

}
