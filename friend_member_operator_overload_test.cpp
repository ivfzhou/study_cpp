#include <iostream>

#include "friend_member_operator_overload.hpp"

using namespace gitee::com::ivfzhou::cpp::friend_member_operator_overload;

void TestFriendMemberOperatorOverload() {
    TestClass tc;
    TestClass tc0 = tc + 1;
    std::cout << "tc0 is" << tc0 << std::endl;
    TestClass tc1 = 1 + tc0;
    std::cout << "tc1 is " << tc1 << std::endl;
}
