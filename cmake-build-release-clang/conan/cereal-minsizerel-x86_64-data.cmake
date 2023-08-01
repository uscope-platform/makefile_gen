########### AGGREGATED COMPONENTS AND DEPENDENCIES FOR THE MULTI CONFIG #####################
#############################################################################################

set(cereal_COMPONENT_NAMES "")
set(cereal_FIND_DEPENDENCY_NAMES "")

########### VARIABLES #######################################################################
#############################################################################################
set(cereal_PACKAGE_FOLDER_MINSIZEREL "/home/fils/.conan2/p/cerea4cf7b92f85513/p")
set(cereal_BUILD_MODULES_PATHS_MINSIZEREL )


set(cereal_INCLUDE_DIRS_MINSIZEREL "${cereal_PACKAGE_FOLDER_MINSIZEREL}/include")
set(cereal_RES_DIRS_MINSIZEREL )
set(cereal_DEFINITIONS_MINSIZEREL )
set(cereal_SHARED_LINK_FLAGS_MINSIZEREL )
set(cereal_EXE_LINK_FLAGS_MINSIZEREL )
set(cereal_OBJECTS_MINSIZEREL )
set(cereal_COMPILE_DEFINITIONS_MINSIZEREL )
set(cereal_COMPILE_OPTIONS_C_MINSIZEREL )
set(cereal_COMPILE_OPTIONS_CXX_MINSIZEREL )
set(cereal_LIB_DIRS_MINSIZEREL )
set(cereal_BIN_DIRS_MINSIZEREL )
set(cereal_LIBRARY_TYPE_MINSIZEREL UNKNOWN)
set(cereal_IS_HOST_WINDOWS_MINSIZEREL 0)
set(cereal_LIBS_MINSIZEREL )
set(cereal_SYSTEM_LIBS_MINSIZEREL )
set(cereal_FRAMEWORK_DIRS_MINSIZEREL )
set(cereal_FRAMEWORKS_MINSIZEREL )
set(cereal_BUILD_DIRS_MINSIZEREL )
set(cereal_NO_SONAME_MODE_MINSIZEREL FALSE)


# COMPOUND VARIABLES
set(cereal_COMPILE_OPTIONS_MINSIZEREL
    "$<$<COMPILE_LANGUAGE:CXX>:${cereal_COMPILE_OPTIONS_CXX_MINSIZEREL}>"
    "$<$<COMPILE_LANGUAGE:C>:${cereal_COMPILE_OPTIONS_C_MINSIZEREL}>")
set(cereal_LINKER_FLAGS_MINSIZEREL
    "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,SHARED_LIBRARY>:${cereal_SHARED_LINK_FLAGS_MINSIZEREL}>"
    "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,MODULE_LIBRARY>:${cereal_SHARED_LINK_FLAGS_MINSIZEREL}>"
    "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,EXECUTABLE>:${cereal_EXE_LINK_FLAGS_MINSIZEREL}>")


set(cereal_COMPONENTS_MINSIZEREL )