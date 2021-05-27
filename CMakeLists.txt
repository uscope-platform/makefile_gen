cmake_minimum_required(VERSION 3.19)
project(makefilegen_v2)

set(CMAKE_CXX_STANDARD 17)

include_directories(/usr/include/antlr4-runtime)

add_subdirectory(includes)
add_subdirectory(src)

