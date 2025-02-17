find_path(
    YAML_CPP_INCLUDE_DIR
    NAMES "yaml-cpp"
    PATHS "${DEPENDENCIES_PREFIX}/include"
    NO_DEFAULT_PATH
)
find_library(
    YAML_CPP_LIB
    NAMES "libyaml-cpp.a"
    PATHS "${DEPENDENCIES_PREFIX}/lib"
    NO_DEFAULT_PATH
)

if(YAML_CPP_LIB AND YAML_CPP_INCLUDE_DIR)
    message(STATUS "YAML_CPP_INCLUDE_DIR found: ${YAML_CPP_INCLUDE_DIR}")
    message(STATUS "YAML_CPP_LIB found: ${YAML_CPP_LIB}")
else()
    include(ExternalProject)
    ExternalProject_Add(
        "libyaml-cpp"
        PREFIX ${DEPENDENCIES_PREFIX}
        GIT_REPOSITORY "https://github.com/jbeder/yaml-cpp.git"
        GIT_TAG "0.8.0"
        CONFIGURE_COMMAND cd ${DEPENDENCIES_PREFIX}/src && mkdir -p libyaml-cpp-build
        BUILD_COMMAND cd ${DEPENDENCIES_PREFIX}/src/libyaml-cpp-build && ${CMAKE_COMMAND} -DCMAKE_INSTALL_PREFIX=${DEPENDENCIES_PREFIX} -DCMAKE_BUILD_TYPE=Release ../libyaml-cpp
        INSTALL_COMMAND cd ${DEPENDENCIES_PREFIX}/src/libyaml-cpp-build && ${CMAKE_COMMAND} --build . --target install
    )

    set(YAML_CPP_LIB "${DEPENDENCIES_PREFIX}/lib/libyaml-cpp.a")

endif()

list(APPEND LIBRARIES ${YAML_CPP_LIB})
