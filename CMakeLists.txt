cmake_minimum_required(VERSION 3.25)

project(cpp LANGUAGES CXX VERSION 0.0.1)

message(STATUS "CMAKE_SYSTEM_NAME is ${CMAKE_SYSTEM_NAME}")
message(STATUS "CMAKE_C_COMPILER is ${CMAKE_C_COMPILER}")
message(STATUS "CMAKE_CXX_COMPILER is ${CMAKE_CXX_COMPILER}")
message(STATUS "CMAKE_CXX_COMPILER_VERSION is ${CMAKE_CXX_COMPILER_VERSION}")
message(STATUS "PROJECT_NAME is ${PROJECT_NAME}")
message(STATUS "CMAKE_SOURCE_DIR is ${CMAKE_SOURCE_DIR}")
message(STATUS "CMAKE_BINARY_DIR is ${CMAKE_BINARY_DIR}")
message(STATUS "CMAKE_SIZEOF_VOID_P is ${CMAKE_SIZEOF_VOID_P}")
message(STATUS "MSVC is ${MSVC}")
message(STATUS "CMAKE_CXX_FLAGS is ${CMAKE_CXX_FLAGS}")
message(STATUS "CMAKE_CXX_FLAGS_DEBUG is ${CMAKE_CXX_FLAGS_DEBUG}")
message(STATUS "CMAKE_CXX_FLAGS_RELEASE is ${CMAKE_CXX_FLAGS_RELEASE}")
message(STATUS "CMAKE_C_FLAGS is ${CMAKE_C_FLAGS}")
message(STATUS "CMAKE_C_FLAGS_DEBUG is ${CMAKE_C_FLAGS_DEBUG}")
message(STATUS "CMAKE_C_FLAGS_RELEASE is ${CMAKE_C_FLAGS_RELEASE}")

set(CMAKE_CXX_FLAGS_DEBUG "-finput-charset=UTF-8 -fexec-charset=UTF-8 --all-warnings -pedantic -Winline -O0 -Wall -g3 \
    -Wno-unused-variable -Wno-unused-but-set-variable -Wno-unused-function")
message(STATUS "set CMAKE_CXX_FLAGS_DEBUG is ${CMAKE_CXX_FLAGS_DEBUG}")
set(CMAKE_C_FLAGS_RELEASE "-finput-charset=UTF-8 -fexec-charset=UTF-8 -O3 -g0")
message(STATUS "set CMAKE_C_FLAGS_RELEASE is ${CMAKE_C_FLAGS_RELEASE}")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

string(TIMESTAMP DATETIME "%Y%m%d%H%M%S")
if (NOT DEFINED PROJECT_VERSION)
    set(PROJECT_VERSION "unknown")
endif ()
execute_process(
        COMMAND git rev-parse --short HEAD
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        OUTPUT_VARIABLE GIT_COMMIT_ID
        OUTPUT_STRIP_TRAILING_WHITESPACE
)
add_definitions(-DBUILD_DATETIME="${DATETIME}")
add_definitions(-DBUILD_VERSION="${PROJECT_VERSION}")
add_definitions(-DGIT_COMMIT_ID="${GIT_COMMIT_ID}")
message(STATUS "macro BUILD_DATATIME is ${DATETIME}")
message(STATUS "macro GIT_COMMIT_ID is ${GIT_COMMIT_ID}")

include_directories(${CMAKE_SOURCE_DIR})

add_executable(cpp)
file(GLOB SOURCES ${CMAKE_SOURCE_DIR}/*.cpp)
foreach (v ${SOURCES})
    get_filename_component(FILE_NAME ${v} NAME_WE)
    add_library(${FILE_NAME} OBJECT ${v})
    target_sources(cpp PRIVATE $<TARGET_OBJECTS:${FILE_NAME}>)
endforeach ()
