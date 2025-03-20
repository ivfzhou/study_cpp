set(ZSTD_DEPENDENCIES_PREFIX ${DEPENDENCIES_PREFIX}/zstd)

find_path(
    ZSTD_INCLUDE_DIR
    NAMES zstd.h
    PATHS ${ZSTD_DEPENDENCIES_PREFIX}/include
    NO_DEFAULT_PATH
)
find_library(
    ZSTD_LIB
    NAMES libzstd.a
    PATHS ${ZSTD_DEPENDENCIES_PREFIX}/lib
    NO_DEFAULT_PATH
)

if(ZSTD_LIB AND ZSTD_INCLUDE_DIR)
    message(STATUS "ZSTD_INCLUDE_DIR found: ${ZSTD_INCLUDE_DIR}")
    message(STATUS "ZSTD_LIB found: ${ZSTD_LIB}")
else()
    ExternalProject_Add(
        zstd
        PREFIX ${ZSTD_DEPENDENCIES_PREFIX}
        URL https://github.com/facebook/zstd/archive/refs/tags/v1.5.7.zip
        CONFIGURE_COMMAND cd ${ZSTD_DEPENDENCIES_PREFIX}/src/zstd
        BUILD_COMMAND cd ${ZSTD_DEPENDENCIES_PREFIX}/src/zstd && make -j
        INSTALL_COMMAND cd ${ZSTD_DEPENDENCIES_PREFIX}/src/zstd && make install PREFIX=${ZSTD_DEPENDENCIES_PREFIX}
    )
    set(ZSTD_INCLUDE_DIR ${ZSTD_DEPENDENCIES_PREFIX}/include)
    set(ZSTD_LIB ${ZSTD_DEPENDENCIES_PREFIX}/lib/libzstd.a)
endif()

include_directories(${ZSTD_INCLUDE_DIR})
list(APPEND LIBRARIES ${ZSTD_LIB})
