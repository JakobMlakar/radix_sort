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
    int n = A.size();
    vector<unsigned char> B(n);
    int C[2] = { 0 };
    for (int i = 0; i < n; i++) {
        C[(A[i] >> k) & 1]++;
    }
    C[1] += C[0];
    for (int i = n - 1; i >= 0; i--) {
        B[--C[(A[i] >> k) & 1]] = A[i];
    }
    swap(A, B);
}