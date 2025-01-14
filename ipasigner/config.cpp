#include <yaml-cpp/yaml.h>

#include "config.hpp"

namespace ipasigner {
    std::ostream &operator<<(std::ostream &out, const config &cfg) {
        std::string buf;
        buf.append("{ ").append("ipa_path=").append(cfg.ipa_path).append(", ").append("dest_dir=").append(cfg.dest_dir).
                append(", ").append("dest_ipa=").append(cfg.dest_ipa).append(", ").append("ipa_suffix=").
                append(cfg.ipa_suffix).append(", ").append("cert_path=").append(cfg.cert_path).append(", ").
                append("provision_path=").append(cfg.provision_path).append(", ").append("provision_path=").
                append(cfg.provision_path).append(", ").append("force=").append(std::to_string(cfg.force)).append(", ").
                append("bundle_id=").append(cfg.bundle_id).append(", ").append("bundle_name=").append(cfg.bundle_name).
                append(", ").append("bundle_version=").append(std::to_string(cfg.bundle_version)).append(", ").
                append("skip_archive=").append(std::to_string(cfg.skip_archive)).append(", ");

        if (cfg.ul_domains.empty()) {
            buf.append("ul_domains=[], ");
        } else {
            buf.append("ul_domains=[ ");
            for (std::size_t i = 0; i < cfg.ul_domains.size(); i++) {
                buf.append(cfg.ul_domains.at(i));
                if (i < cfg.ul_domains.size() - 1) buf.append(", ");
            }
            buf.append(" ], ");
        }

        if (cfg.keychain_access_group.empty()) {
            buf.append("keychain_access_group=[], ");
        } else {
            buf.append("keychain_access_group=[ ");
            for (std::size_t i = 0; i < cfg.keychain_access_group.size(); i++) {
                buf.append(cfg.keychain_access_group.at(i));
                if (i < cfg.keychain_access_group.size() - 1) buf.append(", ");
            }
            buf.append(" ], ");
        }

        if (cfg.security_group.empty()) {
            buf.append("security_group=[], ");
        } else {
            buf.append("security_group=[ ");
            for (std::size_t i = 0; i < cfg.security_group.size(); i++) {
                buf.append(cfg.security_group.at(i));
                if (i < cfg.security_group.size() - 1) buf.append(", ");
            }
            buf.append(" ], ");
        }

        if (cfg.info.empty()) {
            buf.append("info={}, ");
        } else {
            buf.append("info={ ");
            for (auto it = cfg.info.begin(); it != cfg.info.end(); it++) {
                buf.append(it->first).append("=").append(it->second);
                if (std::next(it) != cfg.info.end()) buf.append(", ");
            }
            buf.append(" }, ");
        }

        if (cfg.appx_provision_ids.empty()) {
            buf.append("appx_provision_ids={} ");
        } else {
            buf.append("appx_provision_ids={ ");
            for (auto it = cfg.appx_provision_ids.begin(); it != cfg.appx_provision_ids.end(); it++) {
                buf.append(it->first).append("=").append(it->second);
                if (std::next(it) != cfg.appx_provision_ids.end()) buf.append(", ");
            }
            buf.append(" }");
        }

        out << buf.append(" }");

        return out;
    }
}

YAML::Node YAML::convert<ipasigner::config>::encode(const ipasigner::config &cfg) {
    YAML::Node node;
    node["ipa_path"] = cfg.ipa_path;
    node["dest_dir"] = cfg.dest_dir;
    node["dest_ipa"] = cfg.dest_ipa;
    node["ipa_suffix"] = cfg.ipa_suffix;
    node["cert_path"] = cfg.cert_path;
    node["provision_path"] = cfg.provision_path;
    node["force"] = cfg.force;
    node["bundle_id"] = cfg.bundle_id;
    node["bundle_name"] = cfg.bundle_name;
    node["bundle_version"] = cfg.bundle_version;
    node["skip_archive"] = cfg.skip_archive;
    for (const auto &v: cfg.ul_domains) node["ul_domains"].push_back(v);
    for (const auto &v: cfg.keychain_access_group) node["keychain_access_group"].push_back(v);
    for (const auto &v: cfg.security_group) node["security_group"].push_back(v);
    for (const auto &v: cfg.info) node["info"][v.first] = v.second;
    for (const auto &v: cfg.appx_provision_ids) node["appx_provision_ids"][v.first] = v.second;
    return node;
}

bool YAML::convert<ipasigner::config>::decode(const YAML::Node &node, ipasigner::config &cfg) {
    if (node["ipa_path"] && node["ipa_path"].Type() == YAML::NodeType::Scalar)
        cfg.ipa_path = node["ipa_path"].as<std::string>();
    if (node["dest_dir"] && node["dest_dir"].Type() == YAML::NodeType::Scalar)
        cfg.dest_dir = node["dest_dir"].as<std::string>();
    if (node["dest_ipa"] && node["dest_ipa"].Type() == YAML::NodeType::Scalar)
        cfg.dest_ipa = node["dest_ipa"].as<std::string>();
    if (node["ipa_suffix"] && node["ipa_suffix"].Type() == YAML::NodeType::Scalar)
        cfg.ipa_suffix = node["ipa_suffix"].as<std::string>();
    if (node["cert_path"] && node["cert_path"].Type() == YAML::NodeType::Scalar)
        cfg.cert_path = node["cert_path"].as<std::string>();
    if (node["provision_path"] && node["provision_path"].Type() == YAML::NodeType::Scalar)
        cfg.provision_path = node["provision_path"].as<std::string>();
    if (node["force"] && node["force"].Type() == YAML::NodeType::Scalar)
        cfg.force = node["force"].as<bool>();
    if (node["bundle_id"] && node["bundle_id"].Type() == YAML::NodeType::Scalar)
        cfg.bundle_id = node["bundle_id"].as<std::string>();
    if (node["bundle_name"] && node["bundle_name"].Type() == YAML::NodeType::Scalar)
        cfg.bundle_name = node["bundle_name"].as<std::string>();
    if (node["bundle_version"] && node["bundle_version"].Type() == YAML::NodeType::Scalar)
        cfg.bundle_version = node["bundle_version"].as<int>();
    if (node["skip_archive"] && node["skip_archive"].Type() == YAML::NodeType::Scalar)
        cfg.skip_archive = node["skip_archive"].as<bool>();
    if (node["ul_domains"] && node["ul_domains"].Type() == YAML::NodeType::Sequence)
        for (std::size_t i = 0; i < node["ul_domains"].size(); i++)
            cfg.ul_domains.push_back(node["ul_domains"][i].as<std::string>());
    if (node["keychain_access_group"] && node["keychain_access_group"].Type() == YAML::NodeType::Sequence)
        for (std::size_t i = 0; i < node["keychain_access_group"].size(); i++)
            cfg.keychain_access_group.push_back(node["keychain_access_group"][i].as<std::string>());
    if (node["security_group"] && node["security_group"].Type() == YAML::NodeType::Sequence)
        for (std::size_t i = 0; i < node["security_group"].size(); i++)
            cfg.security_group.push_back(node["security_group"][i].as<std::string>());
    if (node["info"] && node["info"].Type() == YAML::NodeType::Map)
        for (auto v = node["info"].begin(); v != node["info"].end(); v++)
            cfg.info[v->first.as<std::string>()] = v->second.as<std::string>();
    if (node["appx_provision_ids"] && node["appx_provision_ids"].Type() == YAML::NodeType::Map)
        for (auto v = node["appx_provision_ids"].begin(); v != node["appx_provision_ids"].end(); v++)
            cfg.info[v->first.as<std::string>()] = v->second.as<std::string>();
    return true;
}
