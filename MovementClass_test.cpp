#include <utility>

#include "MovementClass.hpp"

void TestMovementClass() {
    using namespace gitee::com::ivfzhou::cpp;

    MovementClass mc("abc");
    MovementClass mc1(std::move(mc)); // 调用移动构造。

    MovementClass m3;
    m3 = std::move(mc1); // 调用移动运算符。
}
