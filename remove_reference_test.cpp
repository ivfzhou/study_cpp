namespace gitee::com::ivfzhou::cpp::remove_reference {
    template<typename T>
    class RemoveReference {
      public:
        using type = T;
    };

    // 具体化。
    template<typename T>
    class RemoveReference<T&> {
      public:
        using type = T;
    };

    template<typename T>
    class RemoveReference<T&&> {
      public:
        using type = T;
    };
}

void TestTypename() {
    using namespace gitee::com::ivfzhou::cpp::remove_reference;
    RemoveReference<int>::type x;
    RemoveReference<int&>::type y;
    RemoveReference<int&&>::type z(0);

    auto m = z;
}
