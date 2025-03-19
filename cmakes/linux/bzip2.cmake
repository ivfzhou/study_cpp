set(BZIP2_DEPENDENCIES_PREFIX ${DEPENDENCIES_PREFIX}/bzip2)

find_path(
    BZIP2_INCLUDE_DIR
    NAMES bzlib.h
    PATHS ${BZIP2_DEPENDENCIES_PREFIX}/include
    NO_DEFAULT_PATH
)
find_library(
    BZIP2_LIB
    NAMES libbz2.a
    PATHS ${BZIP2_DEPENDENCIES_PREFIX}/lib
    NO_DEFAULT_PATH
)

if(BZIP2_LIB AND BZIP2_INCLUDE_DIR)
    message(STATUS "BZIP2_INCLUDE_DIR found: ${BZIP2_INCLUDE_DIR}")
    message(STATUS "BZIP2_LIB found: ${BZIP2_LIB}")
else()
    ExternalProject_Add(
        bzip2
        PREFIX ${BZIP2_DEPENDENCIES_PREFIX}
        GIT_REPOSITORY https://github.com/libarchive/bzip2.git
        GIT_TAG bzip2-1.0.8
        CONFIGURE_COMMAND cd ${BZIP2_DEPENDENCIES_PREFIX}/src/bzip2
        BUILD_COMMAND cd ${BZIP2_DEPENDENCIES_PREFIX}/src/bzip2 && make -j
        INSTALL_COMMAND cd ${BZIP2_DEPENDENCIES_PREFIX}/src/libbzip2 && make install PREFIX=${BZIP2_DEPENDENCIES_PREFIX}
    )
    set(BZIP2_LIB ${BZIP2_DEPENDENCIES_PREFIX}/lib/libbz2.a)
    set(BZIP2_INCLUDE_DIR ${BZIP2_DEPENDENCIES_PREFIX}/include)
endif()

include_directories(${BZIP2_INCLUDE_DIR})
list(APPEND LIBRARIES ${BZIP2_LIB})
