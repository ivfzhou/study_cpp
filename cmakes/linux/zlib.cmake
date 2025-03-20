set(ZLIB_DEPENDENCIES_PREFIX ${DEPENDENCIES_PREFIX}/zlib)

find_path(
    ZLIB_INCLUDE_DIR
    NAMES zlib.h
    PATHS ${ZLIB_DEPENDENCIES_PREFIX}/include
    NO_DEFAULT_PATH
)
find_library(
    ZLIB_LIB
    NAMES libz.a
    PATHS ${ZLIB_DEPENDENCIES_PREFIX}/lib
    NO_DEFAULT_PATH
)

if(ZLIB_INCLUDE_DIR AND ZLIB_LIB)
    message(STATUS "ZLIB_INCLUDE_DIR found: ${ZLIB_INCLUDE_DIR}")
    message(STATUS "ZLIB_LIB found: ${ZLIB_LIB}")
else()
    ExternalProject_Add(
        zlib
        PREFIX ${ZLIB_DEPENDENCIES_PREFIX}
        URL https://github.com/madler/zlib/archive/refs/tags/v1.3.1.zip
        CONFIGURE_COMMAND cd ${ZLIB_DEPENDENCIES_PREFIX}/src && rm -rf zlib-build && mkdir -p zlib-build
        BUILD_COMMAND cd ${ZLIB_DEPENDENCIES_PREFIX}/src/zlib-build &&
        ${CMAKE_COMMAND} -DCMAKE_INSTALL_PREFIX=${ZLIB_DEPENDENCIES_PREFIX} -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
        -DBUILD_SHARED_LIBS=OFF -DZLIB_BUILD_EXAMPLES=OFF ../zlib
        INSTALL_COMMAND cd ${ZLIB_DEPENDENCIES_PREFIX}/src/zlib-build && ${CMAKE_COMMAND} --build . --target install
    )
    set(ZLIB_INCLUDE_DIR ${ZLIB_DEPENDENCIES_PREFIX}/include)
    set(ZLIB_LIB ${ZLIB_DEPENDENCIES_PREFIX}/lib/libz.a)
endif()

include_directories(${ZLIB_INCLUDE_DIR})
list(APPEND LIBRARIES ${ZLIB_LIB})
