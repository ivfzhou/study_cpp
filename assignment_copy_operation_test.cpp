#include "assignment_copy_operation.hpp"

using namespace gitee::com::ivfzhou::cpp::assignment_copy_operation;

void TestAssignmentCopyOperation() {
    TestClass* tc;
    {
        TestClass tc0(1, "tc0"), tc1(2, "tc1");
        auto tc3 = TestClass(tc0 + tc1);
        tc = new TestClass(tc3);
        TestClass tc4;
        tc4 = tc1;
    }
    delete tc;
}
