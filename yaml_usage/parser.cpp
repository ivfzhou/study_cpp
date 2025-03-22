#include <fstream>
#include <iostream>

#include <yaml-cpp/yaml.h>

using namespace std;

namespace gitee::com::ivfzhou::cpp::yaml {
    class Data final {
      public:
        int x = 0;
    };
}

// 自定义序列化类。
namespace YAML {
    using namespace gitee::com::ivfzhou::cpp::yaml;

    template<>
    struct convert<Data> {
        static Node encode(const Data& data) {
            Node node;
            node.push_back(data.x);
            return node;
        }

        static bool decode(const Node& node, Data& data) {
            data.x = node[0].as<int>();
            return true;
        }
    };
}

namespace gitee::com::ivfzhou::cpp::yaml {
    // 加载 yaml 文件。
    void test16() {
        YAML::Node node = YAML::LoadFile("../../yaml_usage/test.yml");
        if (!node) {
            cout << "node is not available" << endl;
            return;
        }
        YAML::Node n = node["name"];
        if (n) {
            cout << "name: " << n.as<string>() << endl;
        }
        n = node["hobbies"];
        if (n) {
            cout << "IsSequence: " << n.IsSequence() << endl;
        }
        ofstream fout("test.yml");
        fout << node;
    }

    // 解析字符串。
    void test17() {
        auto node = YAML::Load("[1, 2]");
        if (!node) {
            cout << "node is not available" << endl;
            return;
        }
        cout << (node.Type() == YAML::NodeType::Sequence) << endl;
    }

    // 遍历序列。
    void test18() {
        auto node = YAML::Load("[1, 2]");
        for (size_t i = 0; i < node.size(); i++) {
            cout << node[i].as<int>() << endl;
        }

        for (auto&& it = node.begin(); it != node.end(); ++it) {
            cout << it->as<int>() << endl;
        }
    }

    // 遍历映射。
    void test19() {
        auto&& node = YAML::Load("{1B: Prince Fielder, 2B: Rickie Weeks, LF: Ryan Braun}");
        for (auto&& it = node.begin(); it != node.end(); ++it) {
            cout << it->first.as<string>() << it->second.as<string>() << endl;
        }
    }

    // 自定义数据类。
    void test23() {
        auto&& node = YAML::Load("[1, 2]");
        auto&& data = node.as<Data>();
        cout << data.x << endl;

        Data d;
        d.x = 2;
        auto&& n = YAML::convert<Data>::encode(d);
        cout << n << endl;
    }
}
