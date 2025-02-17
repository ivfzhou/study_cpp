#include <iostream>

#define CPPHTTPLIB_OPENSSL_SUPPORT
#include "httplib.h"

namespace gitee::com::ivfzhou::cpp::http_usage {
    static void sayHi() {

        // HTTP
        httplib::Server svr;

        // HTTPS
        // httplib::SSLServer svr("cert_path", "private_key_path");

        svr.Get("/hi", [](const httplib::Request& req, httplib::Response& rsp) {
            rsp.set_content("Hello World!", "text/plain");
        });

        svr.listen("0.0.0.0", 8080);
        std::cout << "http_test libraries" << std::endl;
    }
}

void TestHttp() {
    using namespace gitee::com::ivfzhou::cpp::http_usage;
    sayHi();
}
