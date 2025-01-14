#ifndef STRING
#define STRING

#include <string>
#include <iostream>

class String {
    char *value = nullptr;

    friend std::ostream &operator<<(std::ostream &os, const String &s) {
        return os << s.value;
    };

  public:

    String() = default;

    String(const String &);

    String(const std::string &);

    String(const char *);

    String &operator=(const String &);

    String &operator=(const std::string &);

    String &operator=(const char *);

    String operator+(const String &) const;

    String operator+(const char *) const;

    String operator+(const std::string &) const;

    virtual ~String() {
        std::cout << "free" << std::endl;
        delete[] value;
    };
};

#endif
