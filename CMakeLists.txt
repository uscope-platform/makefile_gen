cmake_minimum_required(VERSION 3.16)
project(ananke)

enable_testing()

set(CMAKE_CXX_STANDARD 23)
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
find_package(valijson REQUIRED)
find_package(cereal)
find_package(GTest REQUIRED)
find_package(ctre REQUIRED)
find_package(tomlplusplus REQUIRED)

include_directories(includes)

include_directories(${inja_INCLUDE_DIRS})

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_definitions(-DTEMPLATES_FOLDER="${CMAKE_SOURCE_DIR}/templates")
    add_definitions(-DSPECS_FOLDER="${CMAKE_SOURCE_DIR}/bus_specs")
elseif(CMAKE_BUILD_TYPE STREQUAL "RelWithDebInfo")
    add_definitions(-DTEMPLATES_FOLDER="${CMAKE_SOURCE_DIR}/templates")
    add_definitions(-DSPECS_FOLDER="${CMAKE_SOURCE_DIR}/bus_specs")
else()
    add_definitions(-DTEMPLATES_FOLDER="/usr/local/etc/ananke/templates")
    add_definitions(-DSPECS_FOLDER="/usr/local/etc/ananke/specs")
endif(CMAKE_BUILD_TYPE STREQUAL "Debug")

option(ENABLE_PROFILING "Enable profiling" OFF)
option(ENABLE_COVERAGE "Enable code coverage" OFF)
option(ENABLE_ASAN "Enable AddressSanitizer" OFF)
option(ENABLE_TSAN "Enable ThreadSanitizer" OFF)

if(ENABLE_PROFILING)
    message(STATUS "Enabling Profiling support")
    add_compile_options(--coverage -ftest-coverage)
    add_link_options(--coverage)
endif()


if(ENABLE_COVERAGE)
    message(STATUS "Enabling Code coverage support")
    add_compile_options(--coverage -ftest-coverage)
    add_link_options(--coverage)
endif()

if(ENABLE_ASAN)
    message(STATUS "Enabling AddressSanitizer")
    add_compile_options(-fsanitize=address -fno-omit-frame-pointer)
    add_link_options(-fsanitize=address)
elseif(ENABLE_TSAN)
    message(STATUS "Enabling ThreadSanitizer")
    # TSan requires at least -O1 optimization to be effective
    add_compile_options(-fsanitize=thread -g -O1 -fno-omit-frame-pointer)
    add_link_options(-fsanitize=thread)
endif()



# ---------------------------------------------------------------------------
# Persistent cache schema fingerprint.
# The on-disk cache (data_store::unified_cache) embeds the parsed HDL data
# model; whenever any source that defines that model changes, the archive
# format may change. We derive the cache version from a hash of those sources
# so the cache invalidates automatically (no manual version bumps) and only
# when serialization-relevant code changes.
# ---------------------------------------------------------------------------
file(GLOB_RECURSE CACHE_SCHEMA_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_SOURCE_DIR}/includes/data_model/*"
    "${CMAKE_SOURCE_DIR}/src/data_model/*"
)

set(CACHE_SCHEMA_HASH_HEADER "${CMAKE_BINARY_DIR}/generated/cache_schema_hash.hpp")
add_custom_command(
    OUTPUT ${CACHE_SCHEMA_HASH_HEADER}
    COMMAND ${CMAKE_COMMAND}
        "-DSCHEMA_ROOT=${CMAKE_SOURCE_DIR}"
        "-DOUTPUT=${CACHE_SCHEMA_HASH_HEADER}"
        -P "${CMAKE_SOURCE_DIR}/cmake/hash_cache_schema.cmake"
    DEPENDS ${CACHE_SCHEMA_SOURCES}
    COMMENT "Generating cache schema fingerprint"
)
add_custom_target(cache_schema_hash DEPENDS ${CACHE_SCHEMA_HASH_HEADER})

include_directories(${CMAKE_BINARY_DIR}/generated)

add_subdirectory(includes)
add_subdirectory(src)
add_subdirectory(Testing)
add_subdirectory(grammars)

ExternalProject_Add(antlr_runtime
        GIT_REPOSITORY https://github.com/antlr/antlr4.git
        GIT_TAG ${ANTLR_VERSION}
        CONFIGURE_COMMAND ${CMAKE_COMMAND}
        -DCMAKE_POLICY_VERSION_MINIMUM=3.5
        -DBUILD_TESTING=OFF
        -DANTLR_BUILD_CPP_TESTS=OFF
        ${CMAKE_BINARY_DIR}/antlr_runtime-prefix/src/antlr_runtime/runtime/Cpp
        INSTALL_COMMAND DESTDIR=${CMAKE_BINARY_DIR}/antlr_runtime/dist make install
)

add_custom_target(parsers)
add_dependencies(parsers vh_parser_gen sv_parser_gen)




