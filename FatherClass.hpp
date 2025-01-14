#ifndef FATHER_CLASS
#define FATHER_CLASS

class FatherClass {
  public:
    int publicField = 0;

    explicit FatherClass(int field = 0);

    // 虚函数，不能是 static，动态联编
    virtual void virtualMethod();

    void method() const;

    // 纯虚函数=接口，不能实例化
    virtual void pureVirtualMethod() = 0;

    // 虚析构函数，delete 时使用动态联编，调用子类析构。
    virtual ~FatherClass();

    static void staticMethod();
};

#endif
