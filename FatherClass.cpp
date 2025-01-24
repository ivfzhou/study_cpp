#include <iostream>

#include "FatherClass.hpp"

namespace gitee::com::ivfzhou::cpp {
    FatherClass::FatherClass(int field) : publicField(field) {}

    void FatherClass::virtualMethod() {
        std::cout << "FatherClass::virtualMethod " << publicField << std::endl;
    }

    void FatherClass::constNonVirtualMethod() const {
        std::cout << "FatherClass::constNonVirtualMethod " << publicField << std::endl;
    }

    void FatherClass::pureVirtualMethod() {
        std::cout << "FatherClass::pureVirtualMethod " << publicField << std::endl;
    }

    void FatherClass::staticMethod() {
        std::cout << "FatherClass::staticMethod " << std::endl;
    }

    FatherClass::~FatherClass() {
        std::cout << "~FatherClass " << std::endl;
    }
}
