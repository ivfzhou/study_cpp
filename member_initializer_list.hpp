#ifndef MEMBER_INITIALIZER_LIST
#define MEMBER_INITIALIZER_LIST

namespace member_initializer_list {
    class TestClass {
      private:
        int x = 0; // 相当于初始化列表
        const int y = 10;

      public:
        explicit TestClass(int);

        int getY() const { return y; }

        int getX() const { return x; }
    };
}

#endif
