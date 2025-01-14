#include <cstring>

#include "String.hpp"

String::String(const String &s) {
    size_t len = std::strlen(s.value);
    this->value = new char[len + 1];
    std::strcpy(this->value, s.value);
}

String::String(const std::string &s) {
    size_t len = s.length();
    this->value = new char[len + 1];
    std::strcpy(this->value, s.data());
}

String::String(const char *s) {
    size_t len = std::strlen(s);
    this->value = new char[len + 1];
    std::strcpy(this->value, s);
}

String &String::operator=(const String &s) {
    if (this == &s) return *this;
    delete[] this->value;
    size_t len = std::strlen(s.value);
    this->value = new char[len + 1];
    std::strcpy(this->value, s.value);
    return *this;
}

String &String::operator=(const std::string &s) {
    delete[] this->value;
    size_t len = s.length();
    this->value = new char[len + 1];
    std::strcpy(this->value, s.data());
    return *this;
}

String &String::operator=(const char *s) {
    delete[] this->value;
    size_t len = std::strlen(s);
    this->value = new char[len + 1];
    std::strcpy(this->value, s);
    return *this;
}

String String::operator+(const String &s) const {
    String newStr;
    size_t l1 = std::strlen(this->value);
    size_t l2 = std::strlen(s.value);
    size_t len = l1 + l2;
    newStr.value = new char[len + 1];
    std::memcpy(newStr.value, this->value, l1 * sizeof(char));
    std::memcpy(newStr.value + l1, s.value, l2 * sizeof(char));
    newStr.value[len] = '\0';
    return newStr;
}

String String::operator+(const char *s) const {
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

String String::operator+(const std::string &s) const {
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

String returnStr() {
    String s("abc");
    return s;
}

void testString() {
    std::cout << returnStr() << std::endl;
    {
        String s("abc");
        String s0(s);
        std::string str("def");
        String s1(str);
        std::cout << s << std::endl;
        std::cout << s0 << std::endl;
        std::cout << s1 << std::endl;
    }

    {
        String s = "abc";
        String s0 = s;
        std::string str("def");
        String s1 = str;
        std::cout << s << std::endl;
        std::cout << s0 << std::endl;
        std::cout << s1 << std::endl;
        String s2 = s + s0 + s1;
        std::cout << s2 << std::endl;
    }
}
