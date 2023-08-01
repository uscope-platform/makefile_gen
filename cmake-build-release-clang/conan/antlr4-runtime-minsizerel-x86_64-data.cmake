########### AGGREGATED COMPONENTS AND DEPENDENCIES FOR THE MULTI CONFIG #####################
#############################################################################################

set(antlr4-cppruntime_COMPONENT_NAMES "")
list(APPEND antlr4-cppruntime_FIND_DEPENDENCY_NAMES utf8cpp)
list(REMOVE_DUPLICATES antlr4-cppruntime_FIND_DEPENDENCY_NAMES)
set(utf8cpp_FIND_MODE "NO_MODULE")

########### VARIABLES #######################################################################
#############################################################################################
set(antlr4-cppruntime_PACKAGE_FOLDER_MINSIZEREL "/home/fils/.conan2/p/b/antlr8807f0504349e/p")
set(antlr4-cppruntime_BUILD_MODULES_PATHS_MINSIZEREL )


set(antlr4-cppruntime_INCLUDE_DIRS_MINSIZEREL "${antlr4-cppruntime_PACKAGE_FOLDER_MINSIZEREL}/include"
			"${antlr4-cppruntime_PACKAGE_FOLDER_MINSIZEREL}/include/antlr4-runtime")
set(antlr4-cppruntime_RES_DIRS_MINSIZEREL )
set(antlr4-cppruntime_DEFINITIONS_MINSIZEREL )
set(antlr4-cppruntime_SHARED_LINK_FLAGS_MINSIZEREL )
set(antlr4-cppruntime_EXE_LINK_FLAGS_MINSIZEREL )
set(antlr4-cppruntime_OBJECTS_MINSIZEREL )
set(antlr4-cppruntime_COMPILE_DEFINITIONS_MINSIZEREL )
set(antlr4-cppruntime_COMPILE_OPTIONS_C_MINSIZEREL )
set(antlr4-cppruntime_COMPILE_OPTIONS_CXX_MINSIZEREL )
set(antlr4-cppruntime_LIB_DIRS_MINSIZEREL "${antlr4-cppruntime_PACKAGE_FOLDER_MINSIZEREL}/lib")
set(antlr4-cppruntime_BIN_DIRS_MINSIZEREL )
set(antlr4-cppruntime_LIBRARY_TYPE_MINSIZEREL STATIC)
set(antlr4-cppruntime_IS_HOST_WINDOWS_MINSIZEREL 0)
set(antlr4-cppruntime_LIBS_MINSIZEREL antlr4-runtime)
set(antlr4-cppruntime_SYSTEM_LIBS_MINSIZEREL m pthread)
set(antlr4-cppruntime_FRAMEWORK_DIRS_MINSIZEREL )
set(antlr4-cppruntime_FRAMEWORKS_MINSIZEREL )
set(antlr4-cppruntime_BUILD_DIRS_MINSIZEREL )
set(antlr4-cppruntime_NO_SONAME_MODE_MINSIZEREL FALSE)


# COMPOUND VARIABLES
set(antlr4-cppruntime_COMPILE_OPTIONS_MINSIZEREL
    "$<$<COMPILE_LANGUAGE:CXX>:${antlr4-cppruntime_COMPILE_OPTIONS_CXX_MINSIZEREL}>"
    "$<$<COMPILE_LANGUAGE:C>:${antlr4-cppruntime_COMPILE_OPTIONS_C_MINSIZEREL}>")
set(antlr4-cppruntime_LINKER_FLAGS_MINSIZEREL
    "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,SHARED_LIBRARY>:${antlr4-cppruntime_SHARED_LINK_FLAGS_MINSIZEREL}>"
    "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,MODULE_LIBRARY>:${antlr4-cppruntime_SHARED_LINK_FLAGS_MINSIZEREL}>"
    "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,EXECUTABLE>:${antlr4-cppruntime_EXE_LINK_FLAGS_MINSIZEREL}>")


set(antlr4-cppruntime_COMPONENTS_MINSIZEREL )