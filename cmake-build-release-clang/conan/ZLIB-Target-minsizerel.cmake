# Avoid multiple calls to find_package to append duplicated properties to the targets
include_guard()########### VARIABLES #######################################################################
#############################################################################################
set(zlib_FRAMEWORKS_FOUND_MINSIZEREL "") # Will be filled later
conan_find_apple_frameworks(zlib_FRAMEWORKS_FOUND_MINSIZEREL "${zlib_FRAMEWORKS_MINSIZEREL}" "${zlib_FRAMEWORK_DIRS_MINSIZEREL}")

set(zlib_LIBRARIES_TARGETS "") # Will be filled later


######## Create an interface target to contain all the dependencies (frameworks, system and conan deps)
if(NOT TARGET zlib_DEPS_TARGET)
    add_library(zlib_DEPS_TARGET INTERFACE IMPORTED)
endif()

set_property(TARGET zlib_DEPS_TARGET
             PROPERTY INTERFACE_LINK_LIBRARIES
             $<$<CONFIG:MinSizeRel>:${zlib_FRAMEWORKS_FOUND_MINSIZEREL}>
             $<$<CONFIG:MinSizeRel>:${zlib_SYSTEM_LIBS_MINSIZEREL}>
             $<$<CONFIG:MinSizeRel>:>
             APPEND)

####### Find the libraries declared in cpp_info.libs, create an IMPORTED target for each one and link the
####### zlib_DEPS_TARGET to all of them
conan_package_library_targets("${zlib_LIBS_MINSIZEREL}"    # libraries
                              "${zlib_LIB_DIRS_MINSIZEREL}" # package_libdir
                              "${zlib_BIN_DIRS_MINSIZEREL}" # package_bindir
                              "${zlib_LIBRARY_TYPE_MINSIZEREL}"
                              "${zlib_IS_HOST_WINDOWS_MINSIZEREL}"
                              zlib_DEPS_TARGET
                              zlib_LIBRARIES_TARGETS  # out_libraries_targets
                              "_MINSIZEREL"
                              "zlib"    # package_name
                              "${zlib_NO_SONAME_MODE_MINSIZEREL}")  # soname

# FIXME: What is the result of this for multi-config? All configs adding themselves to path?
set(CMAKE_MODULE_PATH ${zlib_BUILD_DIRS_MINSIZEREL} ${CMAKE_MODULE_PATH})

########## GLOBAL TARGET PROPERTIES MinSizeRel ########################################
    set_property(TARGET ZLIB::ZLIB
                 PROPERTY INTERFACE_LINK_LIBRARIES
                 $<$<CONFIG:MinSizeRel>:${zlib_OBJECTS_MINSIZEREL}>
                 $<$<CONFIG:MinSizeRel>:${zlib_LIBRARIES_TARGETS}>
                 APPEND)

    if("${zlib_LIBS_MINSIZEREL}" STREQUAL "")
        # If the package is not declaring any "cpp_info.libs" the package deps, system libs,
        # frameworks etc are not linked to the imported targets and we need to do it to the
        # global target
        set_property(TARGET ZLIB::ZLIB
                     PROPERTY INTERFACE_LINK_LIBRARIES
                     zlib_DEPS_TARGET
                     APPEND)
    endif()

    set_property(TARGET ZLIB::ZLIB
                 PROPERTY INTERFACE_LINK_OPTIONS
                 $<$<CONFIG:MinSizeRel>:${zlib_LINKER_FLAGS_MINSIZEREL}> APPEND)
    set_property(TARGET ZLIB::ZLIB
                 PROPERTY INTERFACE_INCLUDE_DIRECTORIES
                 $<$<CONFIG:MinSizeRel>:${zlib_INCLUDE_DIRS_MINSIZEREL}> APPEND)
    # Necessary to find LINK shared libraries in Linux
    set_property(TARGET ZLIB::ZLIB
                 PROPERTY INTERFACE_LINK_DIRECTORIES
                 $<$<CONFIG:MinSizeRel>:${zlib_LIB_DIRS_MINSIZEREL}> APPEND)
    set_property(TARGET ZLIB::ZLIB
                 PROPERTY INTERFACE_COMPILE_DEFINITIONS
                 $<$<CONFIG:MinSizeRel>:${zlib_COMPILE_DEFINITIONS_MINSIZEREL}> APPEND)
    set_property(TARGET ZLIB::ZLIB
                 PROPERTY INTERFACE_COMPILE_OPTIONS
                 $<$<CONFIG:MinSizeRel>:${zlib_COMPILE_OPTIONS_MINSIZEREL}> APPEND)

########## For the modules (FindXXX)
set(zlib_LIBRARIES_MINSIZEREL ZLIB::ZLIB)
