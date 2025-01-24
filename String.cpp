#include <cstring>

#include "String.hpp"

namespace gitee::com::ivfzhou::cpp {
    String::String(const String& s) {
        std::cout << "copy constructor String" << std::endl;
        size_t len = std::strlen(s.value);
        this->value = new char[len + 1];
        std::strcpy(this->value, s.value);
    }

    String::String(const std::string& s) {
        std::cout << "copy constructor std::string" << std::endl;
        size_t len = s.length();
        this->value = new char[len + 1];
        std::strcpy(this->value, s.data());
    }

    String::String(const char* s) {
        std::cout << "copy constructor char*" << std::endl;
        size_t len = std::strlen(s);
        this->value = new char[len + 1];
        std::strcpy(this->value, s);
    }

    String& String::operator=(const String& s) {
        std::cout << "member assignment operator String" << std::endl;
        if (this == &s) return *this;
        delete[] this->value;
        size_t len = std::strlen(s.value);
        this->value = new char[len + 1];
        std::strcpy(this->value, s.value);
        return *this;
    }

    String& String::operator=(const std::string& s) {
        std::cout << "member assignment operator std::string" << std::endl;
        delete[] this->value;
        size_t len = s.length();
        this->value = new char[len + 1];
        std::strcpy(this->value, s.data());
        return *this;
    }

    String& String::operator=(const char* s) {
        std::cout << "member assignment operator char*" << std::endl;
        delete[] this->value;
        size_t len = std::strlen(s);
        this->value = new char[len + 1];
        std::strcpy(this->value, s);
        return *this;
    }

    String String::operator+(const String& s) const {
        std::cout << "member add operator String" << std::endl;
        String newStr;
        size_t l1 = std::strlen(this->value);
        size_t l2 = std::strlen(s.value);
        size_t len = l1 + l2;
        newStr.value = new char[len + 1];
        std::memcpy(newStr.value, this->value, l1 * sizeof(char));
        std::memcpy(newStr.value + l1, s.value, l2 * sizeof(char));
        newStr.value[len] = '\0';
        return newStr; // 只调复制构造。
    }

    String String::operator+(const char* s) const {
        std::cout << "member add operator char*" << std::endl;
        String newStr;
        size_t l1 = std::strlen(this->value);
        size_t l2 = std::strlen(s);
        size_t len = l1 + l2;
        newStr.value = new char[len + 1];
        std::memcpy(newStr.value, this->value, l1 * sizeof(char));
        std::memcpy(newStr.value + l1, s, l2 * sizeof(char));
        newStr.value[len] = '\0';
        return newStr;
    }

    String String::operator+(const std::string& s) const {
        std::cout << "member add operator std::string" << std::endl;
        String newStr;
        size_t l1 = std::strlen(this->value);
        size_t l2 = s.length();
        size_t len = l1 + l2;
        newStr.value = new char[len + 1];
        std::memcpy(newStr.value, this->value, l1 * sizeof(char));
        std::memcpy(newStr.value + l1, s.data(), l2 * sizeof(char));
        newStr.value[len] = '\0';
        return newStr;
    }
}
