#include <fstream>
#include <vector>
#include <iostream>
using namespace std;

bool Branje_Stevil(vector<unsigned char>& vec, const char s[]) {
    ifstream input(s);
    int st;
    if (!input.is_open()) {
        return false;
    }
    while (input >> st) {
        vec.push_back(static_cast<unsigned char>(st));
    }
    input.close();
    return true;
}