set(MAKEFILEGEN_TESTS /
        Depfile_test.cpp
        test_main.cpp)

set(TESTED_SOURCES /
        ../src/data_model/Depfile.cpp ../includes/data_model/Depfile.h#
        ../src/data_model/Constraints.cpp ../includes/data_model/Constraints.h
        ../src/data_model/Script.cpp ../includes/data_model/Script.h
        )

add_executable(tests ${MAKEFILEGEN_TESTS} ${TESTED_SOURCES})

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Link runTests with what we want to test and the GTest and pthread library
target_link_libraries(tests ${GTEST_LIBRARIES} pthread)


configure_file(files/Depfile ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)



