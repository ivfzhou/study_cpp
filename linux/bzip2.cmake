find_path(
    BZIP2_INCLUDE_DIR
    NAMES "bzlib.h"
    PATHS "${DEPENDENCIES_PREFIX}/include"
    NO_DEFAULT_PATH
)
find_library(
    BZIP2_LIB
    NAMES "libbz2.a"
    PATHS "${DEPENDENCIES_PREFIX}/lib"
    NO_DEFAULT_PATH
)

if(BZIP2_LIB AND BZIP2_INCLUDE_DIR)
    message(STATUS "BZIP2_INCLUDE_DIR found: ${BZIP2_INCLUDE_DIR}")
    message(STATUS "BZIP2_LIB found: ${BZIP2_LIB}")
else()
    include(ExternalProject)
    ExternalProject_Add(
        libbzip2
        PREFIX ${DEPENDENCIES_PREFIX}
        GIT_REPOSITORY "https://github.com/libarchive/bzip2.git"
        GIT_TAG "bzip2-1.0.8"
        CONFIGURE_COMMAND cd ${DEPENDENCIES_PREFIX}/src/libbzip2
        BUILD_COMMAND cd ${DEPENDENCIES_PREFIX}/src/libbzip2 && make -j
        INSTALL_COMMAND cd ${DEPENDENCIES_PREFIX}/src/libbzip2 && make install PREFIX=${DEPENDENCIES_PREFIX}
    )
    set(BZIP2_LIB "${DEPENDENCIES_PREFIX}/lib/libbz2.a")
endif()

list(APPEND LIBRARIES ${BZIP2_LIB})
