########## MACROS ###########################################################################
#############################################################################################

# Requires CMake > 3.15
if(${CMAKE_VERSION} VERSION_LESS "3.15")
    message(FATAL_ERROR "The 'CMakeDeps' generator only works with CMake >= 3.15")
endif()

if(cereal_FIND_QUIETLY)
    set(cereal_MESSAGE_MODE VERBOSE)
else()
    set(cereal_MESSAGE_MODE STATUS)
endif()

include(${CMAKE_CURRENT_LIST_DIR}/cmakedeps_macros.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/cerealTargets.cmake)
include(CMakeFindDependencyMacro)

check_build_type_defined()

foreach(_DEPENDENCY ${cereal_FIND_DEPENDENCY_NAMES} )
    # Check that we have not already called a find_package with the transitive dependency
    if(NOT ${_DEPENDENCY}_FOUND)
        find_dependency(${_DEPENDENCY} REQUIRED ${${_DEPENDENCY}_FIND_MODE})
    endif()
endforeach()

set(cereal_VERSION_STRING "1.3.2")
set(cereal_INCLUDE_DIRS ${cereal_INCLUDE_DIRS_MINSIZEREL} )
set(cereal_INCLUDE_DIR ${cereal_INCLUDE_DIRS_MINSIZEREL} )
set(cereal_LIBRARIES ${cereal_LIBRARIES_MINSIZEREL} )
set(cereal_DEFINITIONS ${cereal_DEFINITIONS_MINSIZEREL} )

# Only the first installed configuration is included to avoid the collision
foreach(_BUILD_MODULE ${cereal_BUILD_MODULES_PATHS_MINSIZEREL} )
    message(${cereal_MESSAGE_MODE} "Conan: Including build module from '${_BUILD_MODULE}'")
    include(${_BUILD_MODULE})
endforeach()


