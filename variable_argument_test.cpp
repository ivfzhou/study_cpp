#include <iostream>
#include <chrono>
#include <iomanip>

namespace gitee::com::ivfzhou::cpp::variable_argument {
    static void println() {
        std::cout << std::endl;
    }

    static std::string now() {
        const auto t = std::chrono::system_clock::now();
        const auto t0 = std::chrono::system_clock::to_time_t(t);
        std::ostringstream sb;
        sb << std::put_time(std::localtime(&t0), "%Y-%m-%d %H:%M:%S");
        return sb.str();
    }

    template <typename T, typename... Args>
    void println(T t, Args... args) {
        std::cout << t << " ";
        println(args...);
    }

    template <typename... Args>
    void log(const std::string& level, Args... args) {
        std::cout << now() << " " << level << " ";
        println(args...);
    }

    std::string getCaller(const char* file, int line) {
        std::ostringstream oss;
        oss << file << ":" << line;
        return oss.str();
    }

    #define LOG(level, ...) \
        auto callInfo = getCaller(__FILE__, __LINE__); \
        log(level, callInfo, __VA_ARGS__)
}

void TestVariableArgument() {
    using namespace gitee::com::ivfzhou::cpp::variable_argument;
    LOG("INFO", "Hello World!", 1, 1.1);

    println(1, "Hello World!", 1, 1.1);
}
