set(OPENSSL_DEPENDENCIES_PREFIX ${DEPENDENCIES_PREFIX}/openssl)

find_path(
    OPENSSL_INCLUDE_DIR
    NAMES openssl
    PATHS ${OPENSSL_DEPENDENCIES_PREFIX}/include
    NO_DEFAULT_PATH
)
if(CMAKE_SIZEOF_VOID_P EQUAL 4)
    set(LIB_DIR lib)
elseif(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(LIB_DIR lib64)
endif()
set(OPENSSL_LIB_DIR ${OPENSSL_DEPENDENCIES_PREFIX}/${LIB_DIR})
find_library(
    OPENSSL_LIB
    NAMES libssl.a
    PATHS ${OPENSSL_DEPENDENCIES_PREFIX}/${LIB_DIR}
    NO_DEFAULT_PATH
)
find_library(
    CRYPTO_LIB
    NAMES libcrypto.a
    PATHS ${OPENSSL_DEPENDENCIES_PREFIX}/${LIB_DIR}
    NO_DEFAULT_PATH
)

if(OPENSSL_LIB AND OPENSSL_INCLUDE_DIR AND CRYPTO_LIB)
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
        ./config no-shared no-deprecated --prefix=${OPENSSL_DEPENDENCIES_PREFIX} --${OPENSSL_BUILD_TYPE}
        BUILD_COMMAND cd ${OPENSSL_DEPENDENCIES_PREFIX}/src/openssl && make -j
        INSTALL_COMMAND cd ${OPENSSL_DEPENDENCIES_PREFIX}/src/openssl && sudo make install
    )
    set(OPENSSL_LIB ${OPENSSL_DEPENDENCIES_PREFIX}/${LIB_DIR}/libssl.a)
    set(CRYPTO_LIB ${OPENSSL_DEPENDENCIES_PREFIX}/${LIB_DIR}/libcrypto.a)
    set(OPENSSL_INCLUDE_DIR ${OPENSSL_DEPENDENCIES_PREFIX}/include)
endif()

include_directories(${OPENSSL_INCLUDE_DIR})
list(APPEND LIBRARIES ${OPENSSL_LIB})
list(APPEND LIBRARIES ${CRYPTO_LIB})
