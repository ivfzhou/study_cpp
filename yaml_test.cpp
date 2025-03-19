#include <yaml-cpp/yaml.h>
#include <iostream>

using namespace std;

namespace gitee::com::ivfzhou::cpp::yaml {
    // 生成器输出到标准控制台
    static void test1() {
        YAML::Emitter emitter;
        cout << emitter.c_str() << endl;
    }
}

void TestYaml() {
    using namespace gitee::com::ivfzhou::cpp::yaml;
    test1();
}
