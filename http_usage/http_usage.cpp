#include <iostream>

#define CPPHTTPLIB_OPENSSL_SUPPORT
#include "httplib.h"

using namespace std;

namespace gitee::com::ivfzhou::cpp::http_usage {
    // 启动监听。
    static void test1() {
        httplib::Server svr;
        svr.Get("/hi", [](const httplib::Request& req, httplib::Response& rsp) {
            rsp.set_content("Hello World!", "text/plain");
        });
        svr.listen("0.0.0.0", 8080);
    }

    // 发送请求。
    static void test2() {
        httplib::Client cli("https://baidu.com");
        auto&& response = cli.Get("/");
        cout << response->status << endl;
        cout << response->body << endl;
    }

    // 发送 SSL 请求。
    static void test3() {
        httplib::SSLClient cli("https://baidu.com");
        cli.set_ca_cert_path("./ca-bundle.crt");
        cli.enable_server_certificate_verification(false);
        cli.enable_server_hostname_verification(false);
        auto&& response = cli.Get("/");
        cout << response->status << endl;
        cout << response->body << endl;
    }

    // 服务端用例。
    static void test4() {
        httplib::SSLServer svr("cert_path", "private_key_path");

        svr.Get(R"(/numbers/(\d+))", [&](const httplib::Request& req, httplib::Response& res) {
            auto numbers = req.matches[1];
            res.set_content(numbers, "text/plain");
        });

        svr.Get("/users/:id", [&](const httplib::Request& req, httplib::Response& res) {
            auto user_id = req.path_params.at("id");
            res.set_content(user_id, "text/plain");
        });

        svr.Get("/body-header-param", [](const httplib::Request& req, httplib::Response& res) {
            if (req.has_header("Content-Length")) {
                auto val = req.get_header_value("Content-Length");
            }
            if (req.has_param("key")) {
                auto val = req.get_param_value("key");
            }
            res.set_content(req.body, "text/plain");
        });

        svr.Get("/task", [&](const httplib::Request& req, httplib::Response& res) {
            const char* result = nullptr;
            // process.run();
            while (result == nullptr) {
                // sleep(1);
                if (req.is_connection_closed()) {
                    // process.kill();
                    return;
                }
                // result = process.stdout();
            }
            res.set_content(result, "text/plain");
        });

        svr.Get("/stop", [&](const httplib::Request& req, httplib::Response& res) { svr.stop(); });
    }
}

void TestHttp() {
    using namespace gitee::com::ivfzhou::cpp::http_usage;
    test4();
}

void TestHttpAll() {
    using namespace gitee::com::ivfzhou::cpp::http_usage;
    test1();
    test2();
    test3();
    test4();
}
