set(JWT_CPP_DEPENDENCIES_PREFIX ${DEPENDENCIES_PREFIX}/jwt-cpp)

find_path(
    JWT_CPP_INCLUDE_DIR
    NAMES jwt
    PATHS ${JWT_CPP_DEPENDENCIES_PREFIX}/include
    NO_DEFAULT_PATH
)

if(JWT_CPP_LIB AND JWT_CPP_INCLUDE_DIR)
    message(STATUS "JWT_CPP_INCLUDE_DIR found: ${JWT_CPP_INCLUDE_DIR}")
    message(STATUS "JWT_CPP_LIB found: ${JWT_CPP_LIB}")
else()
    ExternalProject_Add(
        jwt-cpp
        PREFIX ${JWT_CPP_DEPENDENCIES_PREFIX}
        URL https://github.com/Thalhammer/jwt-cpp/archive/refs/tags/v0.7.1.zip
        CONFIGURE_COMMAND cd ${JWT_CPP_DEPENDENCIES_PREFIX}/src &&rm -rf jwt-cpp-build && mkdir -p jwt-cpp-build
        BUILD_COMMAND cd ${JWT_CPP_DEPENDENCIES_PREFIX}/src/jwt-cpp-build &&
        ${CMAKE_COMMAND} -DCMAKE_INSTALL_PREFIX=${JWT_CPP_DEPENDENCIES_PREFIX}
        -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE} -DBUILD_SHARED_LIBS=OFF -DOPENSSL_INCLUDE_DIRS=${OPENSSL_INCLUDE_DIR}
        -DOPENSSL_LIBRARY_DIRS=${OPENSSL_LIB_DIR} -DOPENSSL_LIBRARIES=${CRYPTO_LIB} ../jwt-cpp
        INSTALL_COMMAND cd ${JWT_CPP_DEPENDENCIES_PREFIX}/src/jwt-cpp-build &&
        ${CMAKE_COMMAND} --build . --target install
    )
    set(JWT_CPP_INCLUDE_DIR ${JWT_CPP_DEPENDENCIES_PREFIX}/include)
endif()

include_directories(${JWT_CPP_INCLUDE_DIR})
