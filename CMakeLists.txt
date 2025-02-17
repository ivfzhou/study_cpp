cmake_minimum_required(VERSION 3.25)

project(cpp LANGUAGES CXX VERSION 0.0.1)

# 打印变量信息
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
message(STATUS "CMAKE_COMMAND is ${CMAKE_COMMAND}")
message(STATUS "CMAKE_BUILD_TYPE is ${CMAKE_BUILD_TYPE}")
message(STATUS "CMAKE_THREAD_PREFER_PTHREAD is ${CMAKE_THREAD_PREFER_PTHREAD}")
message(STATUS "THREADS_PREFER_PTHREAD_FLAG is ${THREADS_PREFER_PTHREAD_FLAG}")
message(STATUS "MSVC_RUNTIME_LIBRARY is ${MSVC_RUNTIME_LIBRARY}")

# 定义一些宏
string(TIMESTAMP DATETIME "%Y%m%d%H%M%S")
if(NOT DEFINED PROJECT_VERSION)
    set(PROJECT_VERSION "unknown")
endif()
execute_process(
    COMMAND git rev-parse --short HEAD
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    OUTPUT_VARIABLE GIT_COMMIT_ID
    OUTPUT_STRIP_TRAILING_WHITESPACE
)
add_definitions(-DBUILD_DATETIME="${DATETIME}")
add_definitions(-DBUILD_VERSION="${PROJECT_VERSION}")
add_definitions(-DGIT_COMMIT_ID="${GIT_COMMIT_ID}")
message(STATUS "macro BUILD_VERSION is ${PROJECT_VERSION}")
message(STATUS "macro BUILD_DATATIME is ${DATETIME}")
message(STATUS "macro GIT_COMMIT_ID is ${GIT_COMMIT_ID}")

# 搜集源码和头
file(GLOB SOURCES ${CMAKE_SOURCE_DIR}/*.cpp)
include_directories(${CMAKE_SOURCE_DIR})

# 依赖安装编译文件夹
set(DEPENDENCIES_PREFIX "${CMAKE_SOURCE_DIR}/dependencies")
include_directories("${DEPENDENCIES_PREFIX}/include")

# 包含其它脚本
if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    include(cmakes/windows.cmake)
elseif(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    include(cmakes/linux.cmake)
elseif(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    include(cmakes/darwin.cmake)
else()
    message(FATAL_ERROR "unknown operating system: ${CMAKE_SYSTEM_NAME}")
endif()

# 设置语言版本
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 编译对象文件
add_executable(cpp)
message(STATUS "SOURCES is ${SOURCES}")
foreach(v ${SOURCES})
    get_filename_component(FILE_NAME ${v} NAME_WE)
    add_library(${FILE_NAME} OBJECT ${v})
    target_sources(cpp PRIVATE $<TARGET_OBJECTS:${FILE_NAME}>)
endforeach()

# 链接库
message(STATUS "LIBRARIES is ${LIBRARIES}")
target_link_libraries(cpp ${LIBRARIES})
