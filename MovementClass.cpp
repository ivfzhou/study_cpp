#include <cstring>
#include <iostream>

#include "MovementClass.hpp"

namespace gitee::com::ivfzhou::cpp {
    MovementClass::MovementClass(const char* s) {
        data = new char[std::strlen(s)];
        std::memcpy(data, s, std::strlen(s));
        std::cout << "MovementClass(const char*)" << std::endl;
    }

    MovementClass::MovementClass(MovementClass&& mc) noexcept : data(mc.data) {
        mc.data = nullptr;
        std::cout << "MovementClass(&&)" << std::endl;
    }

    MovementClass& MovementClass::operator=(MovementClass&& mc) noexcept {
        std::cout << "MovementClass::operator=" << std::endl;
        if (this == &mc) return *this;
        delete data;
        data = mc.data;
        mc.data = nullptr;
        return *this;
    }
}
