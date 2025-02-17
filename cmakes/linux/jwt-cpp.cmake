find_path(
    JWT_CPP_INCLUDE_DIR
    NAMES "jwt"
    PATHS "${DEPENDENCIES_PREFIX}/include"
    NO_DEFAULT_PATH
)
find_library(
    JWT_CPP_LIB
    NAMES "libjwt.a"
    PATHS "${DEPENDENCIES_PREFIX}/lib"
    NO_DEFAULT_PATH
)

if(JWT_CPP_LIB AND JWT_CPP_INCLUDE_DIR)
    message(STATUS "JWT_CPP_INCLUDE_DIR found: ${JWT_CPP_INCLUDE_DIR}")
    message(STATUS "JWT_CPP_LIB found: ${JWT_CPP_LIB}")
else()
    include(ExternalProject)
    ExternalProject_Add(
        libjwt-cpp
        PREFIX ${DEPENDENCIES_PREFIX}
        GIT_REPOSITORY "https://github.com/pokowaka/jwt-cpp.git"
        GIT_TAG "v1.1"
        CONFIGURE_COMMAND cd ${DEPENDENCIES_PREFIX}/src && mkdir -p libjwt-cpp-build
        BUILD_COMMAND cd ${DEPENDENCIES_PREFIX}/src/libjwt-cpp-build && ${CMAKE_COMMAND} -DCMAKE_INSTALL_PREFIX=${DEPENDENCIES_PREFIX} -DOPENSSL_INCLUDE_DIRS=${DEPENDENCIES_PREFIX}/include -DOPENSSL_LIBRARY_DIRS=${DEPENDENCIES_PREFIX}/${LIB_DIR} -DOPENSSL_LIBRARIES=${DEPENDENCIES_PREFIX}/${LIB_DIR}/libcrypto.a -DENABLE_TESTS=OFF -DCMAKE_BUILD_TYPE=Release ../libjwt-cpp
        INSTALL_COMMAND cd ${DEPENDENCIES_PREFIX}/src/libjwt-cpp-build && ${CMAKE_COMMAND} --build . --target install
    )
    set(JWT_CPP_LIB "${DEPENDENCIES_PREFIX}/lib/libjwt.a")
endif()

list(APPEND LIBRARIES ${JWT_CPP_LIB})
