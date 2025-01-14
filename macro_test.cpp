#include <iostream>

#define FN(name) \
    std::string name = "abc"; \
    std::cout << name << std::endl;

namespace macro_test {
    void test() {
        FN(var);
    }
}
