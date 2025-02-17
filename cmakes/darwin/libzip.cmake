find_path(
    ZIP_INCLUDE_DIR
    NAMES zip.h
    PATHS ${DEPENDENCIES_PREFIX}/include
    NO_DEFAULT_PATH
)
find_library(
    ZIP_LIB
    NAMES libzip.a
    PATHS ${DEPENDENCIES_PREFIX}/lib
    NO_DEFAULT_PATH
)

if(ZIP_LIB AND ZIP_INCLUDE_DIR)
    message(STATUS "ZIP_INCLUDE_DIR found: ${ZIP_INCLUDE_DIR}")
    message(STATUS "ZIP_LIB found: ${ZIP_LIB}")
else()
    include(ExternalProject)
    ExternalProject_Add(
        liblibzip
        PREFIX ${DEPENDENCIES_PREFIX}
        GIT_REPOSITORY "https://github.com/nih-at/libzip.git"
        GIT_TAG "v1.11.3"
        CONFIGURE_COMMAND cd ${DEPENDENCIES_PREFIX}/src/libzip && mkdir build || true
        BUILD_COMMAND cd ${DEPENDENCIES_PREFIX}/src/libzip && cd build && cmake -DCMAKE_INSTALL_PREFIX=${DEPENDENCIES_PREFIX} -DBUILD_SHARED_LIBS=OFF .. && make -j
        INSTALL_COMMAND cd ${DEPENDENCIES_PREFIX}/src/libzip && cd build && make install
    )
    set(ZIP_LIB ${DEPENDENCIES_PREFIX}/lib/libzip.a)
endif()

list(APPEND LIBRARIES ${ZIP_LIB})
