#include <FatherClass.hpp>
#include <SonClass.hpp>

using namespace gitee::com::ivfzhou::cpp;

void TestSonClass() {
    {
        // FatherClass father; 无法编译。
    }

    {
        FatherClass* father = new SonClass;
        father->pureVirtualMethod(); // 调的子类方法。
        delete father;
    }

    std::cout << std::endl << "===" << std::endl << std::endl;

    {
        FatherClass* father = new SonClass;
        father->constNonVirtualMethod(); // 调的父类方法。
        delete father;
    }

    std::cout << std::endl << "===" << std::endl << std::endl;

    {
        FatherClass* father = new SonClass;
        father->staticMethod(); // 调的父类方法。
        delete father;
    }

    std::cout << std::endl << "===" << std::endl << std::endl;

    {
        GrandsonClass* grandson = new GreatGrandsonClass;
        grandson->otherMethod(); // 调用的子类方法。
        delete grandson;
    }
}
