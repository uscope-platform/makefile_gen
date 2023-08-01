# Avoid multiple calls to find_package to append duplicated properties to the targets
include_guard()########### VARIABLES #######################################################################
#############################################################################################
set(cli11_FRAMEWORKS_FOUND_MINSIZEREL "") # Will be filled later
conan_find_apple_frameworks(cli11_FRAMEWORKS_FOUND_MINSIZEREL "${cli11_FRAMEWORKS_MINSIZEREL}" "${cli11_FRAMEWORK_DIRS_MINSIZEREL}")

set(cli11_LIBRARIES_TARGETS "") # Will be filled later


######## Create an interface target to contain all the dependencies (frameworks, system and conan deps)
if(NOT TARGET cli11_DEPS_TARGET)
    add_library(cli11_DEPS_TARGET INTERFACE IMPORTED)
endif()

set_property(TARGET cli11_DEPS_TARGET
             PROPERTY INTERFACE_LINK_LIBRARIES
             $<$<CONFIG:MinSizeRel>:${cli11_FRAMEWORKS_FOUND_MINSIZEREL}>
             $<$<CONFIG:MinSizeRel>:${cli11_SYSTEM_LIBS_MINSIZEREL}>
             $<$<CONFIG:MinSizeRel>:>
             APPEND)

####### Find the libraries declared in cpp_info.libs, create an IMPORTED target for each one and link the
####### cli11_DEPS_TARGET to all of them
conan_package_library_targets("${cli11_LIBS_MINSIZEREL}"    # libraries
                              "${cli11_LIB_DIRS_MINSIZEREL}" # package_libdir
                              "${cli11_BIN_DIRS_MINSIZEREL}" # package_bindir
                              "${cli11_LIBRARY_TYPE_MINSIZEREL}"
                              "${cli11_IS_HOST_WINDOWS_MINSIZEREL}"
                              cli11_DEPS_TARGET
                              cli11_LIBRARIES_TARGETS  # out_libraries_targets
                              "_MINSIZEREL"
                              "cli11"    # package_name
                              "${cli11_NO_SONAME_MODE_MINSIZEREL}")  # soname

# FIXME: What is the result of this for multi-config? All configs adding themselves to path?
set(CMAKE_MODULE_PATH ${cli11_BUILD_DIRS_MINSIZEREL} ${CMAKE_MODULE_PATH})

########## GLOBAL TARGET PROPERTIES MinSizeRel ########################################
    set_property(TARGET CLI11::CLI11
                 PROPERTY INTERFACE_LINK_LIBRARIES
                 $<$<CONFIG:MinSizeRel>:${cli11_OBJECTS_MINSIZEREL}>
                 $<$<CONFIG:MinSizeRel>:${cli11_LIBRARIES_TARGETS}>
                 APPEND)

    if("${cli11_LIBS_MINSIZEREL}" STREQUAL "")
        # If the package is not declaring any "cpp_info.libs" the package deps, system libs,
        # frameworks etc are not linked to the imported targets and we need to do it to the
        # global target
        set_property(TARGET CLI11::CLI11
                     PROPERTY INTERFACE_LINK_LIBRARIES
                     cli11_DEPS_TARGET
                     APPEND)
    endif()

    set_property(TARGET CLI11::CLI11
                 PROPERTY INTERFACE_LINK_OPTIONS
                 $<$<CONFIG:MinSizeRel>:${cli11_LINKER_FLAGS_MINSIZEREL}> APPEND)
    set_property(TARGET CLI11::CLI11
                 PROPERTY INTERFACE_INCLUDE_DIRECTORIES
                 $<$<CONFIG:MinSizeRel>:${cli11_INCLUDE_DIRS_MINSIZEREL}> APPEND)
    # Necessary to find LINK shared libraries in Linux
    set_property(TARGET CLI11::CLI11
                 PROPERTY INTERFACE_LINK_DIRECTORIES
                 $<$<CONFIG:MinSizeRel>:${cli11_LIB_DIRS_MINSIZEREL}> APPEND)
    set_property(TARGET CLI11::CLI11
                 PROPERTY INTERFACE_COMPILE_DEFINITIONS
                 $<$<CONFIG:MinSizeRel>:${cli11_COMPILE_DEFINITIONS_MINSIZEREL}> APPEND)
    set_property(TARGET CLI11::CLI11
                 PROPERTY INTERFACE_COMPILE_OPTIONS
                 $<$<CONFIG:MinSizeRel>:${cli11_COMPILE_OPTIONS_MINSIZEREL}> APPEND)

########## For the modules (FindXXX)
set(cli11_LIBRARIES_MINSIZEREL CLI11::CLI11)
