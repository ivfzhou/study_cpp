find_path(
    XZ_INCLUDE_DIR
    NAMES "lzma.h"
    PATHS "${DEPENDENCIES_PREFIX}/include"
    NO_DEFAULT_PATH
)
find_library(
    XZ_LIB
    NAMES "liblzma.a"
    PATHS ${DEPENDENCIES_PREFIX}/lib
    NO_DEFAULT_PATH
)

if(XZ_LIB AND XZ_INCLUDE_DIR)
    message(STATUS "XZ_INCLUDE_DIR found: ${XZ_INCLUDE_DIR}")
    message(STATUS "XZ_LIB found: ${XZ_LIB}")
else()
    include(ExternalProject)
    ExternalProject_Add(
        libxz
        PREFIX ${DEPENDENCIES_PREFIX}
        GIT_REPOSITORY "https://github.com/tukaani-project/xz.git"
        GIT_TAG "v5.6.4"
        CONFIGURE_COMMAND cd ${DEPENDENCIES_PREFIX}/src && mkdir -p libxz-build
        BUILD_COMMAND cd ${DEPENDENCIES_PREFIX}/src/libxz-build && ${CMAKE_COMMAND} -DCMAKE_INSTALL_PREFIX=${DEPENDENCIES_PREFIX} -DBUILD_SHARED_LIBS=OFF -DCMAKE_BUILD_TYPE=Release -DBUILD_TESTING=OFF ../libxz
        INSTALL_COMMAND cd ${DEPENDENCIES_PREFIX}/src/libxz-build && ${CMAKE_COMMAND} --build . --target install
    )
    set(XZ_LIB ${DEPENDENCIES_PREFIX}/lib/liblzma.a)
endif()

list(APPEND LIBRARIES ${XZ_LIB})
