#include <iostream>

#include "SonClass.hpp"

namespace gitee::com::ivfzhou::cpp {
    // 子类构造函数，不给定默认调用父类无参构造。
    SonClass::SonClass(int field, const std::string& name) : FatherClass(field), publicField(field), name(name) {
        // 获取父类同名成员。
        std::cout << "SonClass field, name, FatherClass::publicField is " << FatherClass::publicField << std::endl;
    }

    void SonClass::virtualMethod() {
        std::cout << "SonClass::virtualMethod " << publicField << std::endl;
    }

    void SonClass::constNonVirtualMethod() const {
        std::cout << "SonClass::constNonVirtualMethod " << publicField << std::endl;
    }

    void SonClass::pureVirtualMethod() {
        std::cout << "SonClass::pureVirtualMethod " << publicField << std::endl;
    }

    SonClass::~SonClass() {
        std::cout << "~SonClass" << std::endl;
    }

    void SonClass::staticMethod() {
        std::cout << "SonClass::staticMethod" << std::endl;
    }

    void GrandsonClass::virtualMethod() {
        std::cout << "GrandsonClass::virtualMethod " << std::endl;
    }

    void GrandsonClass::otherMethod() {
        std::cout << "GrandsonClass::otherMethod" << std::endl;
    }

    GrandsonClass::~GrandsonClass() {
        std::cout << "~GrandsonClass" << std::endl;
    }

    void GreatGrandsonClass::otherMethod() {
        std::cout << "GreatGrandsonClass::otherMethod " << publicField << std::endl;
    }
}
