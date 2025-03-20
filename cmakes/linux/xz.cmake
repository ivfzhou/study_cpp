set(XZ_DEPENDENCIES_PREFIX ${DEPENDENCIES_PREFIX}/xz)

find_path(
    XZ_INCLUDE_DIR
    NAMES lzma.h
    PATHS ${XZ_DEPENDENCIES_PREFIX}/include
    NO_DEFAULT_PATH
)
find_library(
    XZ_LIB
    NAMES liblzma.a
    PATHS ${XZ_DEPENDENCIES_PREFIX}/lib
    NO_DEFAULT_PATH
)

if(XZ_LIB AND XZ_INCLUDE_DIR)
    message(STATUS "XZ_INCLUDE_DIR found: ${XZ_INCLUDE_DIR}")
    message(STATUS "XZ_LIB found: ${XZ_LIB}")
else()
    ExternalProject_Add(
        xz
        PREFIX ${XZ_DEPENDENCIES_PREFIX}
        URL https://github.com/tukaani-project/xz/archive/refs/tags/v5.6.4.zip
        CONFIGURE_COMMAND cd ${XZ_DEPENDENCIES_PREFIX}/src && rm -rf xz-build && mkdir -p xz-build
        BUILD_COMMAND cd ${XZ_DEPENDENCIES_PREFIX}/src/xz-build &&
        ${CMAKE_COMMAND} -DCMAKE_INSTALL_PREFIX=${XZ_DEPENDENCIES_PREFIX} -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
        -DBUILD_SHARED_LIBS=OFF -DBUILD_TESTING=OFF ../xz
        INSTALL_COMMAND cd ${XZ_DEPENDENCIES_PREFIX}/src/xz-build && ${CMAKE_COMMAND} --build . --target install
    )
    set(XZ_LIB ${XZ_DEPENDENCIES_PREFIX}/lib/liblzma.a)
endif()

list(APPEND LIBRARIES ${XZ_LIB})
