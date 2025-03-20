#include "TemplateClass.hpp"

// template class gitee::com::ivfzhou::cpp::TemplateClass<int, int>;

void TestTemplateClass() {
    using namespace gitee::com::ivfzhou::cpp;

    TemplateClass<int, int> tc;

    int x = static_cast<int>(tc);

    tc();
}
