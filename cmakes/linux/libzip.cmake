find_path(
    LIBZIP_INCLUDE_DIR
    NAMES "zip.h"
    PATHS "${DEPENDENCIES_PREFIX}/include"
    NO_DEFAULT_PATH
)
find_library(
    LIBZIP_LIB
    NAMES "libzip.a"
    PATHS "${DEPENDENCIES_PREFIX}/lib"
    NO_DEFAULT_PATH
)

if(LIBZIP_LIB AND LIBZIP_INCLUDE_DIR)
    message(STATUS "LIBZIP_INCLUDE_DIR found: ${LIBZIP_INCLUDE_DIR}")
    message(STATUS "LIBZIP_LIB found: ${LIBZIP_LIB}")
else()
    include(ExternalProject)
    ExternalProject_Add(
        liblibzip
        PREFIX ${DEPENDENCIES_PREFIX}
        GIT_REPOSITORY "https://github.com/nih-at/libzip.git"
        GIT_TAG "v1.11.3"
        CONFIGURE_COMMAND cd ${DEPENDENCIES_PREFIX}/src && mkdir -p liblibzip-build
        BUILD_COMMAND cd ${DEPENDENCIES_PREFIX}/src/liblibzip-build && ${CMAKE_COMMAND} -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=${DEPENDENCIES_PREFIX} -DBUILD_SHARED_LIBS=OFF ../liblibzip
        INSTALL_COMMAND cd ${DEPENDENCIES_PREFIX}/src/liblibzip-build && ${CMAKE_COMMAND} --build . --target install
    )

    set(LIBZIP_LIB "${DEPENDENCIES_PREFIX}/lib/libzip.a")

endif()

list(APPEND LIBRARIES ${LIBZIP_LIB})
