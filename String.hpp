#ifndef GITEE_COM_IVFZHOU_CPP_STRING
#define GITEE_COM_IVFZHOU_CPP_STRING

#include <string>
#include <iostream>

namespace gitee::com::ivfzhou::cpp {
    class String {
        char* value = nullptr;

        friend std::ostream& operator<<(std::ostream& os, const String& s) {
            return os << s.value;
        }

    public:
        String() = default;

        String(const String&);

        explicit String(const std::string&);

        explicit String(const char*);

        String& operator=(const String&);

        String& operator=(const std::string&);

        String& operator=(const char*);

        String operator+(const String&) const;

        String operator+(const char*) const;

        String operator+(const std::string&) const;

        virtual ~String() {
            std::cout << "~String" << std::endl;
            delete[] value;
        }
    };
}

#endif
