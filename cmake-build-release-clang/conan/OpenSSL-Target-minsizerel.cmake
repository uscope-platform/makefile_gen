# Avoid multiple calls to find_package to append duplicated properties to the targets
include_guard()########### VARIABLES #######################################################################
#############################################################################################
set(openssl_FRAMEWORKS_FOUND_MINSIZEREL "") # Will be filled later
conan_find_apple_frameworks(openssl_FRAMEWORKS_FOUND_MINSIZEREL "${openssl_FRAMEWORKS_MINSIZEREL}" "${openssl_FRAMEWORK_DIRS_MINSIZEREL}")

set(openssl_LIBRARIES_TARGETS "") # Will be filled later


######## Create an interface target to contain all the dependencies (frameworks, system and conan deps)
if(NOT TARGET openssl_DEPS_TARGET)
    add_library(openssl_DEPS_TARGET INTERFACE IMPORTED)
endif()

set_property(TARGET openssl_DEPS_TARGET
             PROPERTY INTERFACE_LINK_LIBRARIES
             $<$<CONFIG:MinSizeRel>:${openssl_FRAMEWORKS_FOUND_MINSIZEREL}>
             $<$<CONFIG:MinSizeRel>:${openssl_SYSTEM_LIBS_MINSIZEREL}>
             $<$<CONFIG:MinSizeRel>:OpenSSL::Crypto;ZLIB::ZLIB>
             APPEND)

####### Find the libraries declared in cpp_info.libs, create an IMPORTED target for each one and link the
####### openssl_DEPS_TARGET to all of them
conan_package_library_targets("${openssl_LIBS_MINSIZEREL}"    # libraries
                              "${openssl_LIB_DIRS_MINSIZEREL}" # package_libdir
                              "${openssl_BIN_DIRS_MINSIZEREL}" # package_bindir
                              "${openssl_LIBRARY_TYPE_MINSIZEREL}"
                              "${openssl_IS_HOST_WINDOWS_MINSIZEREL}"
                              openssl_DEPS_TARGET
                              openssl_LIBRARIES_TARGETS  # out_libraries_targets
                              "_MINSIZEREL"
                              "openssl"    # package_name
                              "${openssl_NO_SONAME_MODE_MINSIZEREL}")  # soname

# FIXME: What is the result of this for multi-config? All configs adding themselves to path?
set(CMAKE_MODULE_PATH ${openssl_BUILD_DIRS_MINSIZEREL} ${CMAKE_MODULE_PATH})

########## COMPONENTS TARGET PROPERTIES MinSizeRel ########################################

    ########## COMPONENT OpenSSL::SSL #############

        set(openssl_OpenSSL_SSL_FRAMEWORKS_FOUND_MINSIZEREL "")
        conan_find_apple_frameworks(openssl_OpenSSL_SSL_FRAMEWORKS_FOUND_MINSIZEREL "${openssl_OpenSSL_SSL_FRAMEWORKS_MINSIZEREL}" "${openssl_OpenSSL_SSL_FRAMEWORK_DIRS_MINSIZEREL}")

        set(openssl_OpenSSL_SSL_LIBRARIES_TARGETS "")

        ######## Create an interface target to contain all the dependencies (frameworks, system and conan deps)
        if(NOT TARGET openssl_OpenSSL_SSL_DEPS_TARGET)
            add_library(openssl_OpenSSL_SSL_DEPS_TARGET INTERFACE IMPORTED)
        endif()

        set_property(TARGET openssl_OpenSSL_SSL_DEPS_TARGET
                     PROPERTY INTERFACE_LINK_LIBRARIES
                     $<$<CONFIG:MinSizeRel>:${openssl_OpenSSL_SSL_FRAMEWORKS_FOUND_MINSIZEREL}>
                     $<$<CONFIG:MinSizeRel>:${openssl_OpenSSL_SSL_SYSTEM_LIBS_MINSIZEREL}>
                     $<$<CONFIG:MinSizeRel>:${openssl_OpenSSL_SSL_DEPENDENCIES_MINSIZEREL}>
                     APPEND)

        ####### Find the libraries declared in cpp_info.component["xxx"].libs,
        ####### create an IMPORTED target for each one and link the 'openssl_OpenSSL_SSL_DEPS_TARGET' to all of them
        conan_package_library_targets("${openssl_OpenSSL_SSL_LIBS_MINSIZEREL}"
                              "${openssl_OpenSSL_SSL_LIB_DIRS_MINSIZEREL}"
                              "${openssl_OpenSSL_SSL_BIN_DIRS_MINSIZEREL}" # package_bindir
                              "${openssl_OpenSSL_SSL_LIBRARY_TYPE_MINSIZEREL}"
                              "${openssl_OpenSSL_SSL_IS_HOST_WINDOWS_MINSIZEREL}"
                              openssl_OpenSSL_SSL_DEPS_TARGET
                              openssl_OpenSSL_SSL_LIBRARIES_TARGETS
                              "_MINSIZEREL"
                              "openssl_OpenSSL_SSL"
                              "${openssl_OpenSSL_SSL_NO_SONAME_MODE_MINSIZEREL}")


        ########## TARGET PROPERTIES #####################################
        set_property(TARGET OpenSSL::SSL
                     PROPERTY INTERFACE_LINK_LIBRARIES
                     $<$<CONFIG:MinSizeRel>:${openssl_OpenSSL_SSL_OBJECTS_MINSIZEREL}>
                     $<$<CONFIG:MinSizeRel>:${openssl_OpenSSL_SSL_LIBRARIES_TARGETS}>
                     APPEND)

        if("${openssl_OpenSSL_SSL_LIBS_MINSIZEREL}" STREQUAL "")
            # If the component is not declaring any "cpp_info.components['foo'].libs" the system, frameworks etc are not
            # linked to the imported targets and we need to do it to the global target
            set_property(TARGET OpenSSL::SSL
                         PROPERTY INTERFACE_LINK_LIBRARIES
                         openssl_OpenSSL_SSL_DEPS_TARGET
                         APPEND)
        endif()

        set_property(TARGET OpenSSL::SSL PROPERTY INTERFACE_LINK_OPTIONS
                     $<$<CONFIG:MinSizeRel>:${openssl_OpenSSL_SSL_LINKER_FLAGS_MINSIZEREL}> APPEND)
        set_property(TARGET OpenSSL::SSL PROPERTY INTERFACE_INCLUDE_DIRECTORIES
                     $<$<CONFIG:MinSizeRel>:${openssl_OpenSSL_SSL_INCLUDE_DIRS_MINSIZEREL}> APPEND)
        set_property(TARGET OpenSSL::SSL PROPERTY INTERFACE_LINK_DIRECTORIES
                     $<$<CONFIG:MinSizeRel>:${openssl_OpenSSL_SSL_LIB_DIRS_MINSIZEREL}> APPEND)
        set_property(TARGET OpenSSL::SSL PROPERTY INTERFACE_COMPILE_DEFINITIONS
                     $<$<CONFIG:MinSizeRel>:${openssl_OpenSSL_SSL_COMPILE_DEFINITIONS_MINSIZEREL}> APPEND)
        set_property(TARGET OpenSSL::SSL PROPERTY INTERFACE_COMPILE_OPTIONS
                     $<$<CONFIG:MinSizeRel>:${openssl_OpenSSL_SSL_COMPILE_OPTIONS_MINSIZEREL}> APPEND)

    ########## COMPONENT OpenSSL::Crypto #############

        set(openssl_OpenSSL_Crypto_FRAMEWORKS_FOUND_MINSIZEREL "")
        conan_find_apple_frameworks(openssl_OpenSSL_Crypto_FRAMEWORKS_FOUND_MINSIZEREL "${openssl_OpenSSL_Crypto_FRAMEWORKS_MINSIZEREL}" "${openssl_OpenSSL_Crypto_FRAMEWORK_DIRS_MINSIZEREL}")

        set(openssl_OpenSSL_Crypto_LIBRARIES_TARGETS "")

        ######## Create an interface target to contain all the dependencies (frameworks, system and conan deps)
        if(NOT TARGET openssl_OpenSSL_Crypto_DEPS_TARGET)
            add_library(openssl_OpenSSL_Crypto_DEPS_TARGET INTERFACE IMPORTED)
        endif()

        set_property(TARGET openssl_OpenSSL_Crypto_DEPS_TARGET
                     PROPERTY INTERFACE_LINK_LIBRARIES
                     $<$<CONFIG:MinSizeRel>:${openssl_OpenSSL_Crypto_FRAMEWORKS_FOUND_MINSIZEREL}>
                     $<$<CONFIG:MinSizeRel>:${openssl_OpenSSL_Crypto_SYSTEM_LIBS_MINSIZEREL}>
                     $<$<CONFIG:MinSizeRel>:${openssl_OpenSSL_Crypto_DEPENDENCIES_MINSIZEREL}>
                     APPEND)

        ####### Find the libraries declared in cpp_info.component["xxx"].libs,
        ####### create an IMPORTED target for each one and link the 'openssl_OpenSSL_Crypto_DEPS_TARGET' to all of them
        conan_package_library_targets("${openssl_OpenSSL_Crypto_LIBS_MINSIZEREL}"
                              "${openssl_OpenSSL_Crypto_LIB_DIRS_MINSIZEREL}"
                              "${openssl_OpenSSL_Crypto_BIN_DIRS_MINSIZEREL}" # package_bindir
                              "${openssl_OpenSSL_Crypto_LIBRARY_TYPE_MINSIZEREL}"
                              "${openssl_OpenSSL_Crypto_IS_HOST_WINDOWS_MINSIZEREL}"
                              openssl_OpenSSL_Crypto_DEPS_TARGET
                              openssl_OpenSSL_Crypto_LIBRARIES_TARGETS
                              "_MINSIZEREL"
                              "openssl_OpenSSL_Crypto"
                              "${openssl_OpenSSL_Crypto_NO_SONAME_MODE_MINSIZEREL}")


        ########## TARGET PROPERTIES #####################################
        set_property(TARGET OpenSSL::Crypto
                     PROPERTY INTERFACE_LINK_LIBRARIES
                     $<$<CONFIG:MinSizeRel>:${openssl_OpenSSL_Crypto_OBJECTS_MINSIZEREL}>
                     $<$<CONFIG:MinSizeRel>:${openssl_OpenSSL_Crypto_LIBRARIES_TARGETS}>
                     APPEND)

        if("${openssl_OpenSSL_Crypto_LIBS_MINSIZEREL}" STREQUAL "")
            # If the component is not declaring any "cpp_info.components['foo'].libs" the system, frameworks etc are not
            # linked to the imported targets and we need to do it to the global target
            set_property(TARGET OpenSSL::Crypto
                         PROPERTY INTERFACE_LINK_LIBRARIES
                         openssl_OpenSSL_Crypto_DEPS_TARGET
                         APPEND)
        endif()

        set_property(TARGET OpenSSL::Crypto PROPERTY INTERFACE_LINK_OPTIONS
                     $<$<CONFIG:MinSizeRel>:${openssl_OpenSSL_Crypto_LINKER_FLAGS_MINSIZEREL}> APPEND)
        set_property(TARGET OpenSSL::Crypto PROPERTY INTERFACE_INCLUDE_DIRECTORIES
                     $<$<CONFIG:MinSizeRel>:${openssl_OpenSSL_Crypto_INCLUDE_DIRS_MINSIZEREL}> APPEND)
        set_property(TARGET OpenSSL::Crypto PROPERTY INTERFACE_LINK_DIRECTORIES
                     $<$<CONFIG:MinSizeRel>:${openssl_OpenSSL_Crypto_LIB_DIRS_MINSIZEREL}> APPEND)
        set_property(TARGET OpenSSL::Crypto PROPERTY INTERFACE_COMPILE_DEFINITIONS
                     $<$<CONFIG:MinSizeRel>:${openssl_OpenSSL_Crypto_COMPILE_DEFINITIONS_MINSIZEREL}> APPEND)
        set_property(TARGET OpenSSL::Crypto PROPERTY INTERFACE_COMPILE_OPTIONS
                     $<$<CONFIG:MinSizeRel>:${openssl_OpenSSL_Crypto_COMPILE_OPTIONS_MINSIZEREL}> APPEND)

    ########## AGGREGATED GLOBAL TARGET WITH THE COMPONENTS #####################
    set_property(TARGET openssl::openssl PROPERTY INTERFACE_LINK_LIBRARIES OpenSSL::SSL APPEND)
    set_property(TARGET openssl::openssl PROPERTY INTERFACE_LINK_LIBRARIES OpenSSL::Crypto APPEND)

########## For the modules (FindXXX)
set(openssl_LIBRARIES_MINSIZEREL openssl::openssl)
