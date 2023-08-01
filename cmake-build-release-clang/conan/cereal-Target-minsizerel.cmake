# Avoid multiple calls to find_package to append duplicated properties to the targets
include_guard()########### VARIABLES #######################################################################
#############################################################################################
set(cereal_FRAMEWORKS_FOUND_MINSIZEREL "") # Will be filled later
conan_find_apple_frameworks(cereal_FRAMEWORKS_FOUND_MINSIZEREL "${cereal_FRAMEWORKS_MINSIZEREL}" "${cereal_FRAMEWORK_DIRS_MINSIZEREL}")

set(cereal_LIBRARIES_TARGETS "") # Will be filled later


######## Create an interface target to contain all the dependencies (frameworks, system and conan deps)
if(NOT TARGET cereal_DEPS_TARGET)
    add_library(cereal_DEPS_TARGET INTERFACE IMPORTED)
endif()

set_property(TARGET cereal_DEPS_TARGET
             PROPERTY INTERFACE_LINK_LIBRARIES
             $<$<CONFIG:MinSizeRel>:${cereal_FRAMEWORKS_FOUND_MINSIZEREL}>
             $<$<CONFIG:MinSizeRel>:${cereal_SYSTEM_LIBS_MINSIZEREL}>
             $<$<CONFIG:MinSizeRel>:>
             APPEND)

####### Find the libraries declared in cpp_info.libs, create an IMPORTED target for each one and link the
####### cereal_DEPS_TARGET to all of them
conan_package_library_targets("${cereal_LIBS_MINSIZEREL}"    # libraries
                              "${cereal_LIB_DIRS_MINSIZEREL}" # package_libdir
                              "${cereal_BIN_DIRS_MINSIZEREL}" # package_bindir
                              "${cereal_LIBRARY_TYPE_MINSIZEREL}"
                              "${cereal_IS_HOST_WINDOWS_MINSIZEREL}"
                              cereal_DEPS_TARGET
                              cereal_LIBRARIES_TARGETS  # out_libraries_targets
                              "_MINSIZEREL"
                              "cereal"    # package_name
                              "${cereal_NO_SONAME_MODE_MINSIZEREL}")  # soname

# FIXME: What is the result of this for multi-config? All configs adding themselves to path?
set(CMAKE_MODULE_PATH ${cereal_BUILD_DIRS_MINSIZEREL} ${CMAKE_MODULE_PATH})

########## GLOBAL TARGET PROPERTIES MinSizeRel ########################################
    set_property(TARGET cereal::cereal
                 PROPERTY INTERFACE_LINK_LIBRARIES
                 $<$<CONFIG:MinSizeRel>:${cereal_OBJECTS_MINSIZEREL}>
                 $<$<CONFIG:MinSizeRel>:${cereal_LIBRARIES_TARGETS}>
                 APPEND)

    if("${cereal_LIBS_MINSIZEREL}" STREQUAL "")
        # If the package is not declaring any "cpp_info.libs" the package deps, system libs,
        # frameworks etc are not linked to the imported targets and we need to do it to the
        # global target
        set_property(TARGET cereal::cereal
                     PROPERTY INTERFACE_LINK_LIBRARIES
                     cereal_DEPS_TARGET
                     APPEND)
    endif()

    set_property(TARGET cereal::cereal
                 PROPERTY INTERFACE_LINK_OPTIONS
                 $<$<CONFIG:MinSizeRel>:${cereal_LINKER_FLAGS_MINSIZEREL}> APPEND)
    set_property(TARGET cereal::cereal
                 PROPERTY INTERFACE_INCLUDE_DIRECTORIES
                 $<$<CONFIG:MinSizeRel>:${cereal_INCLUDE_DIRS_MINSIZEREL}> APPEND)
    # Necessary to find LINK shared libraries in Linux
    set_property(TARGET cereal::cereal
                 PROPERTY INTERFACE_LINK_DIRECTORIES
                 $<$<CONFIG:MinSizeRel>:${cereal_LIB_DIRS_MINSIZEREL}> APPEND)
    set_property(TARGET cereal::cereal
                 PROPERTY INTERFACE_COMPILE_DEFINITIONS
                 $<$<CONFIG:MinSizeRel>:${cereal_COMPILE_DEFINITIONS_MINSIZEREL}> APPEND)
    set_property(TARGET cereal::cereal
                 PROPERTY INTERFACE_COMPILE_OPTIONS
                 $<$<CONFIG:MinSizeRel>:${cereal_COMPILE_OPTIONS_MINSIZEREL}> APPEND)

########## For the modules (FindXXX)
set(cereal_LIBRARIES_MINSIZEREL cereal::cereal)
