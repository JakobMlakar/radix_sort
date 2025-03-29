#include <fstream>
#include <vector>
#include <iostream>
using namespace std;

bool Branje_Stevil(vector<unsigned char>& vec, const char s[]) {
    ifstream input(s);
    int st;
    
    if (!input.is_open()) {
        cerr << "Error: Could not open file " << s << endl;
        return false;
    }
    
    while (input >> st) {
        if (st < 0 || st > 255) {
            cerr << "Warning: Number " << st << " out of range, truncating to fit unsigned char" << endl;
        }
        vec.push_back(static_cast<unsigned char>(st));
    }
    
    if (vec.empty()) {
        cerr << "Warning: No valid numbers found in file" << endl;
    }
    
    input.close();
    return !vec.empty();
}

void Izpis_Stevil(const vector<unsigned char>& polje) {
    ofstream output("out.txt");
    for (size_t i = 0; i < polje.size(); i++) {
        output << (int)polje[i] << ' ';
    }
}