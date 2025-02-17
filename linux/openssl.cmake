find_path(
    OPENSSL_INCLUDE_DIR
    NAMES "openssl"
    PATHS "${DEPENDENCIES_PREFIX}/include"
    NO_DEFAULT_PATH
)
if(CMAKE_SIZEOF_VOID_P EQUAL 4)
    set(LIB_DIR "lib")
elseif(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(LIB_DIR "lib64")
endif()
find_library(
    OPENSSL_LIB
    NAMES "libssl.a"
    PATHS "${DEPENDENCIES_PREFIX}/${LIB_DIR}"
    NO_DEFAULT_PATH
)
find_library(
    CRYPTO_LIB
    NAMES "libcrypto.a"
    PATHS "${DEPENDENCIES_PREFIX}/${LIB_DIR}"
    NO_DEFAULT_PATH
)

if(OPENSSL_LIB AND OPENSSL_INCLUDE_DIR AND CRYPTO_LIB)
    message(STATUS "OPENSSL_INCLUDE_DIR found: ${OPENSSL_INCLUDE_DIR}")
    message(STATUS "OPENSSL_LIB found: ${OPENSSL_LIB}")
    message(STATUS "CRYPTO_LIB found: ${CRYPTO_LIB}")
else()
    include(ExternalProject)
    ExternalProject_Add(
        "libopenssl"
        PREFIX ${DEPENDENCIES_PREFIX}
        GIT_REPOSITORY "https://github.com/openssl/openssl.git"
        GIT_TAG "openssl-3.4.1"
        CONFIGURE_COMMAND cd ${DEPENDENCIES_PREFIX}/src/libopenssl && ./config no-shared --prefix=${DEPENDENCIES_PREFIX}
        BUILD_COMMAND cd ${DEPENDENCIES_PREFIX}/src/libopenssl && make -j
        INSTALL_COMMAND cd ${DEPENDENCIES_PREFIX}/src/libopenssl && sudo make install
    )
    set(OPENSSL_LIB "${DEPENDENCIES_PREFIX}/${LIB_DIR}/libssl.a")
    set(CRYPTO_LIB "${DEPENDENCIES_PREFIX}/${LIB_DIR}/libcrypto.a")
endif()

list(APPEND LIBRARIES ${OPENSSL_LIB})
list(APPEND LIBRARIES ${CRYPTO_LIB})
