#ifndef GITEE_COM_IVFZHOU_CPP_SON_CLASS
#define GITEE_COM_IVFZHOU_CPP_SON_CLASS

#include <string>

#include "FatherClass.hpp"
#include "String.hpp"

namespace gitee::com::ivfzhou::cpp {
    // 类继承，多个逗号分割，
    // public 继承父类公有和保护成员。
    // protected 继承父类公有和保护成员且变成保护。
    // private 继承父类公有和保护成员且变成私有，默认。
    // virtual 虚基类，解决多继承二义性。
    class SonClass : virtual public FatherClass {
    public:
        int publicField = 0;

        String name;

        explicit SonClass(int field = 0, const std::string& name = "");

        // 父类方法是虚的，子类自动为虚。
        // 需要是指针或者引用才能动态联编。
        void virtualMethod() override;

        void constNonVirtualMethod() const;

        void pureVirtualMethod() override;

        void staticMethod();

        ~SonClass() override;
    };

    class GrandsonClass : public SonClass {
        void virtualMethod() override;

    public:
        virtual void otherMethod();

        ~GrandsonClass() override;
    };

    class GreatGrandsonClass final : public GrandsonClass {
        // 根据方法名覆盖。
        void otherMethod() override;
    };
}

#endif
