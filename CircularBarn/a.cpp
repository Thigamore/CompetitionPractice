#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("cbarn.in");
ofstream fout("cbarn.out");

int main() {
    int n; fin >> n;
    int cows[n];
    for(int i = 0; i < n; i++) {
        fin >> cows[i];
    }
    int lowDist = 2147483646;
    for(int i = 0; i < n; i++) {
        int tempDist = 0;
        int mov = 1;
        for(int j = (i + 1 % n); j != i; j = ((j + 1) % n)){
            tempDist += cows[j] * mov;
            mov++;
        }
        if(tempDist < lowDist) {
            lowDist = tempDist;
        }
    }
    fout << lowDist << endl;
}