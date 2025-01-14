#include <iostream>

#include "FatherClass.hpp"

FatherClass::FatherClass(int field) : publicField(field) {}

void FatherClass::virtualMethod() {
    std::cout << "FatherClass virtualMethod " << publicField << std::endl;
}

void FatherClass::method() const {
    std::cout << "FatherClass method " << publicField << std::endl;
}

// void FatherClass::pureVirtualMethod() {
//     std::cout << "FatherClass pureVirtualMethod " << publicField << std::endl;
// }

FatherClass::~FatherClass() {
    std::cout << "FatherClass deleted " << std::endl;
}

void FatherClass::staticMethod() {
    std::cout << "FatherClass staticMethod " << std::endl;
}
