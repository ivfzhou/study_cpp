cmake_minimum_required(VERSION 3.25)

project(cpp)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(cpp
        main.cpp
        assign_copy_operate.cpp
        cast_var.cpp
        character.cpp
        enum.cpp
        exception.cpp
        FatherClass.cpp
        friend_member_operator_overload.cpp
        FriendClass.hpp
        iterator.cpp
        locate_new.cpp
        macro_test.cpp
        member_initializer_list.cpp
        multiple_inheritance.cpp
        namespace.cpp
        private_extend.cpp
        RTTI.cpp
        smart_pointer.cpp
        SonClass.cpp
        source.cpp
        String.cpp
        task.cpp
        template.cpp
        template_static_member.cpp
        TestClass10.cpp
        TestClass20.cpp
        TmplClass.hpp
        valarray_usage.cpp
        value_pass.cpp
        vararg_test.cpp
)
