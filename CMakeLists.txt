cmake_minimum_required(VERSION 3.10)
project(RadixSort)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add the library with your functions
add_library(radix_sort_lib radix_sort_functions.cpp)

# Add the main executable
add_executable(radix_sort main.cpp)
target_link_libraries(radix_sort radix_sort_lib)

# Enable testing
enable_testing()

# Find GTest package
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Add the test executable
add_executable(run_tests test_radix.cpp)
target_link_libraries(run_tests radix_sort_lib ${GTEST_LIBRARIES} pthread)

# Add test
add_test(NAME RadixSortTests COMMAND run_tests)
