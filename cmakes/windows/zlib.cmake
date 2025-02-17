find_path(
    ZLIB_INCLUDE_DIR
    NAMES "zlib.h"
    PATHS "${DEPENDENCIES_PREFIX}/include"
    NO_DEFAULT_PATH
)
find_library(
    ZLIB_LIB
    NAMES zlibstatic.lib
    PATHS "${DEPENDENCIES_PREFIX}/lib"
    NO_DEFAULT_PATH
)

if(ZLIB_LIB AND ZLIB_INCLUDE_DIR)
    message(STATUS "ZLIB_LIB found: ${ZLIB_LIB}")
    message(STATUS "ZLIB_INCLUDE_DIR found: ${ZLIB_INCLUDE_DIR}")
else()
    include(ExternalProject)
    ExternalProject_Add(
        "libzlib"
        PREFIX ${DEPENDENCIES_PREFIX}
        GIT_REPOSITORY "https://github.com/madler/zlib.git"
        GIT_TAG "v1.3.1"
        CONFIGURE_COMMAND cd ${DEPENDENCIES_PREFIX}/src && if not exist libzlib-build (md libzlib-build)
        BUILD_COMMAND cd ${DEPENDENCIES_PREFIX}/src/libzlib-build && ${CMAKE_COMMAND} -DCMAKE_INSTALL_PREFIX=${DEPENDENCIES_PREFIX} -DZLIB_BUILD_EXAMPLES=OFF ../libzlib
        INSTALL_COMMAND cd ${DEPENDENCIES_PREFIX}/src/libzlib-build && ${CMAKE_COMMAND} --build . --target install --config Release
    )
    set(ZLIB_LIB "${DEPENDENCIES_PREFIX}/lib/zlibstatic.lib")
endif()

list(APPEND LIBRARIES ${ZLIB_LIB})
