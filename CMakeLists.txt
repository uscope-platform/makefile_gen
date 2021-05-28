cmake_minimum_required(VERSION 3.19)
project(makefilegen_v2)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wattributes")

include_directories(/usr/include/antlr4-runtime)
include_directories(includes)

add_subdirectory(includes)
add_subdirectory(src)


