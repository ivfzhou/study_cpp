find_path(
    OPENSSL_INCLUDE_DIR
    NAMES openssl
    PATHS ${DEPENDENCIES_PREFIX}/include
    NO_DEFAULT_PATH
)
find_library(
    OPENSSL_LIB
    NAMES libssl.a
    PATHS ${DEPENDENCIES_PREFIX}/lib
    NO_DEFAULT_PATH
)
find_library(
    CRYPTO_LIB
    NAMES libcrypto.a
    PATHS ${DEPENDENCIES_PREFIX}/lib
    NO_DEFAULT_PATH
)

if(OPENSSL_LIB AND OPENSSL_INCLUDE_DIR AND CRYPTO_LIB)
    message(STATUS "OPENSSL_INCLUDE_DIR found: ${OPENSSL_INCLUDE_DIR}")
    message(STATUS "OPENSSL_LIB found: ${OPENSSL_LIB}")
    message(STATUS "CRYPTO_LIB found: ${CRYPTO_LIB}")
else()
    include(ExternalProject)
    ExternalProject_Add(
        libopenssl
        PREFIX ${DEPENDENCIES_PREFIX}
        GIT_REPOSITORY "https://github.com/openssl/openssl.git"
        GIT_TAG "openssl-3.4.1"
        CONFIGURE_COMMAND cd ${DEPENDENCIES_PREFIX}/src/libopenssl && ./Configure no-shared --prefix=${DEPENDENCIES_PREFIX} darwin64-x86_64-cc
        BUILD_COMMAND cd ${DEPENDENCIES_PREFIX}/src/libopenssl && make -j
        INSTALL_COMMAND cd ${DEPENDENCIES_PREFIX}/src/libopenssl && make install
    )
    set(CRYPTO_LIB ${DEPENDENCIES_PREFIX}/lib/libcrypto.a)
    set(OPENSSL_LIB ${DEPENDENCIES_PREFIX}/lib/libssl.a)
endif()

list(APPEND LIBRARIES ${CRYPTO_LIB})
list(APPEND LIBRARIES ${OPENSSL_LIB})
