set(YAML_CPP_DEPENDENCIES_PREFIX ${DEPENDENCIES_PREFIX}/yaml-cpp)

find_path(
    YAML_CPP_INCLUDE_DIR
    NAMES yaml-cpp
    PATHS ${YAML_CPP_DEPENDENCIES_PREFIX}/include
    NO_DEFAULT_PATH
)
set(YAML_CPP_LIB_NAME libyaml-cpp.a)
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(YAML_CPP_LIB_NAME libyaml-cppd.a)
endif()
find_library(
    YAML_CPP_LIB
    NAMES ${YAML_CPP_LIB_NAME}
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
        URL https://github.com/jbeder/yaml-cpp/archive/refs/tags/0.8.0.zip
        CONFIGURE_COMMAND cd ${YAML_CPP_DEPENDENCIES_PREFIX}/src && rm -rf yaml-cpp-build && mkdir -p yaml-cpp-build
        BUILD_COMMAND cd ${YAML_CPP_DEPENDENCIES_PREFIX}/src/yaml-cpp-build &&
        ${CMAKE_COMMAND} -DCMAKE_INSTALL_PREFIX=${YAML_CPP_DEPENDENCIES_PREFIX} -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
        -DBUILD_SHARED_LIBS=OFF ../yaml-cpp
        INSTALL_COMMAND cd ${YAML_CPP_DEPENDENCIES_PREFIX}/src/yaml-cpp-build &&
        ${CMAKE_COMMAND} --build . --target install
    )
    set(YAML_CPP_INCLUDE_DIR ${YAML_CPP_DEPENDENCIES_PREFIX}/include)
    set(YAML_CPP_LIB ${YAML_CPP_DEPENDENCIES_PREFIX}/lib/${YAML_CPP_LIB_NAME})
endif()

add_definitions(-DYAML_CPP_STATIC_DEFINE=1)
include_directories(${YAML_CPP_INCLUDE_DIR})
list(APPEND LIBRARIES ${YAML_CPP_LIB})
