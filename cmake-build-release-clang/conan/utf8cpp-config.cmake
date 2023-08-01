########## MACROS ###########################################################################
#############################################################################################

# Requires CMake > 3.15
if(${CMAKE_VERSION} VERSION_LESS "3.15")
    message(FATAL_ERROR "The 'CMakeDeps' generator only works with CMake >= 3.15")
endif()

if(utf8cpp_FIND_QUIETLY)
    set(utf8cpp_MESSAGE_MODE VERBOSE)
else()
    set(utf8cpp_MESSAGE_MODE STATUS)
endif()

include(${CMAKE_CURRENT_LIST_DIR}/cmakedeps_macros.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/utf8cppTargets.cmake)
include(CMakeFindDependencyMacro)

check_build_type_defined()

foreach(_DEPENDENCY ${utfcpp_FIND_DEPENDENCY_NAMES} )
    # Check that we have not already called a find_package with the transitive dependency
    if(NOT ${_DEPENDENCY}_FOUND)
        find_dependency(${_DEPENDENCY} REQUIRED ${${_DEPENDENCY}_FIND_MODE})
    endif()
endforeach()

set(utf8cpp_VERSION_STRING "3.2.1")
set(utf8cpp_INCLUDE_DIRS ${utfcpp_INCLUDE_DIRS_MINSIZEREL} )
set(utf8cpp_INCLUDE_DIR ${utfcpp_INCLUDE_DIRS_MINSIZEREL} )
set(utf8cpp_LIBRARIES ${utfcpp_LIBRARIES_MINSIZEREL} )
set(utf8cpp_DEFINITIONS ${utfcpp_DEFINITIONS_MINSIZEREL} )

# Only the first installed configuration is included to avoid the collision
foreach(_BUILD_MODULE ${utfcpp_BUILD_MODULES_PATHS_MINSIZEREL} )
    message(${utf8cpp_MESSAGE_MODE} "Conan: Including build module from '${_BUILD_MODULE}'")
    include(${_BUILD_MODULE})
endforeach()


