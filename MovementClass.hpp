#ifndef GITEE_COM_IVFZHOU_CPP_MOVEMENT_CLASS
#define GITEE_COM_IVFZHOU_CPP_MOVEMENT_CLASS

namespace gitee::com::ivfzhou::cpp {
    class MovementClass {
        char* data = nullptr;

    public:
        MovementClass() = default;

        explicit MovementClass(const char*);

        // 移动复制构造方法，默认提供。
        MovementClass(MovementClass&&) noexcept;

        // 移动赋值运算符，默认提供。
        MovementClass& operator=(MovementClass&&) noexcept;

        ~MovementClass() {
            delete[] data;
        };
    };
}

#endif
