find_path(
    ZSTD_INCLUDE_DIR
    NAMES "zstd.h"
    PATHS "${DEPENDENCIES_PREFIX}/include"
    NO_DEFAULT_PATH
)
find_library(
    ZSTD_LIB
    NAMES "libzstd.a"
    PATHS "${DEPENDENCIES_PREFIX}/lib"
    NO_DEFAULT_PATH
)

if(ZSTD_LIB AND ZSTD_INCLUDE_DIR)
    message(STATUS "ZSTD_INCLUDE_DIR found: ${ZSTD_INCLUDE_DIR}")
    message(STATUS "ZSTD_LIB found: ${ZSTD_LIB}")
else()
    include(ExternalProject)
    ExternalProject_Add(
        libzstd
        PREFIX ${DEPENDENCIES_PREFIX}
        GIT_REPOSITORY "https://github.com/facebook/zstd.git"
        GIT_TAG "v1.5.6"
        CONFIGURE_COMMAND cd ${DEPENDENCIES_PREFIX}/src/libzstd
        BUILD_COMMAND cd ${DEPENDENCIES_PREFIX}/src/libzstd && make -j
        INSTALL_COMMAND cd ${DEPENDENCIES_PREFIX}/src/libzstd && make install PREFIX=${DEPENDENCIES_PREFIX}
    )
    set(ZSTD_LIB "${DEPENDENCIES_PREFIX}/lib/libzstd.a")
endif()

list(APPEND LIBRARIES ${ZSTD_LIB})
