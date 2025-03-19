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
        GIT_REPOSITORY https://github.com/yhirose/cpp-httplib.git
        GIT_TAG v0.18.7
        CONFIGURE_COMMAND cd ${CPP_HTTPLIB_DEPENDENCIES_PREFIX}/src && if not exist cpp-httplib-build (md cpp-httplib-build)
        BUILD_COMMAND cd ${CPP_HTTPLIB_DEPENDENCIES_PREFIX}/src/cpp-httplib-build && ${CMAKE_COMMAND} -DCMAKE_INSTALL_PREFIX=${CPP_HTTPLIB_DEPENDENCIES_PREFIX} -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE} ../cpp-httplib
        INSTALL_COMMAND cd ${CPP_HTTPLIB_DEPENDENCIES_PREFIX}/src/cpp-httplib-build && ${CMAKE_COMMAND} --build . --target install --config ${CMAKE_BUILD_TYPE}
    )
    set(CPP_HTTPLIB_INCLUDE_DIR ${CPP_HTTPLIB_DEPENDENCIES_PREFIX}/include)
endif()

include_directories(${CPP_HTTPLIB_INCLUDE_DIR})
