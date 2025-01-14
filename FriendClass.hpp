#ifndef FRIEND_CLASS
#define FRIEND_CLASS

#include "TmplClass.hpp"

template<typename T, typename E> class FriendClass {
  private:
    TmplClass<T, E> c;

    int field;

  public:
    void friendClassMethod();
};

#include "FriendClass.cpp"

#endif
