#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("outofplace.in");
ofstream fout("outofplace.out");

int main() {
    int n; fin >> n;
    int heights[n];
    for(int i = 0; i < n; i++ ) {
        fin >> heights[i];
    }
    int pos = -1;
    int num;
    for(int i = 1; i < n; i++) {
        // cout << "i: " << heights[i] << ", i-1: " << heights[i-1] << endl;
        if(heights[i] < heights[i-1]) {
            // cout << "Found: ";
            pos = i;
            // cout << pos << endl;
            num = heights[i];
            break;
        }
    }
    if(pos == -1) {
        fout << 0;
        exit(0);
    }
    int expPos = n-1;
    for(int i = 0; i < n; i++) {
        if(num < heights[i]) {
            expPos = i;
            break;
        }
    }
    // cout << "Pos: " << pos<< endl;
    int maxPos = max(expPos, pos) + 1;
    int total = 0;
    for(int i = min(expPos, pos) + 1; i < maxPos; i++) {
        if(heights[i-1] != heights[i]) {
            total++;
        }
    }
    fout << total;
}