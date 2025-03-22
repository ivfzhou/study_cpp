#include <chrono>
#include <iostream>

#include <jwt-cpp/jwt.h>

using namespace std;

namespace gitee::com::ivfzhou::cpp::jwtivf {
    // 解析凭证。
    static void test1() {
        auto&& s = jwt::decode(
            "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJhdXRoSWQiOiJpdmZ6aG91YXNkIiwidGltZU1pbGxpcyI6MTc0MjUzNDEyM30.f-"
            "E4u4g6VALD7oPdZQV2lgtfSya7ofIqmyAhKFxhuAo");
        for (auto&& header_json : s.get_header_json()) {
            cout << header_json.first << ": " << header_json.second << endl;
        }
        for (auto&& payload_json : s.get_payload_json()) {
            cout << payload_json.first << ": " << payload_json.second << endl;
        }
    }

    // 校验凭证。
    static void test2() {
        auto&& s = jwt::decode(
            "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJhdXRoSWQiOiJpdmZ6aG91YXNkIiwidGltZU1pbGxpcyI6MTc0MjUzNDEyM30.f-"
            "E4u4g6VALD7oPdZQV2lgtfSya7ofIqmyAhKFxhuAo");
        try {
            jwt::verify().allow_algorithm(jwt::algorithm::hs256("91fd0314d30d11ef969012c7e349893c1")).verify(s);
        } catch (jwt::error::signature_verification_exception&& e) {
            cout << e.what() << endl;
        } catch (...) {
            cout << "Unknown exception" << endl;
        }
    }

    // 创建凭证。
    static void test3() {
        auto&& s = chrono::duration_cast<chrono::seconds>(chrono::system_clock::now().time_since_epoch());
        auto&& t = jwt::create()
                       .set_type("JWT")
                       .set_payload_claim("authId", jwt::claim(string("ivfzhouasd")))
                       .set_payload_claim("timeMillis", jwt::claim(to_string(s.count())))
                       .sign(jwt::algorithm::hs256("91fd0314d30d11ef969012c7e349893c"));
        cout << t << endl;
    }
}

void TestJwt() {
    using namespace gitee::com::ivfzhou::cpp::jwtivf;
    test3();
}

void TestJwtAll() {
    using namespace gitee::com::ivfzhou::cpp::jwtivf;
    test1();
    test2();
    test3();
}
