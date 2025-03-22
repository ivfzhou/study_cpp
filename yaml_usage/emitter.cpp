#include <iostream>
#include <map>
#include <vector>

#include <yaml-cpp/yaml.h>

using namespace std;

namespace gitee::com::ivfzhou::cpp::yaml {
    // 生成器输出到标准控制台
    static void test1() {
        YAML::Emitter emitter;
        cout << emitter.c_str() << endl;
    }

    // 生成列表
    static void test2() {
        YAML::Emitter emitter;
        emitter << YAML::BeginSeq << "1" << 2 << 3.1 << true << YAML::EndSeq;
        cout << emitter.c_str() << endl;
    }

    // 生成映射
    static void test3() {
        YAML::Emitter emitter;
        emitter << YAML::BeginMap << YAML::Key << "name" << YAML::Value << "zs" << YAML::Key << 1 << YAML::Value << 2
                << YAML::EndMap;
        cout << emitter.c_str() << endl;
    }

    // 混合生成列表和映射
    static void test4() {
        YAML::Emitter emitter;
        emitter << YAML::BeginMap << YAML::Key << "name" << YAML::Value << "zs" << YAML::Key << "hobbies" << YAML::Value
                << YAML::BeginSeq << "one" << "two" << "three" << YAML::EndSeq << YAML::EndMap;
        cout << emitter.c_str() << endl;
    }

    // 自定义输出
    static void test5() {
        YAML::Emitter emitter;
        emitter << YAML::Literal << "- A\n- B\n- C";
        cout << emitter.c_str() << endl;
    }

    // 列表改成一行输出
    static void test6() {
        YAML::Emitter emitter;
        emitter << YAML::Flow << YAML::BeginSeq << "A" << "B" << "C" << YAML::EndSeq << YAML::BeginMap << YAML::Key
                << "k" << YAML::Value << "v" << YAML::Key << "k" << YAML::Value << "v" << YAML::Key << "k"
                << YAML::Value << "v" << YAML::EndMap;
        cout << emitter.c_str() << endl;
    }

    // 输出注释
    static void test7() {
        YAML::Emitter emitter;
        emitter << YAML::Comment("this is a comment");
        cout << emitter.c_str() << endl;
    }

    // 输出锚和别名
    static void test8() {
        YAML::Emitter emitter;
        emitter << YAML::BeginSeq << YAML::Anchor("anchor") << YAML::BeginMap << YAML::Key << "name" << YAML::Value
                << "zs" << YAML::Key << "age" << YAML::Value << 18 << YAML::EndMap << "ABC" << YAML::Alias("anchor")
                << YAML::EndSeq;
        cout << emitter.c_str() << endl;
    }

    // 使用 vector 生成列表
    static void test9() {
        YAML::Emitter emitter;
        vector<int> arr;
        arr.push_back(1);
        arr.push_back(2);
        arr.push_back(3);
        emitter << YAML::BeginSeq << arr << YAML::EndSeq;
        cout << emitter.c_str() << endl;
    }

    // 使用 map 生成映射
    static void test10() {
        YAML::Emitter emitter;
        map<int, string> m;
        m[1] = "one";
        m[2] = "two";
        m[3] = "three";
        emitter << YAML::BeginMap << m << YAML::EndMap;
        cout << emitter.c_str() << endl;
    }

    class Info {
      public:
        int x = 0;
        int y = 0;
        Info(const int x, const int y) : x(x), y(y) {}
    };
    YAML::Emitter& operator<<(YAML::Emitter& e, const Info& i) {
        return e << YAML::BeginSeq << i.x << i.y << YAML::EndSeq;
    }
    // 使用自定义类型输出
    static void test11() {
        YAML::Emitter emitter;
        Info i(1, 2);
        emitter << i;
        cout << emitter.c_str() << endl;
    }

    // 输出 YAML::Node
    static void test12() {
        YAML::Emitter emitter;
        YAML::Node node;
        node["name"] = "one";
        emitter << node;
        cout << emitter.c_str() << endl;
    }

    // 输出转换非 ASCII 码
    static void test13() {
        YAML::Emitter emitter;
        emitter.SetOutputCharset(YAML::EscapeNonAscii);
        emitter << YAML::BeginSeq << "你好" << YAML::EndSeq;
        cout << emitter.c_str() << endl;
    }

    // 修改输出格式
    static void test14() {
        YAML::Emitter emitter;
        emitter.SetIndent(4);
        emitter.SetMapFormat(YAML::Flow);
        emitter << YAML::BeginMap << YAML::Key << "name" << YAML::Value << "one" << YAML::EndMap;
        cout << emitter.c_str() << endl;
    }

    // 输出发生错误
    static void test15() {
        YAML::Emitter emitter;
        emitter << YAML::Key << YAML::Value << "11";
        cout << emitter.good() << endl;
        cout << emitter.GetLastError() << endl;
    }

    extern void test16();
    extern void test17();
    extern void test18();
    extern void test19();

    // 生成文档。
    static void test20() {
        YAML::Node node;
        node["key"] = "value";
        node["seq"].push_back("first element");
        node["seq"].push_back("second element");

        node["mirror"] = node["seq"][0];
        node["seq"][0] = "1st element";
        node["mirror"] = "element #1";

        node["self"] = node;
        node[node["mirror"]] = node["seq"];
        cout << node << endl;
    }

    // 序列转映射行为。
    static void test21() {
        auto&& node = YAML::Load("[1, 2, 3]");
        node[1] = 5;
        node.push_back(-3);
        node["key"] = "value";
        cout << node << endl;

        node = YAML::Load("[1, 2, 3]");
        node[3] = 4;
        node[10] = 10;
        cout << node << endl;
    }

    // 使用列表作为映射的键。
    static void test22() {
        auto&& node = YAML::Load("{pi: 3.14159, [0, 1]: integers}");
        std::vector<int> v;
        v.push_back(0);
        v.push_back(1);
        string&& str = node[v].as<std::string>();
        cout << str << endl;
    }

    extern void test23();
}

void TestYaml() {
    using namespace gitee::com::ivfzhou::cpp::yaml;
    test23();
}

void TestYamlAll() {
    using namespace gitee::com::ivfzhou::cpp::yaml;
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();
    test10();
    test11();
    test12();
    test13();
    test14();
    test15();
    test16();
    test17();
    test18();
    test19();
    test20();
    test21();
    test22();
    test23();
}
