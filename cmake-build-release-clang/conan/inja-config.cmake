########## MACROS ###########################################################################
#############################################################################################

# Requires CMake > 3.15
if(${CMAKE_VERSION} VERSION_LESS "3.15")
    message(FATAL_ERROR "The 'CMakeDeps' generator only works with CMake >= 3.15")
endif()

if(inja_FIND_QUIETLY)
    set(inja_MESSAGE_MODE VERBOSE)
else()
    set(inja_MESSAGE_MODE STATUS)
endif()

include(${CMAKE_CURRENT_LIST_DIR}/cmakedeps_macros.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/injaTargets.cmake)
include(CMakeFindDependencyMacro)

check_build_type_defined()

foreach(_DEPENDENCY ${inja_FIND_DEPENDENCY_NAMES} )
    # Check that we have not already called a find_package with the transitive dependency
    if(NOT ${_DEPENDENCY}_FOUND)
        find_dependency(${_DEPENDENCY} REQUIRED ${${_DEPENDENCY}_FIND_MODE})
    endif()
endforeach()

set(inja_VERSION_STRING "3.4.0")
set(inja_INCLUDE_DIRS ${inja_INCLUDE_DIRS_MINSIZEREL} )
set(inja_INCLUDE_DIR ${inja_INCLUDE_DIRS_MINSIZEREL} )
set(inja_LIBRARIES ${inja_LIBRARIES_MINSIZEREL} )
set(inja_DEFINITIONS ${inja_DEFINITIONS_MINSIZEREL} )

# Only the first installed configuration is included to avoid the collision
foreach(_BUILD_MODULE ${inja_BUILD_MODULES_PATHS_MINSIZEREL} )
    message(${inja_MESSAGE_MODE} "Conan: Including build module from '${_BUILD_MODULE}'")
    include(${_BUILD_MODULE})
endforeach()


