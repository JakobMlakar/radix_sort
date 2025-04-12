#include <vector>
#include <iostream>
#include "radix_sort_functions.h"
using namespace std;

int main(int argc, const char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <input_file>" << endl;
        return 0;
    }
    vector<unsigned char> A;
    if (!Branje_Stevil(A, argv[1])) return 0;
    RadixSort(A);
    Izpis_Stevil(A);
    return 0;
}
