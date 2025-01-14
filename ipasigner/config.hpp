#ifndef IPASIGNER_CONFIG_HPP
#define IPASIGNER_CONFIG_HPP

#include <string>
#include <list>
#include <map>
#include <iostream>

namespace ipasigner {

    class config {

        // 打印
        friend std::ostream &operator<<(std::ostream &o, const config &cfg);

    public:
        // 待签名文件路径，可以是文件夹，文件名中可以使用通配符*
        std::string ipa_path;

        // 签名结果文件路径
        std::string dest_dir;

        // 签名结果文件名，如果不填，则取待签名文件名
        std::string dest_ipa;

        // 与 dest_ipa 必须二选一，签名结果文件名后缀，示例输出文件为 example1_signed.ipa
        std::string ipa_suffix;

        std::string cert_path;

        std::string provision_path;

        // 强制签名，同codesign的--force
        bool force = false;

        // 更换 bundleId
        std::string bundle_id;

        // 更换 bundle 名
        std::string bundle_name;

        // 更换 bundle 版本号
        int bundle_version = 0;

        // 当待签名文件为文件夹的时候，可以设为 true 来跳过打包步骤
        bool skip_archive = false;

        // UL 域名
        std::vector<std::string> ul_domains;

        // 钥匙串访问组
        std::vector<std::string> keychain_access_group;

        // 苹果安全应用组，即为证书添加的 appgoup 值
        std::vector<std::string> security_group;

        // 替换所有 info.plist 的对应配置
        std::map<std::string, std::string> info;

        // appx 包对应的子描述文件，用于多签的情况
        std::map<std::string, std::string> appx_provision_ids;

    };

}

// 实现序列和反序列化
template<>
class YAML::convert<ipasigner::config> {
public:
    static Node encode(const ipasigner::config &cfg);

    static bool decode(const Node &node, ipasigner::config &cfg);
};


#endif
