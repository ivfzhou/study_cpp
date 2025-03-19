# 编译

克隆源码

```
git clone https://gitee.com/ivfzhou/study_cpp.git
cd study_cpp
```

## Windows

1. Debug 模式

```cmd
cmake.exe -DCMAKE_BUILD_TYPE=Debug -G "Visual Studio 17 2022" -S . -B build-debug
cmake.exe --build -B build-debug --target openssl --config Debug
cmake.exe --build -B build-debug --target jwt-cpp --config Debug
cmake.exe --build -B build-debug --target cpp-httplib --config Debug
cmake.exe --build -B build-debug --target zlib --config Debug
cmake.exe --build -B build-debug --target libzip --config Debug
cmake.exe --build -B build-debug --target yaml-cpp --config Debug
cmake.exe --build -B build-debug --target cpp --config Debug
```

1. Release 模式

```cmd
cmake.exe -DCMAKE_BUILD_TYPE=Release -G "Visual Studio 17 2022" -S . -B build-release
cmake.exe --build -B build-debug --target openssl --config Release
cmake.exe --build -B build-debug --target jwt-cpp --config Release
cmake.exe --build -B build-debug --target cpp-httplib --config Release
cmake.exe --build -B build-debug --target zlib --config Release
cmake.exe --build -B build-debug --target libzip --config Release
cmake.exe --build -B build-debug --target yaml-cpp --config Release
cmake.exe --build -B build-debug --target cpp --config Release
```

## Linux

1. Debug 模式

```shell
cmake -DCMAKE_BUILD_TYPE=Debug -G "Unix Makefiles" -S . -B build-debug
cmake --build build-debug --target openssl
cmake --build build-debug --target zlib
cmake --build build-debug --target libzip
cmake --build build-debug --target bzip2
cmake --build build-debug --target xz
cmake --build build-debug --target zstd
cmake --build build-debug --target cpp-httplib
cmake --build build-debug --target jwt-cpp
cmake --build build-debug --target yaml-cpp
cmake --build build-debug --target cpp
```

1. Release 模式

```shell
cmake -DCMAKE_BUILD_TYPE=Release -G "Unix Makefiles" -S . -B build-release
cmake --build build-release --target openssl
cmake --build build-release --target zlib
cmake --build build-release --target libzip
cmake --build build-release --target bzip2
cmake --build build-release --target xz
cmake --build build-release --target zstd
cmake --build build-release --target cpp-httplib
cmake --build build-release --target jwt-cpp
cmake --build build-release --target yaml-cpp
cmake --build build-release --target cpp
```
