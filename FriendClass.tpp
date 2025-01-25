#include <iostream>

#include "FriendClass.hpp"

namespace gitee::com::ivfzhou::cpp {
    template <typename T, typename E>
    void FriendClass<T, E>::friendClassMethod() {
        // 访问私有成员。
        std::cout << c.privateField << std::endl;
    }
}
