cmake_minimum_required(VERSION 3.25)
set(VERSION "0.1.0")
project(ipasigner LANGUAGES C CXX VERSION ${VERSION})

string(TIMESTAMP BUILT_TIME "%Y%m%d%H%M%S")
add_definitions(-DVERSION="${VERSION}" -DBUILT_TIME="${BUILT_TIME}")

set(CMAKE_CXX_STANDARD 20)
add_executable(ipasigner config.cpp main.cpp)

include(FetchContent)
FetchContent_Declare(
        argparse
        GIT_REPOSITORY https://github.com/p-ranav/argparse.git
        GIT_TAG v3.0
)
FetchContent_MakeAvailable(argparse)

FetchContent_Declare(
        yaml-cpp
        GIT_REPOSITORY https://github.com/jbeder/yaml-cpp.git
        GIT_TAG 0.8.0
)
#FetchContent_GetProperties(yaml-cpp)
FetchContent_MakeAvailable(yaml-cpp)

if(NOT yaml-cpp_POPULATED)
    message(STATUS "Fetching yaml-cpp...")
    FetchContent_Populate(yaml-cpp)
    add_subdirectory(${yaml-cpp_SOURCE_DIR} ${yaml-cpp_BINARY_DIR})
endif()

target_link_libraries(ipasigner yaml-cpp::yaml-cpp argparse)
