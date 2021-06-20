cmake_minimum_required(VERSION 3.18)
project(makefilegen_v2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

set(OPENSSL_USE_STATIC_LIBS TRUE)
find_package(OpenSSL REQUIRED)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

include_directories(/usr/include/antlr4-runtime)
include_directories(includes)

add_subdirectory(includes)
add_subdirectory(src)
add_subdirectory(Testing)


