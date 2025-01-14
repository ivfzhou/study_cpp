// RTTI Runtime Type Identification

#include <iostream>
#include <typeinfo>

namespace rtti {
    class Grand {
      public:
        virtual void whoami() {
            std::cout << "I am grand" << std::endl;
        }
    };

    class Superb : public Grand {
      public:
        void whoami() override {
            std::cout << "I am superb" << std::endl;
        }
    };

    class Magnificent : public Superb {
      public:
        void whoami() override {
            std::cout << "I am magnificent" << std::endl;
        }
    };

    void test() {
        // dynamic_cast 指针转换
        {
            Grand *ptr_g = new Magnificent;
            auto *ptr_m = dynamic_cast<Magnificent *>(ptr_g); // 如果ptr_g不能转成Magnificent则返回0
            if (ptr_m) {
                ptr_m->whoami();
            }
            delete ptr_g;
        }

        // dynamic_cast 引用转换
        {
            try {
                Superb s;
                Grand &ref_g = s;
                auto &ref_m = dynamic_cast<Magnificent &>(ref_g); // 如果ref_g不能转成Magnificent引用则触发bad_cast异常
            } catch (std::bad_cast &e) {
                std::cout << "dynamic_cast exception " << e.what() << std::endl;
            }
        }

        // typeid & type_info
        {
            Grand *ptr_g = new Magnificent;
            const std::type_info &ti_g = typeid(ptr_g);
            std::cout << ti_g.name() << std::endl;

            std::cout << typeid(Magnificent *).name() << std::endl;
            std::cout << typeid(Magnificent).name() << std::endl;
            std::cout << typeid(Magnificent &).name() << std::endl;
            std::cout << (typeid(Magnificent *) == ti_g) << std::endl;
            std::cout << (typeid(Grand *) == ti_g) << std::endl;
            delete ptr_g;
        }
    }
}
