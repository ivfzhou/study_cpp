set(LIBZIP_DEPENDENCIES_PREFIX ${DEPENDENCIES_PREFIX}/libzip)

find_path(
    LIBZIP_INCLUDE_DIR
    NAMES zip.h
    PATHS ${LIBZIP_DEPENDENCIES_PREFIX}/include
    NO_DEFAULT_PATH
)

find_library(
    LIBZIP_LIB
    NAMES zip.lib
    PATHS ${LIBZIP_DEPENDENCIES_PREFIX}/lib
    NO_DEFAULT_PATH
)

if(LIBZIP_LIB AND LIBZIP_INCLUDE_DIR)
    message(STATUS "LIBZIP_LIB found: ${LIBZIP_LIB}")
    message(STATUS "LIBZIP_INCLUDE_DIR found: ${LIBZIP_INCLUDE_DIR}")
else()
    ExternalProject_Add(
        libzip
        PREFIX ${LIBZIP_DEPENDENCIES_PREFIX}
        URL https://github.com/nih-at/libzip/archive/refs/tags/v1.11.3.zip
        CONFIGURE_COMMAND cd ${LIBZIP_DEPENDENCIES_PREFIX}/src &&
        rd /s /q libzip-build && md libzip-build
        BUILD_COMMAND cd ${LIBZIP_DEPENDENCIES_PREFIX}/src/libzip-build &&
        ${CMAKE_COMMAND} -DCMAKE_INSTALL_PREFIX=${LIBZIP_DEPENDENCIES_PREFIX} -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
        -DBUILD_SHARED_LIBS=OFF -DZLIB_LIBRARY=${ZLIB_LIB} -DZLIB_INCLUDE_DIR=${ZLIB_INCLUDE_DIR} ../libzip
        INSTALL_COMMAND cd ${LIBZIP_DEPENDENCIES_PREFIX}/src/libzip-build &&
        ${CMAKE_COMMAND} --build . --target install --config ${CMAKE_BUILD_TYPE}
    )
    set(LIBZIP_LIB ${LIBZIP_DEPENDENCIES_PREFIX}/lib/zip.lib)
    set(LIBZIP_INCLUDE_DIR ${LIBZIP_DEPENDENCIES_PREFIX}/include)
endif()

include_directories(${LIBZIP_INCLUDE_DIR})
list(APPEND LIBRARIES ${LIBZIP_LIB})
