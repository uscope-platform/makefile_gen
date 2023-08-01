# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/fils/git/makefilegen_v2/cmake-build-release-clang/antlr_runtime-prefix/src/antlr_runtime"
  "/home/fils/git/makefilegen_v2/cmake-build-release-clang/antlr_runtime-prefix/src/antlr_runtime-build"
  "/home/fils/git/makefilegen_v2/cmake-build-release-clang/antlr_runtime-prefix"
  "/home/fils/git/makefilegen_v2/cmake-build-release-clang/antlr_runtime-prefix/tmp"
  "/home/fils/git/makefilegen_v2/cmake-build-release-clang/antlr_runtime-prefix/src/antlr_runtime-stamp"
  "/home/fils/git/makefilegen_v2/cmake-build-release-clang/antlr_runtime-prefix/src"
  "/home/fils/git/makefilegen_v2/cmake-build-release-clang/antlr_runtime-prefix/src/antlr_runtime-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/fils/git/makefilegen_v2/cmake-build-release-clang/antlr_runtime-prefix/src/antlr_runtime-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/fils/git/makefilegen_v2/cmake-build-release-clang/antlr_runtime-prefix/src/antlr_runtime-stamp${cfgdir}") # cfgdir has leading slash
endif()
