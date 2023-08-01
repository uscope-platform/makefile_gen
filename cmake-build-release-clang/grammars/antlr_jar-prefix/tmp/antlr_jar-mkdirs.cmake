# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/fils/git/makefilegen_v2/cmake-build-release-clang/grammars/antlr_jar-prefix/src/antlr_jar"
  "/home/fils/git/makefilegen_v2/cmake-build-release-clang/grammars/antlr_jar-prefix/src/antlr_jar-build"
  "/home/fils/git/makefilegen_v2/cmake-build-release-clang/grammars/antlr_jar-prefix"
  "/home/fils/git/makefilegen_v2/cmake-build-release-clang/grammars/antlr_jar-prefix/tmp"
  "/home/fils/git/makefilegen_v2/cmake-build-release-clang/grammars/antlr_jar-prefix/src/antlr_jar-stamp"
  "/home/fils/git/makefilegen_v2/cmake-build-release-clang/grammars/antlr_jar"
  "/home/fils/git/makefilegen_v2/cmake-build-release-clang/grammars/antlr_jar-prefix/src/antlr_jar-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/fils/git/makefilegen_v2/cmake-build-release-clang/grammars/antlr_jar-prefix/src/antlr_jar-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/fils/git/makefilegen_v2/cmake-build-release-clang/grammars/antlr_jar-prefix/src/antlr_jar-stamp${cfgdir}") # cfgdir has leading slash
endif()
