# Load the debug and release variables
get_filename_component(_DIR "${CMAKE_CURRENT_LIST_FILE}" PATH)
file(GLOB DATA_FILES "${_DIR}/cereal-*-data.cmake")

foreach(f ${DATA_FILES})
    include(${f})
endforeach()

# Create the targets for all the components
foreach(_COMPONENT ${cereal_COMPONENT_NAMES} )
    if(NOT TARGET ${_COMPONENT})
        add_library(${_COMPONENT} INTERFACE IMPORTED)
        message(${cereal_MESSAGE_MODE} "Conan: Component target declared '${_COMPONENT}'")
    endif()
endforeach()

if(NOT TARGET cereal::cereal)
    add_library(cereal::cereal INTERFACE IMPORTED)
    message(${cereal_MESSAGE_MODE} "Conan: Target declared 'cereal::cereal'")
endif()
if(NOT TARGET cereal)
    add_library(cereal INTERFACE IMPORTED)
    set_property(TARGET cereal PROPERTY INTERFACE_LINK_LIBRARIES cereal::cereal)
else()
    message(WARNING "Target name 'cereal' already exists.")
endif()
# Load the debug and release library finders
get_filename_component(_DIR "${CMAKE_CURRENT_LIST_FILE}" PATH)
file(GLOB CONFIG_FILES "${_DIR}/cereal-Target-*.cmake")

foreach(f ${CONFIG_FILES})
    include(${f})
endforeach()