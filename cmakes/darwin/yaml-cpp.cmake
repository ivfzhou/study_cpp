set(YAML_CPP_DEPENDENCIES_PREFIX ${DEPENDENCIES_PREFIX}/yaml-cpp)

find_path(
    YAML_CPP_INCLUDE_DIR
    NAMES yaml-cpp
    PATHS ${YAML_CPP_DEPENDENCIES_PREFIX}/include
    NO_DEFAULT_PATH
)
find_library(
    YAML_CPP_LIB
    NAMES libyaml-cpp.a
    PATHS ${YAML_CPP_DEPENDENCIES_PREFIX}/lib
    NO_DEFAULT_PATH
)

if(YAML_CPP_LIB AND YAML_CPP_INCLUDE_DIR)
    message(STATUS "YAML_CPP_INCLUDE_DIR found: ${YAML_CPP_INCLUDE_DIR}")
    message(STATUS "YAML_CPP_LIB found: ${YAML_CPP_LIB}")
else()
    ExternalProject_Add(
        yaml-cpp
        PREFIX ${YAML_CPP_DEPENDENCIES_PREFIX}
        GIT_REPOSITORY https://github.com/jbeder/yaml-cpp.git
        GIT_TAG 0.8.0
        CONFIGURE_COMMAND cd ${YAML_CPP_DEPENDENCIES_PREFIX}/src && mkdir -p yaml-cpp-build
        BUILD_COMMAND cd ${YAML_CPP_DEPENDENCIES_PREFIX}/src/yaml-cpp-build && ${CMAKE_COMMAND} -DCMAKE_INSTALL_PREFIX=${YAML_CPP_DEPENDENCIES_PREFIX} -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE} ../yaml-cpp
        INSTALL_COMMAND cd ${YAML_CPP_DEPENDENCIES_PREFIX}/src/yaml-cpp-build && ${CMAKE_COMMAND} --build . --target install
    )
    set(YAML_CPP_INCLUDE_DIR ${YAML_CPP_DEPENDENCIES_PREFIX}/include)
    set(YAML_CPP_LIB ${YAML_CPP_DEPENDENCIES_PREFIX}/lib/libyaml-cpp.a)
endif()

include_directories(${YAML_CPP_INCLUDE_DIR})
list(APPEND LIBRARIES ${YAML_CPP_LIB})
