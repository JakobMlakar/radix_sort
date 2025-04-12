#ifndef RADIX_SORT_FUNCTIONS_H
#define RADIX_SORT_FUNCTIONS_H

#include <vector>

// Function declarations
bool Branje_Stevil(std::vector<unsigned char>& vec, const char s[]);
void Izpis_Stevil(const std::vector<unsigned char>& polje);
void CountingSort(std::vector<unsigned char>& A, int k);
void RadixSort(std::vector<unsigned char>& A);

#endif // RADIX_SORT_FUNCTIONS_H
