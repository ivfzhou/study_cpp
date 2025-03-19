set(LIBZIP_DEPENDENCIES_PREFIX ${DEPENDENCIES_PREFIX}/libzip)

find_path(
    LIBZIP_INCLUDE_DIR
    NAMES zip.h
    PATHS ${LIBZIP_DEPENDENCIES_PREFIX}/include
    NO_DEFAULT_PATH
)
find_library(
    LIBZIP_LIB
    NAMES libzip.a
    PATHS ${LIBZIP_DEPENDENCIES_PREFIX}/lib
    NO_DEFAULT_PATH
)

if(LIBZIP_LIB AND LIBZIP_INCLUDE_DIR)
    message(STATUS "LIBZIP_INCLUDE_DIR found: ${LIBZIP_INCLUDE_DIR}")
    message(STATUS "LIBZIP_LIB found: ${LIBZIP_LIB}")
else()
    ExternalProject_Add(
        libzip
        PREFIX ${LIBZIP_DEPENDENCIES_PREFIX}
        GIT_REPOSITORY https://github.com/nih-at/libzip.git
        GIT_TAG v1.11.3
        CONFIGURE_COMMAND cd ${LIBZIP_DEPENDENCIES_PREFIX}/src && mkdir -p libzip-build
        BUILD_COMMAND cd ${LIBZIP_DEPENDENCIES_PREFIX}/src/libzip-build && ${CMAKE_COMMAND} -DCMAKE_INSTALL_PREFIX=${LIBZIP_DEPENDENCIES_PREFIX} -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE} ../libzip
        INSTALL_COMMAND cd ${LIBZIP_DEPENDENCIES_PREFIX}/src/libzip-build && ${CMAKE_COMMAND} --build . --target install
    )
    set(LIBZIP_INCLUDE_DIR ${LIBZIP_DEPENDENCIES_PREFIX}/include)
    set(LIBZIP_LIB ${LIBZIP_DEPENDENCIES_PREFIX}/lib/libzip.a)
endif()

include_directories(${LIBZIP_INCLUDE_DIR})
list(APPEND LIBRARIES ${LIBZIP_LIB})
