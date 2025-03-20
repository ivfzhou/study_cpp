set(OPENSSL_DEPENDENCIES_PREFIX ${DEPENDENCIES_PREFIX}/openssl)

find_path(
    OPENSSL_INCLUDE_DIR
    NAMES openssl
    PATHS ${OPENSSL_DEPENDENCIES_PREFIX}/include
    NO_DEFAULT_PATH
)
find_library(
    OPENSSL_LIB
    NAMES libssl.lib
    PATHS ${OPENSSL_DEPENDENCIES_PREFIX}/lib
    NO_DEFAULT_PATH
)
find_library(
    CRYPTO_LIB
    NAMES libcrypto.lib
    PATHS ${OPENSSL_DEPENDENCIES_PREFIX}/lib
    NO_DEFAULT_PATH
)

if(OPENSSL_INCLUDE_DIR AND OPENSSL_LIB AND CRYPTO_LIB)
    message(STATUS "OPENSSL_INCLUDE_DIR found: ${OPENSSL_INCLUDE_DIR}")
    message(STATUS "OPENSSL_LIB found: ${OPENSSL_LIB}")
    message(STATUS "CRYPTO_LIB found: ${CRYPTO_LIB}")
else()
    string(TOLOWER ${CMAKE_BUILD_TYPE} OPENSSL_BUILD_TYPE)
    ExternalProject_Add(
        openssl
        PREFIX ${OPENSSL_DEPENDENCIES_PREFIX}
        URL https://github.com/openssl/openssl/archive/refs/tags/openssl-3.4.1.zip
        CONFIGURE_COMMAND cd ${OPENSSL_DEPENDENCIES_PREFIX}/src/openssl &&
        perl Configure no-shared no-deprecated --prefix=${OPENSSL_DEPENDENCIES_PREFIX} --${OPENSSL_BUILD_TYPE}
        BUILD_COMMAND cd ${OPENSSL_DEPENDENCIES_PREFIX}/src/openssl && nmake /I .
        INSTALL_COMMAND cd ${OPENSSL_DEPENDENCIES_PREFIX}/src/openssl && nmake install /I .
    )
    set(OPENSSL_LIB ${OPENSSL_DEPENDENCIES_PREFIX}/lib/libssl.lib)
    set(CRYPTO_LIB ${OPENSSL_DEPENDENCIES_PREFIX}/lib/libcrypto.lib)
    set(OPENSSL_INCLUDE_DIR ${OPENSSL_DEPENDENCIES_PREFIX}/include)
endif()

include_directories(${OPENSSL_INCLUDE_DIR})
list(APPEND LIBRARIES ${OPENSSL_LIB})
list(APPEND LIBRARIES ${CRYPTO_LIB})
