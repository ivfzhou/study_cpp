set(ZLIB_DEPENDENCIES_PREFIX ${DEPENDENCIES_PREFIX}/zlib)

find_path(
    ZLIB_INCLUDE_DIR
    NAMES zlib.h
    PATHS ${ZLIB_DEPENDENCIES_PREFIX}/include
    NO_DEFAULT_PATH
)
set(ZLIB_LIB_NAME zlibstatic.lib)
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(ZLIB_LIB_NAME zlibstaticd.lib)
endif()
find_library(
    ZLIB_LIB
    NAMES ${ZLIB_LIB_NAME}
    PATHS ${ZLIB_DEPENDENCIES_PREFIX}/lib
    NO_DEFAULT_PATH
)

if(ZLIB_LIB AND ZLIB_INCLUDE_DIR)
    message(STATUS "ZLIB_LIB found: ${ZLIB_LIB}")
    message(STATUS "ZLIB_INCLUDE_DIR found: ${ZLIB_INCLUDE_DIR}")
else()
    ExternalProject_Add(
        zlib
        PREFIX ${ZLIB_DEPENDENCIES_PREFIX}
        URL https://github.com/madler/zlib/archive/refs/tags/v1.3.1.zip
        CONFIGURE_COMMAND cd ${ZLIB_DEPENDENCIES_PREFIX}/src &&
        rd /s /q zlib-build && md zlib-build
        BUILD_COMMAND cd ${ZLIB_DEPENDENCIES_PREFIX}/src/zlib-build &&
        ${CMAKE_COMMAND} -DCMAKE_INSTALL_PREFIX=${ZLIB_DEPENDENCIES_PREFIX} -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
        -DBUILD_SHARED_LIBS=OFF -DZLIB_BUILD_EXAMPLES=OFF ../zlib
        INSTALL_COMMAND cd ${ZLIB_DEPENDENCIES_PREFIX}/src/zlib-build &&
        ${CMAKE_COMMAND} --build . --target install --config ${CMAKE_BUILD_TYPE}
    )
    set(ZLIB_LIB ${ZLIB_DEPENDENCIES_PREFIX}/lib/${ZLIB_LIB_NAME})
    set(ZLIB_INCLUDE_DIR ${ZLIB_DEPENDENCIES_PREFIX}/include)
endif()

include_directories(${ZLIB_INCLUDE_DIR})
list(APPEND LIBRARIES ${ZLIB_LIB})
