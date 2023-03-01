#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("taming.in");
ofstream fout("taming.out");

int main() {
    int n; fin >> n;
    int breakout[n];
    for(int i = 0; i < n; i++) {
        fin >> breakout[i];
    }
    bool days[n] = {};
    for(int i = n-1; i > 0 ; i--) {
        if(breakout[i] > 0) {
            if(breakout[i - breakout[i]] >0) {
                // cout << breakout[i-breakout[i]] << " ";
                fout << -1;
                exit(0);
            }
            days[i- breakout[i]] = true;
        }
    }
    days[0] = true;
    int min = 0;
    int max = 0;
    for(int i = 0; i < n; i++) {
        if(days[i]) {
            min++;
            max++;
        } else {
            if(breakout[i] == -1) {
                max++;
            }
        }
    }
    fout << min << " " << max;
}