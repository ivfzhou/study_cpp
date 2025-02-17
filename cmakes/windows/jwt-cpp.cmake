find_path(
    JWT_CPP_INCLUDE_DIR
    NAMES "jwt-cpp/jwt.h"
    PATHS "${DEPENDENCIES_PREFIX}/include"
    NO_DEFAULT_PATH
)

if(JWT_CPP_INCLUDE_DIR)
    message(STATUS "JWT_CPP_INCLUDE_DIR found: ${JWT_CPP_INCLUDE_DIR}")
else()
    include(ExternalProject)
    ExternalProject_Add(
        "libjwt-cpp"
        PREFIX ${DEPENDENCIES_PREFIX}
        GIT_REPOSITORY "https://github.com/Thalhammer/jwt-cpp.git"
        GIT_TAG "v0.7.0"
        CONFIGURE_COMMAND cd ${DEPENDENCIES_PREFIX}/src && if not exist libjwt-cpp-build (md libjwt-cpp-build)
        BUILD_COMMAND cd ${DEPENDENCIES_PREFIX}/src/libjwt-cpp-build && ${CMAKE_COMMAND} -DCMAKE_INSTALL_PREFIX=${DEPENDENCIES_PREFIX} -DJWT_BUILD_EXAMPLES=OFF -DOPENSSL_ROOT_DIR=${DEPENDENCIES_PREFIX} ../libjwt-cpp
        INSTALL_COMMAND cd ${DEPENDENCIES_PREFIX}/src/libjwt-cpp-build && ${CMAKE_COMMAND} --build . --target install --config Release
    )
endif()
