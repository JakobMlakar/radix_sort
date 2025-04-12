cmake_minimum_required(VERSION 3.10)
project(RadixSort)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE_FILES
    main.cpp
)

add_executable(radix_sort ${SOURCE_FILES})

enable_testing()

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(run_tests test_radix.cpp ${SOURCE_FILES})
target_link_libraries(run_tests ${GTEST_LIBRARIES} pthread)

target_compile_definitions(run_tests PRIVATE TESTING)

add_test(NAME RadixSortTests COMMAND run_tests)
