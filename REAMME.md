# 编译

克隆源码

```
git clone https://gitee.com/ivfzhou/study_cpp.git
cd study_cpp
```

## Windows

1. Debug 模式

```cmd
cmake.exe -G "Visual Studio 17 2022" -DCMAKE_MSVC_RUNTIME_LIBRARY=MultiThreadedDebug -DCMAKE_BUILD_TYPE=Debug -S . -B build-debug
cmake.exe --build -B build-debug --target libopenssl --config Debug
cmake.exe --build -B build-debug --target libjwt-cpp --config Debug
cmake.exe --build -B build-debug --target libcpp-httplib --config Debug
cmake.exe --build -B build-debug --target libzlib --config Debug
cmake.exe --build -B build-debug --target liblibzip --config Debug
cmake.exe --build -B build-debug --target libyaml-cpp --config Debug
cmake.exe --build -B build-debug --target cpp --config Debug
```

1. Release 模式

```cmd
cmake.exe -G "Visual Studio 17 2022" -DCMAKE_MSVC_RUNTIME_LIBRARY=MultiThreaded -S . -B build-release
cmake.exe --build -B build-debug --target libopenssl --config Release
cmake.exe --build -B build-debug --target libjwt-cpp --config Release
cmake.exe --build -B build-debug --target libcpp-httplib --config Release
cmake.exe --build -B build-debug --target libzlib --config Release
cmake.exe --build -B build-debug --target liblibzip --config Release
cmake.exe --build -B build-debug --target libyaml-cpp --config Release
cmake.exe --build -B build-debug --target cpp --config Release
```

## Linux

1. Debug 模式

```shell
cmake -DCMAKE_BUILD_TYPE=Debug -G "Unix Makefiles" -S . -B build-debug
cmake --build build-debug --target libopenssl
cmake --build build-debug --target libzlib
cmake --build build-debug --target liblibzip
cmake --build build-debug --target libbzip2
cmake --build build-debug --target libxz
cmake --build build-debug --target libzstd
cmake --build build-debug --target libcpp-httplib
cmake --build build-debug --target libjwt-cpp
cmake --build build-debug --target libyaml-cpp
cmake --build build-debug --target cpp
```

1. Release 模式

```shell
cmake -DCMAKE_BUILD_TYPE=Release -G "Unix Makefiles" -S . -B build-release
cmake --build build-release --target libopenssl
cmake --build build-release --target libzlib
cmake --build build-release --target liblibzip
cmake --build build-release --target libbzip2
cmake --build build-release --target libxz
cmake --build build-release --target libzstd
cmake --build build-release --target libcpp-httplib
cmake --build build-release --target libjwt-cpp
cmake --build build-release --target libyaml-cpp
cmake --build build-release --target cpp
```
