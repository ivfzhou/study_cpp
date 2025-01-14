#include <string>
#include <iostream>
#include <codecvt>
#include <locale>

namespace character {

    // 通用字符名：\uxxxx \Uxxxxxxxx 表示 Unicode、ISO10646的一个码点。
    void universalCharacterName() {
        int k\u00f6rper = 0;
        std::cout << "k\u00f6rper " << k\u00f6rper << std::endl; // körper
    }

    // 宽字符类型
    void weightChar() {
        wchar_t wc = L'你';
        wchar_t wc0[] = L"你好";
        std::wcout << wc << std::endl << wc0 << std::endl; // 4f60
    }

    // raw string
    void rawString() {
        std::string s = R"( hello world\n )";
        std::cout << s << std::endl;

        std::string s0 = R"++( hello"( world\n )++"; // 更换定界符，但不能包含空格、左右括号、斜杠、控制字符。
        std::cout << s0 << std::endl;

        wchar_t s1[] = LR"( 与宽字符结合使用 )";
        std::wcout << s1 << std::endl;
    }

    // 其他形式的字符串字面量
    void chars() {
        char8_t s[] = u8"你好";
        // std::wstring_convert<std::codecvt_utf8<char8_t>, char8_t> converter;
        // std::cout << converter.to_bytes(std::u8string(s)) << std::endl;

        char16_t s0[] = u"你好";
        std::wstring_convert<std::codecvt_utf8<char16_t>, char16_t> converter0;
        std::cout << converter0.to_bytes(std::u16string(s0)) << std::endl;

        char32_t s1[] = U"你好";
        std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> converter1;
        std::cout << converter1.to_bytes(std::u32string(s1)) << std::endl;

        char8_t c8 = u8'a';
        char16_t c16 = u'你';
        char32_t c32 = U'你';
        std::cout << int(c8) << std::endl
                  << int(c16) << std::endl
                  << int(c32) << std::endl;
    }

}
