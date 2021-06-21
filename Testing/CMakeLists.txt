set(MAKEFILEGEN_TESTS /
        test_main.cpp /
        data_model/Depfile_test.cpp /
        data_model/Script_test.cpp /
        data_model/Constraints_test.cpp /
        data_model/hdl_resource_testing.cpp/
        data_model/settings_store_test.cpp)

set(TESTED_SOURCES /
        ../src/data_model/Depfile.cpp ../includes/data_model/Depfile.h   /
        ../src/data_model/Constraints.cpp ../includes/data_model/Constraints.h /
        ../src/data_model/Script.cpp ../includes/data_model/Script.h /
        ../src/data_model/HDL_Resource.cpp ../includes/data_model/HDL_Resource.h
        ../src/data_model/settings_store.cpp ../includes/data_model/settings_store.h
        )

add_executable(tests ${MAKEFILEGEN_TESTS} ${TESTED_SOURCES})

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Link runTests with what we want to test and the GTest and pthread library
target_link_libraries(tests ${GTEST_LIBRARIES} pthread)


configure_file(files/Depfile ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)



