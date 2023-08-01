# Avoid multiple calls to find_package to append duplicated properties to the targets
include_guard()########### VARIABLES #######################################################################
#############################################################################################
set(utfcpp_FRAMEWORKS_FOUND_MINSIZEREL "") # Will be filled later
conan_find_apple_frameworks(utfcpp_FRAMEWORKS_FOUND_MINSIZEREL "${utfcpp_FRAMEWORKS_MINSIZEREL}" "${utfcpp_FRAMEWORK_DIRS_MINSIZEREL}")

set(utfcpp_LIBRARIES_TARGETS "") # Will be filled later


######## Create an interface target to contain all the dependencies (frameworks, system and conan deps)
if(NOT TARGET utfcpp_DEPS_TARGET)
    add_library(utfcpp_DEPS_TARGET INTERFACE IMPORTED)
endif()

set_property(TARGET utfcpp_DEPS_TARGET
             PROPERTY INTERFACE_LINK_LIBRARIES
             $<$<CONFIG:MinSizeRel>:${utfcpp_FRAMEWORKS_FOUND_MINSIZEREL}>
             $<$<CONFIG:MinSizeRel>:${utfcpp_SYSTEM_LIBS_MINSIZEREL}>
             $<$<CONFIG:MinSizeRel>:>
             APPEND)

####### Find the libraries declared in cpp_info.libs, create an IMPORTED target for each one and link the
####### utfcpp_DEPS_TARGET to all of them
conan_package_library_targets("${utfcpp_LIBS_MINSIZEREL}"    # libraries
                              "${utfcpp_LIB_DIRS_MINSIZEREL}" # package_libdir
                              "${utfcpp_BIN_DIRS_MINSIZEREL}" # package_bindir
                              "${utfcpp_LIBRARY_TYPE_MINSIZEREL}"
                              "${utfcpp_IS_HOST_WINDOWS_MINSIZEREL}"
                              utfcpp_DEPS_TARGET
                              utfcpp_LIBRARIES_TARGETS  # out_libraries_targets
                              "_MINSIZEREL"
                              "utfcpp"    # package_name
                              "${utfcpp_NO_SONAME_MODE_MINSIZEREL}")  # soname

# FIXME: What is the result of this for multi-config? All configs adding themselves to path?
set(CMAKE_MODULE_PATH ${utfcpp_BUILD_DIRS_MINSIZEREL} ${CMAKE_MODULE_PATH})

########## GLOBAL TARGET PROPERTIES MinSizeRel ########################################
    set_property(TARGET utf8cpp
                 PROPERTY INTERFACE_LINK_LIBRARIES
                 $<$<CONFIG:MinSizeRel>:${utfcpp_OBJECTS_MINSIZEREL}>
                 $<$<CONFIG:MinSizeRel>:${utfcpp_LIBRARIES_TARGETS}>
                 APPEND)

    if("${utfcpp_LIBS_MINSIZEREL}" STREQUAL "")
        # If the package is not declaring any "cpp_info.libs" the package deps, system libs,
        # frameworks etc are not linked to the imported targets and we need to do it to the
        # global target
        set_property(TARGET utf8cpp
                     PROPERTY INTERFACE_LINK_LIBRARIES
                     utfcpp_DEPS_TARGET
                     APPEND)
    endif()

    set_property(TARGET utf8cpp
                 PROPERTY INTERFACE_LINK_OPTIONS
                 $<$<CONFIG:MinSizeRel>:${utfcpp_LINKER_FLAGS_MINSIZEREL}> APPEND)
    set_property(TARGET utf8cpp
                 PROPERTY INTERFACE_INCLUDE_DIRECTORIES
                 $<$<CONFIG:MinSizeRel>:${utfcpp_INCLUDE_DIRS_MINSIZEREL}> APPEND)
    # Necessary to find LINK shared libraries in Linux
    set_property(TARGET utf8cpp
                 PROPERTY INTERFACE_LINK_DIRECTORIES
                 $<$<CONFIG:MinSizeRel>:${utfcpp_LIB_DIRS_MINSIZEREL}> APPEND)
    set_property(TARGET utf8cpp
                 PROPERTY INTERFACE_COMPILE_DEFINITIONS
                 $<$<CONFIG:MinSizeRel>:${utfcpp_COMPILE_DEFINITIONS_MINSIZEREL}> APPEND)
    set_property(TARGET utf8cpp
                 PROPERTY INTERFACE_COMPILE_OPTIONS
                 $<$<CONFIG:MinSizeRel>:${utfcpp_COMPILE_OPTIONS_MINSIZEREL}> APPEND)

########## For the modules (FindXXX)
set(utfcpp_LIBRARIES_MINSIZEREL utf8cpp)
