#ifndef GITEE_COM_IVFZHOU_CPP_FATHER_CLASS
#define GITEE_COM_IVFZHOU_CPP_FATHER_CLASS

namespace gitee::com::ivfzhou::cpp {
    class FatherClass {
    public:
        int publicField = 0;

        explicit FatherClass(int field = 0);

        // 虚函数，不能是 static，动态联编。
        virtual void virtualMethod();

        void constNonVirtualMethod() const;

        // 纯虚函数=接口，不能实例化。
        virtual void pureVirtualMethod() = 0;

        static void staticMethod();

        // 虚析构函数，delete 时使用动态联编，先调用子类析构。
        virtual ~FatherClass();
    };
}

#endif
