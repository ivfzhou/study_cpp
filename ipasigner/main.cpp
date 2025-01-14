/*
 * Copyright (c) 2024 ivfzhou
 * ipasigner is licensed under Mulan PSL v2.
 * You can use this software according to the terms and conditions of the Mulan PSL v2.
 * You may obtain a copy of Mulan PSL v2 at:
 *          http://license.coscl.org.cn/MulanPSL2
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
 * EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
 * MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
 * See the Mulan PSL v2 for more details.
 */

#include <iostream>
#include <fstream>

#include <yaml-cpp/yaml.h>
#include <argparse/argparse.hpp>

#include "config.hpp"

int main(int argv, char *argc[]) {
    // 解析命令行参数
    argparse::ArgumentParser argParser(
            "ipasigner",
            std::string("v").append(VERSION).append("+").append(BUILT_TIME));
    argParser.set_prefix_chars("/-");
    argParser.add_description("Used to signing .ipa file");
    argParser.add_epilog("Author email is ivfzhou@126.com");
    argParser.add_argument("-c", "--config").help("yaml format sign config").required();
    try {
        argParser.parse_args(argv, argc);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        std::cerr << argParser << std::endl;
        return 1;
    }
    auto cfgPath = argParser.get("-c");

    // 解析 yml 数据
    std::cout << "parse yml config" << std::endl;
    YAML::Node node = YAML::LoadFile(cfgPath);
    const auto &cfg = node.as<ipasigner::config>();
    std::cout << cfg << std::endl;


    // 执行签名

    return 0;
}
