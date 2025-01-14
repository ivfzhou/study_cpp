#include <iostream>

#include "SonClass.hpp"

// 子类构造函数，不给定默认调用父类无参构造
SonClass::SonClass(int field, const std::string &name) : FatherClass(field), publicField(field), name(name) {
    // 获取父类同名成员
    std::cout << "SonClass constructor " << FatherClass::publicField << std::endl;
}

void SonClass::virtualMethod() {
    std::cout << "SonClass virtualMethod " << this->publicField << std::endl;
}

void SonClass::method() const {
    std::cout << "SonClass method " << this->publicField << std::endl;
}

void SonClass::pureVirtualMethod() {
    // FatherClass::pureVirtualMethod();
    std::cout << "SonClass pureVirtualMethod " << this->publicField << std::endl;
}

SonClass::~SonClass() {
    std::cout << "SonClass deleted " << std::endl;
}

void SonClass::staticMethod() {
    std::cout << "SonClass staticMethod" << std::endl;
}

class DeepSonClass : public SonClass {
private:
    void virtualMethod() {
        std::cout << "DeepSonClass virtualMethod " << std::endl;
    }

public:
    virtual void otherMethod() {
        std::cout << "DeepSonClass otherMethod" << std::endl;
    }

    ~DeepSonClass() {
        std::cout << "DeepSonClass delete" << std::endl;
    }
};

class SSonClass : public DeepSonClass {
public:
    // 根据方法名覆盖
    void otherMethod() {
        std::cout << publicField << std::endl;
    }
};

void testClass() {
    FatherClass::staticMethod();
    FatherClass *fc = new SonClass(0, "");
    fc->pureVirtualMethod();
    delete fc;

    DeepSonClass *dsc = new SSonClass;
    dsc->otherMethod();
    delete dsc;
}
