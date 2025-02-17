find_path(
    OPENSSL_INCLUDE_DIR
    NAMES "openssl"
    PATHS "${DEPENDENCIES_PREFIX}/include"
    NO_DEFAULT_PATH
)
find_library(
    OPENSSL_LIB
    NAMES "libssl.lib"
    PATHS "${DEPENDENCIES_PREFIX}/lib"
    NO_DEFAULT_PATH
)
find_library(
    CRYPTO_LIB
    NAMES "libcrypto.lib"
    PATHS "${DEPENDENCIES_PREFIX}/lib"
    NO_DEFAULT_PATH
)

if(OPENSSL_INCLUDE_DIR AND OPENSSL_LIB AND CRYPTO_LIB)
    message(STATUS "OPENSSL_INCLUDE_DIR found: ${OPENSSL_INCLUDE_DIR}")
    message(STATUS "OPENSSL_LIB found: ${OPENSSL_LIB}")
    message(STATUS "CRYPTO_LIB found: ${CRYPTO_LIB}")
else()
    include(ExternalProject)
    if(CMAKE_SIZEOF_VOID_P EQUAL 4)
        set(VC-WIN "VC-WIN32")
    elseif(CMAKE_SIZEOF_VOID_P EQUAL 8)
        set(VC-WIN "VC-WIN64A")
    endif()
    ExternalProject_Add(
        "libopenssl"
        PREFIX ${DEPENDENCIES_PREFIX}
        GIT_REPOSITORY "https://github.com/openssl/openssl.git"
        GIT_TAG "openssl-3.4.1"
        CONFIGURE_COMMAND cd ${DEPENDENCIES_PREFIX}/src/libopenssl && perl Configure ${VC-WIN} no-shared --prefix=${DEPENDENCIES_PREFIX}
        BUILD_COMMAND cd ${DEPENDENCIES_PREFIX}/src/libopenssl && nmake /I .
        INSTALL_COMMAND cd ${DEPENDENCIES_PREFIX}/src/libopenssl && nmake install /I .
    )
    set(OPENSSL_LIB "${DEPENDENCIES_PREFIX}/lib/libssl.lib")
    set(CRYPTO_LIB "${DEPENDENCIES_PREFIX}/lib/libcrypto.lib")
endif()

list(APPEND LIBRARIES ${OPENSSL_LIB})
list(APPEND LIBRARIES ${CRYPTO_LIB})
