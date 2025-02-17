find_path(
    XZ_INCLUDE_DIR
    NAMES lzma.h
    PATHS ${DEPENDENCIES_PREFIX}/include
    NO_DEFAULT_PATH
)
find_library(
    XZ_LIB
    NAMES liblzma.a
    PATHS ${DEPENDENCIES_PREFIX}/lib
    NO_DEFAULT_PATH
)

if(XZ_LIB AND XZ_INCLUDE_DIR)
    message(STATUS "XZ_INCLUDE_DIR found: ${XZ_INCLUDE_DIR}")
    message(STATUS "XZ_LIB found: ${XZ_LIB}")
else()
    include(ExternalProject)
    ExternalProject_Add(
        liblzma
        PREFIX ${DEPENDENCIES_PREFIX}
        GIT_REPOSITORY "https://github.com/tukaani-project/xz.git"
        GIT_TAG "v5.6.4"
        CONFIGURE_COMMAND cd ${DEPENDENCIES_PREFIX}/src/liblzma && mkdir build || true
        BUILD_COMMAND cd ${DEPENDENCIES_PREFIX}/src/liblzma && cd build && cmake -DCMAKE_INSTALL_PREFIX=${DEPENDENCIES_PREFIX} -DBUILD_SHARED_LIBS=OFF -DCMAKE_BUILD_TYPE=Release .. && make -j
        INSTALL_COMMAND cd ${DEPENDENCIES_PREFIX}/src/liblzma && cd build && make install
    )

    set(XZ_LIB ${DEPENDENCIES_PREFIX}/lib/liblzma.a)

endif()

list(APPEND LIBRARIES ${XZ_LIB})
