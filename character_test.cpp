#include <string>
#include <iostream>
#include <codecvt>
#include <locale>

// 通用字符名：\uxxxx \Uxxxxxxxx 表示 Unicode、ISO10646 的一个码点。
void TestUniversalCharacterName() {
    int k\u00f6rper = 0;
    std::cout << "k\u00f6rper " << k\u00f6rper << std::endl; // körper
}

// 宽字符类型。
void TestWideCharacter() {
    wchar_t wc = L'你';
    wchar_t wc0[] = L"你好";
    std::locale::global(std::locale("")); // 设置全局 locale。
    std::wcout.imbue(std::locale()); // 设置 wcout 的 locale。
    std::wcout << L"wc is " << wc << std::endl
        << L"wc0 is " << wc0 << std::endl;
}

// raw string
void TestRawString() {
    std::string s = R"( hello world\n )";
    std::cout << "s is " << s << std::endl;

    std::string s0 = R"++( hello"( world\n )++"; // 更换定界符，但不能包含空格、左右括号、斜杠、控制字符。
    std::cout << "s0 is " << s0 << std::endl;

    wchar_t s1[] = LR"( 与宽字符结合使用 )";
    std::wcout.imbue(std::locale());
    std::wcout << L"s1 is " << s1 << std::endl;
}

// 其他形式的字符串字面量。
void TestCertainLengthCharacters() {
    char8_t s[] = u8"你好";
    std::cout << reinterpret_cast<char*>(s) << std::endl;

    char16_t s0[] = u"你好";
    std::wstring_convert<std::codecvt_utf8<char16_t>, char16_t> convert16;
    std::string s0_utf8 = convert16.to_bytes(s0);
    std::cout << s0_utf8 << std::endl;

    char32_t s1[] = U"你好";
    std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> convert32;
    std::string s1_utf8 = convert32.to_bytes(s1);
    std::cout << s1_utf8 << std::endl;

    char8_t c8 = u8'a';
    char16_t c16 = u'你';
    char32_t c32 = U'你';
    std::cout << "c8 int is " << static_cast<int>(c8) << std::endl
        << "c16 int is " << static_cast<int>(c16) << std::endl
        << "c32 int is " << static_cast<int>(c32) << std::endl;
}
