#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("sleepy.in");
ofstream fout("sleepy.out");

// from the back
//      take first one out of place, replace with first
//      put new first one where it belongs

void printCows(int cows[], int len) {
    cout << "Cows: {";
    for(int i = 0; i < len; i++) {
        cout << cows[i] << ",";
    }
    cout << "}\n";
}

int main() {
    int n; fin >> n;
    int cows[n];
    for(int i = 0; i < n; i++) {
        fin >> cows[i];
    }
    int moves = 0;
    printCows(cows, n);
    int last = -1;
    int biggest = -1;
    for(int i = 0; i < n; i++) {
        if(cows[i] != i + 1) {
            for(int j = i; j < n; j++) {
                if(cows[j] == j+1) {
                    break;
                }
                swap(cows[j], cows[j+1]);
            }
            moves += i + 1;
        }
    }
    fout << moves;
}