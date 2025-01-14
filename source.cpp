namespace cn_ivfzhou_cpp {
    const int isAStaticVar = 2; // 只能在同一个翻译单元使用

    extern const int externalVar = 3;

    static void fn() {} // 只能在同一个翻译单元使用

    inline void ifn() { fn(); } // 可被多个翻译单元包含而无重复定义
}
