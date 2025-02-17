find_path(
    YAML_CPP_INCLUDE_DIR
    NAMES "yaml-cpp"
    PATHS "${DEPENDENCIES_PREFIX}/include"
    NO_DEFAULT_PATH
)
set(YAML_CPP_LIB_NAME "yaml-cpp.lib")
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(MSVC_RUNTIME_LIBRARY_POSTFIX Debug)
    set(YAML_CPP_LIB_NAME "yaml-cppd.lib")
endif()
find_library(
    YAML_CPP_LIB
    NAMES ${YAML_CPP_LIB_NAME}
    PATHS "${DEPENDENCIES_PREFIX}/lib"
    NO_DEFAULT_PATH
)

if(YAML_CPP_LIB AND YAML_CPP_INCLUDE_DIR)
    message(STATUS "YAML_CPP_LIB found: ${YAML_CPP_LIB}")
    message(STATUS "YAML_CPP_INCLUDE_DIR found: ${YAML_CPP_INCLUDE_DIR}")
else()
    include(ExternalProject)
    ExternalProject_Add(
        "libyaml-cpp"
        PREFIX ${DEPENDENCIES_PREFIX}
        GIT_REPOSITORY "https://github.com/jbeder/yaml-cpp.git"
        GIT_TAG "0.8.0"
        CONFIGURE_COMMAND cd ${DEPENDENCIES_PREFIX}/src && if not exist libyaml-cpp-build (md libyaml-cpp-build)
        BUILD_COMMAND cd ${DEPENDENCIES_PREFIX}/src/libyaml-cpp-build && ${CMAKE_COMMAND} -DYAML_MSVC_SHARED_RT=OFF -DCMAKE_MSVC_RUNTIME_LIBRARY=MultiThreaded${MSVC_RUNTIME_LIBRARY_POSTFIX} -DCMAKE_INSTALL_PREFIX=${DEPENDENCIES_PREFIX} ../libyaml-cpp
        INSTALL_COMMAND cd ${DEPENDENCIES_PREFIX}/src/libyaml-cpp-build && ${CMAKE_COMMAND} --build . --target install --config ${CMAKE_BUILD_TYPE}
    )
    set(YAML_CPP_LIB "${DEPENDENCIES_PREFIX}/lib/${YAML_CPP_LIB_NAME}")
endif()

list(APPEND LIBRARIES ${YAML_CPP_LIB})
