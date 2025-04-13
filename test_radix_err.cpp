#include <gtest/gtest.h>
#include <vector>
#include <fstream>
#include "radix_sort_functions.h"

// Test Branje_Stevil function
TEST(RadixSortTest, ReadNumbersTest) {
    // Create a test file
    std::ofstream testFile("test_input.txt");
    testFile << "10 255 0 128";
    testFile.close();
    
    std::vector<unsigned char> numbers;
    ASSERT_TRUE(Branje_Stevil(numbers, "test_input.txt"));
    ASSERT_EQ(numbers.size(), 4);
    EXPECT_EQ(numbers[0], 10);
    EXPECT_EQ(numbers[1], 255);
    EXPECT_EQ(numbers[2], 0);
    EXPECT_EQ(numbers[3], 128);
    
    // Clean up
    remove("test_input.txt");
}

// Test RadixSort function
TEST(RadixSortTest, SortTest) {
    std::vector<unsigned char> numbers = {99, 10, 0, 255, 128};
    std::vector<unsigned char> expected = {0, 10, 99, 128, 255};
    
    RadixSort(numbers);
    EXPECT_EQ(numbers, expected);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
