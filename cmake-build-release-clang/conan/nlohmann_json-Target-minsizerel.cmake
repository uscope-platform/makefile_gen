# Avoid multiple calls to find_package to append duplicated properties to the targets
include_guard()########### VARIABLES #######################################################################
#############################################################################################
set(nlohmann_json_FRAMEWORKS_FOUND_MINSIZEREL "") # Will be filled later
conan_find_apple_frameworks(nlohmann_json_FRAMEWORKS_FOUND_MINSIZEREL "${nlohmann_json_FRAMEWORKS_MINSIZEREL}" "${nlohmann_json_FRAMEWORK_DIRS_MINSIZEREL}")

set(nlohmann_json_LIBRARIES_TARGETS "") # Will be filled later


######## Create an interface target to contain all the dependencies (frameworks, system and conan deps)
if(NOT TARGET nlohmann_json_DEPS_TARGET)
    add_library(nlohmann_json_DEPS_TARGET INTERFACE IMPORTED)
endif()

set_property(TARGET nlohmann_json_DEPS_TARGET
             PROPERTY INTERFACE_LINK_LIBRARIES
             $<$<CONFIG:MinSizeRel>:${nlohmann_json_FRAMEWORKS_FOUND_MINSIZEREL}>
             $<$<CONFIG:MinSizeRel>:${nlohmann_json_SYSTEM_LIBS_MINSIZEREL}>
             $<$<CONFIG:MinSizeRel>:>
             APPEND)

####### Find the libraries declared in cpp_info.libs, create an IMPORTED target for each one and link the
####### nlohmann_json_DEPS_TARGET to all of them
conan_package_library_targets("${nlohmann_json_LIBS_MINSIZEREL}"    # libraries
                              "${nlohmann_json_LIB_DIRS_MINSIZEREL}" # package_libdir
                              "${nlohmann_json_BIN_DIRS_MINSIZEREL}" # package_bindir
                              "${nlohmann_json_LIBRARY_TYPE_MINSIZEREL}"
                              "${nlohmann_json_IS_HOST_WINDOWS_MINSIZEREL}"
                              nlohmann_json_DEPS_TARGET
                              nlohmann_json_LIBRARIES_TARGETS  # out_libraries_targets
                              "_MINSIZEREL"
                              "nlohmann_json"    # package_name
                              "${nlohmann_json_NO_SONAME_MODE_MINSIZEREL}")  # soname

# FIXME: What is the result of this for multi-config? All configs adding themselves to path?
set(CMAKE_MODULE_PATH ${nlohmann_json_BUILD_DIRS_MINSIZEREL} ${CMAKE_MODULE_PATH})

########## GLOBAL TARGET PROPERTIES MinSizeRel ########################################
    set_property(TARGET nlohmann_json::nlohmann_json
                 PROPERTY INTERFACE_LINK_LIBRARIES
                 $<$<CONFIG:MinSizeRel>:${nlohmann_json_OBJECTS_MINSIZEREL}>
                 $<$<CONFIG:MinSizeRel>:${nlohmann_json_LIBRARIES_TARGETS}>
                 APPEND)

    if("${nlohmann_json_LIBS_MINSIZEREL}" STREQUAL "")
        # If the package is not declaring any "cpp_info.libs" the package deps, system libs,
        # frameworks etc are not linked to the imported targets and we need to do it to the
        # global target
        set_property(TARGET nlohmann_json::nlohmann_json
                     PROPERTY INTERFACE_LINK_LIBRARIES
                     nlohmann_json_DEPS_TARGET
                     APPEND)
    endif()

    set_property(TARGET nlohmann_json::nlohmann_json
                 PROPERTY INTERFACE_LINK_OPTIONS
                 $<$<CONFIG:MinSizeRel>:${nlohmann_json_LINKER_FLAGS_MINSIZEREL}> APPEND)
    set_property(TARGET nlohmann_json::nlohmann_json
                 PROPERTY INTERFACE_INCLUDE_DIRECTORIES
                 $<$<CONFIG:MinSizeRel>:${nlohmann_json_INCLUDE_DIRS_MINSIZEREL}> APPEND)
    # Necessary to find LINK shared libraries in Linux
    set_property(TARGET nlohmann_json::nlohmann_json
                 PROPERTY INTERFACE_LINK_DIRECTORIES
                 $<$<CONFIG:MinSizeRel>:${nlohmann_json_LIB_DIRS_MINSIZEREL}> APPEND)
    set_property(TARGET nlohmann_json::nlohmann_json
                 PROPERTY INTERFACE_COMPILE_DEFINITIONS
                 $<$<CONFIG:MinSizeRel>:${nlohmann_json_COMPILE_DEFINITIONS_MINSIZEREL}> APPEND)
    set_property(TARGET nlohmann_json::nlohmann_json
                 PROPERTY INTERFACE_COMPILE_OPTIONS
                 $<$<CONFIG:MinSizeRel>:${nlohmann_json_COMPILE_OPTIONS_MINSIZEREL}> APPEND)

########## For the modules (FindXXX)
set(nlohmann_json_LIBRARIES_MINSIZEREL nlohmann_json::nlohmann_json)
