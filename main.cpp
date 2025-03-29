#include <fstream>
#include <vector>
#include <iostream>
using namespace std;

bool Branje_Stevil(vector<unsigned char>& vec, const char s[]) {
    ifstream input(s);
    int st;
    
    // Check if file opened successfully
    if (!input.is_open()) {
        cerr << "Error: Could not open file " << s << endl;
        return false;
    }
    
    // Read numbers from file
    while (input >> st) {
        // Validate number range (0-255 for unsigned char)
        if (st < 0 || st > 255) {
            cerr << "Warning: Number " << st << " out of range, truncating to fit unsigned char" << endl;
        }
        vec.push_back(static_cast<unsigned char>(st));
    }
    
    // Check if any numbers were read
    if (vec.empty()) {
        cerr << "Warning: No valid numbers found in file" << endl;
    }
    
    input.close();
    return !vec.empty();
}

void Izpis_Stevil(const vector<unsigned char>& polje) {
    ofstream output("out.txt");
    
    // Check if file opened successfully
    if (!output.is_open()) {
        cerr << "Error: Could not open output file" << endl;
        return;
    }
    
    // Write numbers to file
    for (size_t i = 0; i < polje.size(); i++) {
        output << (int)polje[i] << ' ';
    }
    
    // Confirm completion
    cout << "Successfully wrote " << polje.size() << " numbers to out.txt" << endl;
    
    output.close();
}

void CountingSort(vector<unsigned char>& A, int k) {
    // Validate input parameters
    if (k < 0 || k >= 8) {
        cerr << "Error: Bit position must be between 0 and 7" << endl;
        return;
    }
    
    if (A.empty()) {
        return; // Nothing to sort
    }
    
    int n = A.size();
    vector<unsigned char> B(n); // Output array
    int C[2] = { 0 };  // Counter array for binary digits (0 or 1)
    
    // Count occurrences of each value at bit position k
    for (int i = 0; i < n; i++) {
        C[(A[i] >> k) & 1]++;
    }
    
    // Calculate cumulative counts
    C[1] += C[0];
    
    // Build the output array in a stable manner (working from end to maintain stability)
    for (int i = n - 1; i >= 0; i--) {
        B[--C[(A[i] >> k) & 1]] = A[i];
    }
    
    // Copy back to the original array
    swap(A, B);
}