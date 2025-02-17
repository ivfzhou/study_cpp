find_path(
    CPP_HTTPLIB_INCLUDE_DIR
    NAMES "httplib.h"
    PATHS "${DEPENDENCIES_PREFIX}/include"
    NO_DEFAULT_PATH
)

if(CPP_HTTPLIB_INCLUDE_DIR)
    message(STATUS "CPP_HTTPLIB_INCLUDE_DIR found: ${CPP_HTTPLIB_INCLUDE_DIR}")
else()
    include(ExternalProject)
    ExternalProject_Add(
        "libcpp-httplib"
        PREFIX ${DEPENDENCIES_PREFIX}
        GIT_REPOSITORY "https://github.com/yhirose/cpp-httplib.git"
        GIT_TAG "v0.18.7"
        CONFIGURE_COMMAND cd ${DEPENDENCIES_PREFIX}/src && if not exist libcpp-httplib-build (md libcpp-httplib-build)
        BUILD_COMMAND cd ${DEPENDENCIES_PREFIX}/src/libcpp-httplib-build && ${CMAKE_COMMAND} -DCMAKE_INSTALL_PREFIX=${DEPENDENCIES_PREFIX} ../libcpp-httplib
        INSTALL_COMMAND cd ${DEPENDENCIES_PREFIX}/src/libcpp-httplib-build && ${CMAKE_COMMAND} --build . --target install --config Release
    )
endif()
