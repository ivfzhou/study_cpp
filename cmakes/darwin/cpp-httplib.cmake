find_path(
    CPP_HTTPLIB_INCLUDE_DIR
    NAMES httplib.h
    PATHS ${INSTALL_PREFIX}/include
    NO_DEFAULT_PATH
)

if(CPP_HTTPLIB_INCLUDE_DIR)
    message(STATUS "CPP_HTTPLIB_INCLUDE_DIR found: ${CPP_HTTPLIB_INCLUDE_DIR}")
else()
    include(ExternalProject)
    ExternalProject_Add(
        libcpp-httplib
        PREFIX ${DEPENDENCIES_PREFIX}
        GIT_REPOSITORY "https://github.com/yhirose/cpp-httplib.git"
        GIT_TAG "v0.18.7"
        CONFIGURE_COMMAND cd ${DEPENDENCIES_PREFIX}/src/libcpp-httplib && mkdir build || true
        BUILD_COMMAND cd ${DEPENDENCIES_PREFIX}/src/libcpp-httplib && cd build && cmake -DCMAKE_INSTALL_PREFIX=${DEPENDENCIES_PREFIX} .. && make -j
        INSTALL_COMMAND cd ${DEPENDENCIES_PREFIX}/src/libcpp-httplib && cd build && make install
    )

endif()
