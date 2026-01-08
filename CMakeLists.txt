cmake_minimum_required(VERSION 3.16)
project(makefilegen_v2)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

set(OPENSSL_USE_STATIC_LIBS TRUE)
set(THREADS_PREFER_PTHREAD_FLAG ON)
set(ANTLR_VERSION 4.13.1)

find_package(OpenSSL REQUIRED)
find_package(Threads REQUIRED)
find_package(antlr4-runtime CONFIG REQUIRED)
find_package(CLI11 REQUIRED)
find_package(spdlog REQUIRED)
find_package(nlohmann_json REQUIRED)
find_package(cereal)
find_package(GTest REQUIRED)

include_directories(includes)

include_directories(${inja_INCLUDE_DIRS})

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_definitions(-DTEMPLATES_FOLDER="${CMAKE_SOURCE_DIR}/templates")
    add_definitions(-DSPECS_FOLDER="${CMAKE_SOURCE_DIR}/bus_specs")
else()
    add_definitions(-DTEMPLATES_FOLDER="/usr/local/etc/makefile_gen/templates")
    add_definitions(-DSPECS_FOLDER="/usr/local/etc/makefile_gen/specs")
endif(CMAKE_BUILD_TYPE STREQUAL "Debug")

add_subdirectory(includes)
add_subdirectory(src)
add_subdirectory(Testing)
add_subdirectory(grammars)

ExternalProject_Add(antlr_runtime
        GIT_REPOSITORY https://github.com/antlr/antlr4.git
        GIT_TAG ${ANTLR_VERSION}
        CONFIGURE_COMMAND cmake ${CMAKE_BINARY_DIR}/antlr_runtime-prefix/src/antlr_runtime/runtime/Cpp
        INSTALL_COMMAND DESTDIR=${CMAKE_BINARY_DIR}/antlr_runtime/dist make install
        )

add_custom_target(parsers)
add_dependencies(parsers vh_parser_gen sv_parser_gen)


