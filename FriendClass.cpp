#include <iostream>

template<typename T, typename E> void FriendClass<T, E>::friendClassMethod() {
    // 访问 c 的私有成员
    std::cout << c.privateField << std::endl;
}
