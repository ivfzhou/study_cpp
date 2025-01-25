#include <utility>

#include "MovementClass.hpp"

void TestMovementClass() {
    using namespace gitee::com::ivfzhou::cpp;

    MovementClass mc("abc");
    MovementClass mc1(std::move(mc)); // 调用移动复制构造。
}
