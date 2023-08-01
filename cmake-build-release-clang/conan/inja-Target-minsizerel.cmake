# Avoid multiple calls to find_package to append duplicated properties to the targets
include_guard()########### VARIABLES #######################################################################
#############################################################################################
set(inja_FRAMEWORKS_FOUND_MINSIZEREL "") # Will be filled later
conan_find_apple_frameworks(inja_FRAMEWORKS_FOUND_MINSIZEREL "${inja_FRAMEWORKS_MINSIZEREL}" "${inja_FRAMEWORK_DIRS_MINSIZEREL}")

set(inja_LIBRARIES_TARGETS "") # Will be filled later


######## Create an interface target to contain all the dependencies (frameworks, system and conan deps)
if(NOT TARGET inja_DEPS_TARGET)
    add_library(inja_DEPS_TARGET INTERFACE IMPORTED)
endif()

set_property(TARGET inja_DEPS_TARGET
             PROPERTY INTERFACE_LINK_LIBRARIES
             $<$<CONFIG:MinSizeRel>:${inja_FRAMEWORKS_FOUND_MINSIZEREL}>
             $<$<CONFIG:MinSizeRel>:${inja_SYSTEM_LIBS_MINSIZEREL}>
             $<$<CONFIG:MinSizeRel>:nlohmann_json::nlohmann_json>
             APPEND)

####### Find the libraries declared in cpp_info.libs, create an IMPORTED target for each one and link the
####### inja_DEPS_TARGET to all of them
conan_package_library_targets("${inja_LIBS_MINSIZEREL}"    # libraries
                              "${inja_LIB_DIRS_MINSIZEREL}" # package_libdir
                              "${inja_BIN_DIRS_MINSIZEREL}" # package_bindir
                              "${inja_LIBRARY_TYPE_MINSIZEREL}"
                              "${inja_IS_HOST_WINDOWS_MINSIZEREL}"
                              inja_DEPS_TARGET
                              inja_LIBRARIES_TARGETS  # out_libraries_targets
                              "_MINSIZEREL"
                              "inja"    # package_name
                              "${inja_NO_SONAME_MODE_MINSIZEREL}")  # soname

# FIXME: What is the result of this for multi-config? All configs adding themselves to path?
set(CMAKE_MODULE_PATH ${inja_BUILD_DIRS_MINSIZEREL} ${CMAKE_MODULE_PATH})

########## COMPONENTS TARGET PROPERTIES MinSizeRel ########################################

    ########## COMPONENT pantor::inja #############

        set(inja_pantor_inja_FRAMEWORKS_FOUND_MINSIZEREL "")
        conan_find_apple_frameworks(inja_pantor_inja_FRAMEWORKS_FOUND_MINSIZEREL "${inja_pantor_inja_FRAMEWORKS_MINSIZEREL}" "${inja_pantor_inja_FRAMEWORK_DIRS_MINSIZEREL}")

        set(inja_pantor_inja_LIBRARIES_TARGETS "")

        ######## Create an interface target to contain all the dependencies (frameworks, system and conan deps)
        if(NOT TARGET inja_pantor_inja_DEPS_TARGET)
            add_library(inja_pantor_inja_DEPS_TARGET INTERFACE IMPORTED)
        endif()

        set_property(TARGET inja_pantor_inja_DEPS_TARGET
                     PROPERTY INTERFACE_LINK_LIBRARIES
                     $<$<CONFIG:MinSizeRel>:${inja_pantor_inja_FRAMEWORKS_FOUND_MINSIZEREL}>
                     $<$<CONFIG:MinSizeRel>:${inja_pantor_inja_SYSTEM_LIBS_MINSIZEREL}>
                     $<$<CONFIG:MinSizeRel>:${inja_pantor_inja_DEPENDENCIES_MINSIZEREL}>
                     APPEND)

        ####### Find the libraries declared in cpp_info.component["xxx"].libs,
        ####### create an IMPORTED target for each one and link the 'inja_pantor_inja_DEPS_TARGET' to all of them
        conan_package_library_targets("${inja_pantor_inja_LIBS_MINSIZEREL}"
                              "${inja_pantor_inja_LIB_DIRS_MINSIZEREL}"
                              "${inja_pantor_inja_BIN_DIRS_MINSIZEREL}" # package_bindir
                              "${inja_pantor_inja_LIBRARY_TYPE_MINSIZEREL}"
                              "${inja_pantor_inja_IS_HOST_WINDOWS_MINSIZEREL}"
                              inja_pantor_inja_DEPS_TARGET
                              inja_pantor_inja_LIBRARIES_TARGETS
                              "_MINSIZEREL"
                              "inja_pantor_inja"
                              "${inja_pantor_inja_NO_SONAME_MODE_MINSIZEREL}")


        ########## TARGET PROPERTIES #####################################
        set_property(TARGET pantor::inja
                     PROPERTY INTERFACE_LINK_LIBRARIES
                     $<$<CONFIG:MinSizeRel>:${inja_pantor_inja_OBJECTS_MINSIZEREL}>
                     $<$<CONFIG:MinSizeRel>:${inja_pantor_inja_LIBRARIES_TARGETS}>
                     APPEND)

        if("${inja_pantor_inja_LIBS_MINSIZEREL}" STREQUAL "")
            # If the component is not declaring any "cpp_info.components['foo'].libs" the system, frameworks etc are not
            # linked to the imported targets and we need to do it to the global target
            set_property(TARGET pantor::inja
                         PROPERTY INTERFACE_LINK_LIBRARIES
                         inja_pantor_inja_DEPS_TARGET
                         APPEND)
        endif()

        set_property(TARGET pantor::inja PROPERTY INTERFACE_LINK_OPTIONS
                     $<$<CONFIG:MinSizeRel>:${inja_pantor_inja_LINKER_FLAGS_MINSIZEREL}> APPEND)
        set_property(TARGET pantor::inja PROPERTY INTERFACE_INCLUDE_DIRECTORIES
                     $<$<CONFIG:MinSizeRel>:${inja_pantor_inja_INCLUDE_DIRS_MINSIZEREL}> APPEND)
        set_property(TARGET pantor::inja PROPERTY INTERFACE_LINK_DIRECTORIES
                     $<$<CONFIG:MinSizeRel>:${inja_pantor_inja_LIB_DIRS_MINSIZEREL}> APPEND)
        set_property(TARGET pantor::inja PROPERTY INTERFACE_COMPILE_DEFINITIONS
                     $<$<CONFIG:MinSizeRel>:${inja_pantor_inja_COMPILE_DEFINITIONS_MINSIZEREL}> APPEND)
        set_property(TARGET pantor::inja PROPERTY INTERFACE_COMPILE_OPTIONS
                     $<$<CONFIG:MinSizeRel>:${inja_pantor_inja_COMPILE_OPTIONS_MINSIZEREL}> APPEND)

    ########## AGGREGATED GLOBAL TARGET WITH THE COMPONENTS #####################
    set_property(TARGET pantor::inja PROPERTY INTERFACE_LINK_LIBRARIES pantor::inja APPEND)

########## For the modules (FindXXX)
set(inja_LIBRARIES_MINSIZEREL pantor::inja)
