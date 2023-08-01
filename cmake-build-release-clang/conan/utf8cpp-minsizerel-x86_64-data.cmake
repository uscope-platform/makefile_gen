########### AGGREGATED COMPONENTS AND DEPENDENCIES FOR THE MULTI CONFIG #####################
#############################################################################################

set(utfcpp_COMPONENT_NAMES "")
set(utfcpp_FIND_DEPENDENCY_NAMES "")

########### VARIABLES #######################################################################
#############################################################################################
set(utfcpp_PACKAGE_FOLDER_MINSIZEREL "/home/fils/.conan2/p/utfcpee2135b5762e1/p")
set(utfcpp_BUILD_MODULES_PATHS_MINSIZEREL )


set(utfcpp_INCLUDE_DIRS_MINSIZEREL )
set(utfcpp_RES_DIRS_MINSIZEREL )
set(utfcpp_DEFINITIONS_MINSIZEREL )
set(utfcpp_SHARED_LINK_FLAGS_MINSIZEREL )
set(utfcpp_EXE_LINK_FLAGS_MINSIZEREL )
set(utfcpp_OBJECTS_MINSIZEREL )
set(utfcpp_COMPILE_DEFINITIONS_MINSIZEREL )
set(utfcpp_COMPILE_OPTIONS_C_MINSIZEREL )
set(utfcpp_COMPILE_OPTIONS_CXX_MINSIZEREL )
set(utfcpp_LIB_DIRS_MINSIZEREL )
set(utfcpp_BIN_DIRS_MINSIZEREL )
set(utfcpp_LIBRARY_TYPE_MINSIZEREL UNKNOWN)
set(utfcpp_IS_HOST_WINDOWS_MINSIZEREL 0)
set(utfcpp_LIBS_MINSIZEREL )
set(utfcpp_SYSTEM_LIBS_MINSIZEREL )
set(utfcpp_FRAMEWORK_DIRS_MINSIZEREL )
set(utfcpp_FRAMEWORKS_MINSIZEREL )
set(utfcpp_BUILD_DIRS_MINSIZEREL )
set(utfcpp_NO_SONAME_MODE_MINSIZEREL FALSE)


# COMPOUND VARIABLES
set(utfcpp_COMPILE_OPTIONS_MINSIZEREL
    "$<$<COMPILE_LANGUAGE:CXX>:${utfcpp_COMPILE_OPTIONS_CXX_MINSIZEREL}>"
    "$<$<COMPILE_LANGUAGE:C>:${utfcpp_COMPILE_OPTIONS_C_MINSIZEREL}>")
set(utfcpp_LINKER_FLAGS_MINSIZEREL
    "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,SHARED_LIBRARY>:${utfcpp_SHARED_LINK_FLAGS_MINSIZEREL}>"
    "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,MODULE_LIBRARY>:${utfcpp_SHARED_LINK_FLAGS_MINSIZEREL}>"
    "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,EXECUTABLE>:${utfcpp_EXE_LINK_FLAGS_MINSIZEREL}>")


set(utfcpp_COMPONENTS_MINSIZEREL )