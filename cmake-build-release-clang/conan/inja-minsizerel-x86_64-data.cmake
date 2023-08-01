########### AGGREGATED COMPONENTS AND DEPENDENCIES FOR THE MULTI CONFIG #####################
#############################################################################################

list(APPEND inja_COMPONENT_NAMES pantor::inja)
list(REMOVE_DUPLICATES inja_COMPONENT_NAMES)
list(APPEND inja_FIND_DEPENDENCY_NAMES nlohmann_json)
list(REMOVE_DUPLICATES inja_FIND_DEPENDENCY_NAMES)
set(nlohmann_json_FIND_MODE "NO_MODULE")

########### VARIABLES #######################################################################
#############################################################################################
set(inja_PACKAGE_FOLDER_MINSIZEREL "/home/fils/.conan2/p/injab1c05d020a6f7/p")
set(inja_BUILD_MODULES_PATHS_MINSIZEREL )


set(inja_INCLUDE_DIRS_MINSIZEREL "${inja_PACKAGE_FOLDER_MINSIZEREL}/include")
set(inja_RES_DIRS_MINSIZEREL )
set(inja_DEFINITIONS_MINSIZEREL )
set(inja_SHARED_LINK_FLAGS_MINSIZEREL )
set(inja_EXE_LINK_FLAGS_MINSIZEREL )
set(inja_OBJECTS_MINSIZEREL )
set(inja_COMPILE_DEFINITIONS_MINSIZEREL )
set(inja_COMPILE_OPTIONS_C_MINSIZEREL )
set(inja_COMPILE_OPTIONS_CXX_MINSIZEREL )
set(inja_LIB_DIRS_MINSIZEREL )
set(inja_BIN_DIRS_MINSIZEREL )
set(inja_LIBRARY_TYPE_MINSIZEREL UNKNOWN)
set(inja_IS_HOST_WINDOWS_MINSIZEREL 0)
set(inja_LIBS_MINSIZEREL )
set(inja_SYSTEM_LIBS_MINSIZEREL )
set(inja_FRAMEWORK_DIRS_MINSIZEREL )
set(inja_FRAMEWORKS_MINSIZEREL )
set(inja_BUILD_DIRS_MINSIZEREL )
set(inja_NO_SONAME_MODE_MINSIZEREL FALSE)


# COMPOUND VARIABLES
set(inja_COMPILE_OPTIONS_MINSIZEREL
    "$<$<COMPILE_LANGUAGE:CXX>:${inja_COMPILE_OPTIONS_CXX_MINSIZEREL}>"
    "$<$<COMPILE_LANGUAGE:C>:${inja_COMPILE_OPTIONS_C_MINSIZEREL}>")
set(inja_LINKER_FLAGS_MINSIZEREL
    "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,SHARED_LIBRARY>:${inja_SHARED_LINK_FLAGS_MINSIZEREL}>"
    "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,MODULE_LIBRARY>:${inja_SHARED_LINK_FLAGS_MINSIZEREL}>"
    "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,EXECUTABLE>:${inja_EXE_LINK_FLAGS_MINSIZEREL}>")


set(inja_COMPONENTS_MINSIZEREL pantor::inja)
########### COMPONENT pantor::inja VARIABLES ############################################

set(inja_pantor_inja_INCLUDE_DIRS_MINSIZEREL "${inja_PACKAGE_FOLDER_MINSIZEREL}/include")
set(inja_pantor_inja_LIB_DIRS_MINSIZEREL )
set(inja_pantor_inja_BIN_DIRS_MINSIZEREL )
set(inja_pantor_inja_LIBRARY_TYPE_MINSIZEREL UNKNOWN)
set(inja_pantor_inja_IS_HOST_WINDOWS_MINSIZEREL 0)
set(inja_pantor_inja_RES_DIRS_MINSIZEREL )
set(inja_pantor_inja_DEFINITIONS_MINSIZEREL )
set(inja_pantor_inja_OBJECTS_MINSIZEREL )
set(inja_pantor_inja_COMPILE_DEFINITIONS_MINSIZEREL )
set(inja_pantor_inja_COMPILE_OPTIONS_C_MINSIZEREL "")
set(inja_pantor_inja_COMPILE_OPTIONS_CXX_MINSIZEREL "")
set(inja_pantor_inja_LIBS_MINSIZEREL )
set(inja_pantor_inja_SYSTEM_LIBS_MINSIZEREL )
set(inja_pantor_inja_FRAMEWORK_DIRS_MINSIZEREL )
set(inja_pantor_inja_FRAMEWORKS_MINSIZEREL )
set(inja_pantor_inja_DEPENDENCIES_MINSIZEREL nlohmann_json::nlohmann_json)
set(inja_pantor_inja_SHARED_LINK_FLAGS_MINSIZEREL )
set(inja_pantor_inja_EXE_LINK_FLAGS_MINSIZEREL )
set(inja_pantor_inja_NO_SONAME_MODE_MINSIZEREL FALSE)

# COMPOUND VARIABLES
set(inja_pantor_inja_LINKER_FLAGS_MINSIZEREL
        $<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,SHARED_LIBRARY>:${inja_pantor_inja_SHARED_LINK_FLAGS_MINSIZEREL}>
        $<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,MODULE_LIBRARY>:${inja_pantor_inja_SHARED_LINK_FLAGS_MINSIZEREL}>
        $<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,EXECUTABLE>:${inja_pantor_inja_EXE_LINK_FLAGS_MINSIZEREL}>
)
set(inja_pantor_inja_COMPILE_OPTIONS_MINSIZEREL
    "$<$<COMPILE_LANGUAGE:CXX>:${inja_pantor_inja_COMPILE_OPTIONS_CXX_MINSIZEREL}>"
    "$<$<COMPILE_LANGUAGE:C>:${inja_pantor_inja_COMPILE_OPTIONS_C_MINSIZEREL}>")