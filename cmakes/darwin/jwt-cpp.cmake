find_path(
    JWT_INCLUDE_DIR
    NAMES jwt
    PATHS ${DEPENDENCIES_PREFIX}/include
    NO_DEFAULT_PATH
)
find_library(
    JWT_LIB
    NAMES libjwt.a
    PATHS ${DEPENDENCIES_PREFIX}/lib
    NO_DEFAULT_PATH
)

if(JWT_LIB AND JWT_INCLUDE_DIR)
    message(STATUS "JWT_INCLUDE_DIR found: ${JWT_INCLUDE_DIR}")
    message(STATUS "JWT_LIB found: ${JWT_LIB}")
else()
    include(ExternalProject)
    ExternalProject_Add(libjwt
        PREFIX ${DEPENDENCIES_PREFIX}
        GIT_REPOSITORY "https://github.com/pokowaka/jwt-cpp.git"
        GIT_TAG "v1.1"
        CONFIGURE_COMMAND cd ${DEPENDENCIES_PREFIX}/src/libjwt && mkdir build && cd build || true
        BUILD_COMMAND cd ${DEPENDENCIES_PREFIX}/src/libjwt && cd build && cmake -DCMAKE_INSTALL_PREFIX=${DEPENDENCIES_PREFIX} -DOPENSSL_INCLUDE_DIRS=${DEPENDENCIES_PREFIX}/include -DOPENSSL_LIBRARY_DIRS=${DEPENDENCIES_PREFIX}/${LIB_DIR} -DOPENSSL_LIBRARIES=${DEPENDENCIES_PREFIX}/${LIB_DIR}/libcrypto.a -DENABLE_TESTS=OFF -DCMAKE_BUILD_TYPE=Release ..
        INSTALL_COMMAND cd ${DEPENDENCIES_PREFIX}/src/libjwt && cd build make -j && make install
    )
    set(JWT_LIB ${DEPENDENCIES_PREFIX}/lib/libjwt.a)
endif()

list(APPEND LIBRARIES ${JWT_LIB})
