#include <iostream>
#include <typeinfo>

namespace gitee::com::ivfzhou::cpp::rtti {
    class Grand {
    public:
        virtual void whoami() {
            std::cout << "I am grand" << std::endl;
        }
        virtual ~Grand() = default;
    };

    class Superb : public Grand {
    public:
        void whoami() override {
            std::cout << "I am superb" << std::endl;
        }
        ~Superb() override = default;
    };

    class Magnificent : public Superb {
    public:
        void whoami() override {
            std::cout << "I am magnificent" << std::endl;
        }
    };
}

void TestRuntimeTypeIdentification() {
    using namespace gitee::com::ivfzhou::cpp::rtti;
    // dynamic_cast 指针转换。
    {
        Grand* grand = new Magnificent;
        auto magnificent = dynamic_cast<Magnificent*>(grand); // 如果 grand 不能转成 Magnificent 则返回 0。
        if (magnificent) magnificent->whoami();

        delete grand;
    }

    // dynamic_cast 引用转换。
    {
        try {
            Superb s;
            Grand& grand = s;
            auto& magnificent = dynamic_cast<Magnificent&>(grand); // 如果 grand 不能转成 Magnificent 引用则触发 bad_cast 异常。
        } catch (std::bad_cast& e) {
            std::cout << "dynamic_cast exception " << e.what() << std::endl;
        }
    }

    // typeid & type_info
    {
        Grand* grand = new Magnificent;
        const auto& info = typeid(grand);
        std::cout << info.name() << std::endl;

        std::cout << "typeid(Magnificent*).name() is " << typeid(Magnificent*).name() << std::endl;
        std::cout << "typeid(Magnificent).name() is " << typeid(Magnificent).name() << std::endl;
        std::cout << "typeid(Magnificent&).name() is " << typeid(Magnificent&).name() << std::endl;
        std::cout << "typeid(Magnificent*) == info is " << (typeid(Magnificent*) == info) << std::endl;
        std::cout << "typeid(Grand*) == info is " << (typeid(Grand*) == info) << std::endl;
        delete grand;
    }
}
