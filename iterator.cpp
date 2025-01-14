#include <vector>
#include <iostream>

namespace iterator  {
    void test() {
        std::vector<int>::iterator iter;
        std::vector<int> v;
        v.assign(1, 1);
        for (iter = v.begin(); iter != v.end(); iter++) {
            std::cout << *iter << std::endl;
        }
    }
}
