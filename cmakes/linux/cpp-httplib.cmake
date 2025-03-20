set(CPP_HTTPLIB_DEPENDENCIES_PREFIX ${DEPENDENCIES_PREFIX}/cpp-httplib)

find_path(
    CPP_HTTPLIB_INCLUDE_DIR
    NAMES httplib.h
    PATHS ${CPP_HTTPLIB_DEPENDENCIES_PREFIX}/include
    NO_DEFAULT_PATH
)

if(CPP_HTTPLIB_INCLUDE_DIR)
    message(STATUS "CPP_HTTPLIB_INCLUDE_DIR found: ${CPP_HTTPLIB_INCLUDE_DIR}")
else()
    ExternalProject_Add(
        cpp-httplib
        PREFIX ${CPP_HTTPLIB_DEPENDENCIES_PREFIX}
        URL https://github.com/yhirose/cpp-httplib/archive/refs/tags/v0.20.0.zip
        CONFIGURE_COMMAND cd ${CPP_HTTPLIB_DEPENDENCIES_PREFIX}/src &&
        rm -rf cpp-httplib-build && mkdir -p cpp-httplib-build
        BUILD_COMMAND cd ${CPP_HTTPLIB_DEPENDENCIES_PREFIX}/src/cpp-httplib-build &&
        ${CMAKE_COMMAND} -DCMAKE_INSTALL_PREFIX=${CPP_HTTPLIB_DEPENDENCIES_PREFIX}
        -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE} -DBUILD_SHARED_LIBS=OFF ../cpp-httplib
        INSTALL_COMMAND cd ${CPP_HTTPLIB_DEPENDENCIES_PREFIX}/src/cpp-httplib-build &&
        ${CMAKE_COMMAND} --build . --target install
    )
    set(CPP_HTTPLIB_INCLUDE_DIR ${CPP_HTTPLIB_DEPENDENCIES_PREFIX}/include)
endif()

include_directories(${CPP_HTTPLIB_INCLUDE_DIR})
