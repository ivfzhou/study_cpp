find_path(
    YAML_CPP_INCLUDE_DIR
    NAMES yaml-cpp
    PATHS ${DEPENDENCIES_PREFIX}/include
    NO_DEFAULT_PATH
)
find_library(
    YAML_CPP_LIB
    NAMES libyaml-cpp.a
    PATHS ${DEPENDENCIES_PREFIX}/lib
    NO_DEFAULT_PATH
)

if(YAML_CPP_LIB AND YAML_CPP_INCLUDE_DIR)
    message(STATUS "yaml-cpp header found: ${YAML_CPP_INCLUDE_DIR}")
    message(STATUS "yaml-cpp static library found: ${YAML_CPP_LIB}")
else()
    include(ExternalProject)
    ExternalProject_Add(
        libyaml-cpp
        PREFIX ${YAML_CPP_ROOT}
        GIT_REPOSITORY "https://github.com/jbeder/yaml-cpp.git"
        GIT_TAG "0.8.0"
        CONFIGURE_COMMAND cd ${DEPENDENCIES_PREFIX}/src/libyaml-cpp && mkdir build || true
        BUILD_COMMAND cd ${DEPENDENCIES_PREFIX}/src/libyaml-cpp && cd build && cmake -DCMAKE_INSTALL_PREFIX=${DEPENDENCIES_PREFIX} .. && make -j
        INSTALL_COMMAND cd ${DEPENDENCIES_PREFIX}/src/libyaml-cpp && cd build && make install
    )
    set(YAML_CPP_LIB ${DEPENDENCIES_PREFIX}/lib/libyaml-cpp.a)
endif()

list(APPEND LIB_LIST ${YAML_CPP_LIB})
