set(YAML_CPP_DEPENDENCIES_PREFIX ${DEPENDENCIES_PREFIX}/yaml-cpp)

find_path(
    YAML_CPP_INCLUDE_DIR
    NAMES yaml-cpp
    PATHS ${YAML_CPP_DEPENDENCIES_PREFIX}/include
    NO_DEFAULT_PATH
)
set(YAML_CPP_LIB_NAME yaml-cpp.lib)
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(MSVC_RUNTIME_LIBRARY_SUFFIX Debug)
    set(YAML_CPP_LIB_NAME yaml-cppd.lib)
endif()
find_library(
    YAML_CPP_LIB
    NAMES ${YAML_CPP_LIB_NAME}
    PATHS ${YAML_CPP_DEPENDENCIES_PREFIX}/lib
    NO_DEFAULT_PATH
)

if(YAML_CPP_LIB AND YAML_CPP_INCLUDE_DIR)
    message(STATUS "YAML_CPP_LIB found: ${YAML_CPP_LIB}")
    message(STATUS "YAML_CPP_INCLUDE_DIR found: ${YAML_CPP_INCLUDE_DIR}")
else()
    ExternalProject_Add(
        yaml-cpp
        PREFIX ${YAML_CPP_DEPENDENCIES_PREFIX}
        GIT_REPOSITORY https://github.com/jbeder/yaml-cpp.git
        GIT_TAG 0.8.0
        CONFIGURE_COMMAND cd ${YAML_CPP_DEPENDENCIES_PREFIX}/src && if not exist yaml-cpp-build (md yaml-cpp-build)
        BUILD_COMMAND cd ${YAML_CPP_DEPENDENCIES_PREFIX}/src/yaml-cpp-build && ${CMAKE_COMMAND} -DCMAKE_INSTALL_PREFIX=${YAML_CPP_DEPENDENCIES_PREFIX} -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE} -DCMAKE_MSVC_RUNTIME_LIBRARY=MultiThreaded${MSVC_RUNTIME_LIBRARY_SUFFIX} ../yaml-cpp
        INSTALL_COMMAND cd ${YAML_CPP_DEPENDENCIES_PREFIX}/src/yaml-cpp-build && ${CMAKE_COMMAND} --build . --target install --config ${CMAKE_BUILD_TYPE}
    )
    set(YAML_CPP_LIB ${YAML_CPP_DEPENDENCIES_PREFIX}/lib/${YAML_CPP_LIB_NAME})
    set(YAML_CPP_INCLUDE_DIR ${YAML_CPP_DEPENDENCIES_PREFIX}/include)
endif()

include_directories(${YAML_CPP_INCLUDE_DIR})
list(APPEND LIBRARIES ${YAML_CPP_LIB})
