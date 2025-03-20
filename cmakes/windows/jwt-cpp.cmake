set(JWT_CPP_DEPENDENCIES_PREFIX ${DEPENDENCIES_PREFIX}/jwt-cpp)

find_path(
    JWT_CPP_INCLUDE_DIR
    NAMES jwt-cpp/jwt.h
    PATHS ${JWT_CPP_DEPENDENCIES_PREFIX}/include
    NO_DEFAULT_PATH
)

if(JWT_CPP_INCLUDE_DIR)
    message(STATUS "JWT_CPP_INCLUDE_DIR found: ${JWT_CPP_INCLUDE_DIR}")
else()
    ExternalProject_Add(
        jwt-cpp
        PREFIX ${JWT_CPP_DEPENDENCIES_PREFIX}
        URL https://github.com/Thalhammer/jwt-cpp/archive/refs/tags/v0.7.1.zip
        CONFIGURE_COMMAND cd ${JWT_CPP_DEPENDENCIES_PREFIX}/src &&
        rd /s /q jwt-cpp-build && md jwt-cpp-build
        BUILD_COMMAND cd ${JWT_CPP_DEPENDENCIES_PREFIX}/src/jwt-cpp-build &&
        ${CMAKE_COMMAND} -DCMAKE_INSTALL_PREFIX=${JWT_CPP_DEPENDENCIES_PREFIX} -DBUILD_SHARED_LIBS=OFF
        -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE} -DOPENSSL_ROOT_DIR=${OPENSSL_DEPENDENCIES_PREFIX}
        -DJWT_BUILD_EXAMPLES=OFF ../jwt-cpp
        INSTALL_COMMAND cd ${JWT_CPP_DEPENDENCIES_PREFIX}/src/jwt-cpp-build &&
        ${CMAKE_COMMAND} --build . --target install --config ${CMAKE_BUILD_TYPE}
    )
    set(JWT_CPP_INCLUDE_DIR ${JWT_CPP_DEPENDENCIES_PREFIX}/include)
endif()

include_directories(${JWT_CPP_INCLUDE_DIR})
