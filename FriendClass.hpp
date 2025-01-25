#ifndef GITEE_COM_IVFZHOU_CPP_FRIEND_CLASS
#define GITEE_COM_IVFZHOU_CPP_FRIEND_CLASS

#include "TemplateClass.hpp"

namespace gitee::com::ivfzhou::cpp {
    template <typename T, typename E>
    class FriendClass {
        TemplateClass<T, E> c;

        int field = 0;

    public:
        void friendClassMethod();
    };
}

#include "FriendClass.tpp"

#endif
