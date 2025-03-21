namespace gitee::com::ivfzhou::enumeration {
    // 枚举定义，struct 可换 class。
    enum class NumericEnum { One, Two }; // 类作用域范围的枚举。

    NumericEnum num = NumericEnum::One; // 通过作用域运算符使用。
    int x = static_cast<int>(num); // 需显式强制类型转换。

    enum NumericEnum0 { One, Two };

    int y = One; // 可以隐式类型转换。

    enum class NumericEnum1 : short { One, Two }; // 指定编译器使用 short 为底层类型。
}
