#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("gymnastics.in");
ofstream fout("gymnastics.out");

int main() {
    int r; fin >> r;
    int n; fin >> n;
    int gym[r][n];
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < n; j++) {
            fin >> gym[i][j];
        }
    }

    int total = 0;
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            int wins = 0;
            int losses = 0;
            int pos1;
            int pos2;
            for(int k = 0; k < r; k++) {
                for(int l = 0; l < n; l++) {
                    if(gym[k][l] == i) {
                        pos1 = l;
                    } else if(gym[k][l] == j) {
                        pos2 = l;
                    }
                }
                if(pos1 > pos2) {
                    wins++;
                } else {
                    losses++;
                }
            }
            if(max(wins,losses) == r) {
                total++;
            }
        }
    }    

    fout << total;
}