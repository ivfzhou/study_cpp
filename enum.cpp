namespace enum_ {
    enum class NumericEnum {
        One, Two
    }; // 类作用域范围的枚举

    NumericEnum num = NumericEnum::One; // 通过作用域运算符使用
    int x = (int) num; // 需显式强制类型转换

    enum NumericEnum0 {
        One, Two
    };

    int y = One; // 可以隐式类型转换

    enum class NumericEnum1 : short {
        One, Two
    }; // 指定编译器使用short为底层类型
}
