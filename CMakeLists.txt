cmake_minimum_required(VERSION 3.10)
project(RadixSort)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Source files excluding test files
set(SOURCE_FILES main.cpp)

# Create the main executable
add_executable(radix_sort ${SOURCE_FILES})

# Enable testing
enable_testing()

# Find GTest package
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Add test executable - include all the source files except main.cpp
# This avoids "multiple definition of main" errors
add_executable(run_tests 
    test_radix.cpp
    # Include your source files without main.cpp here
)

# Link against GTest libraries
target_link_libraries(run_tests ${GTEST_LIBRARIES} pthread)

# Add test
add_test(NAME RadixSortTests COMMAND run_tests)
