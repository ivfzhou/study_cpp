#ifndef SON_CLASS
#define SON_CLASS

#include <string>

#include "FatherClass.hpp"
#include "String.hpp"

// 类继承，多个逗号分割，
// public继承父类公有和保护成员
// protected继承父类公有和保护成员且变成保护
// private继承父类公有和保护成员且变成私有，默认
// virtual虚基类，解决多继承二义性。
class SonClass : virtual public FatherClass {
  public:
    int publicField = 0;

    String name;

    SonClass(int field = 0, const std::string &name = "");

    /* virtual父类方法是虚的，子类自动为虚 */ void virtualMethod();

    void method() const;

    virtual void pureVirtualMethod();

    ~SonClass();

    void staticMethod();
};

#endif
