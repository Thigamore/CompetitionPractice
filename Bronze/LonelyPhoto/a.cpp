#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("sleepy.in");

int main() {
    int n; cin >> n;
    char cows[n];
    for(int i = 0; i < n; i++) {
        cin >> cows[i];
    }
    int total = 0;
    for(int i = 0; i < n-2; i++) {
        int G = 0;
        int H = 0;
        // cout << "Cows: " << cows[i] << ", " << cows[i+1] << ", " << cows[i+2] << endl;
        for(int j = 0; j < 3; j++) {
            if(cows[i+j] == 'G') {
                G++;
            } else {
                H++;
            }
        }
        if(G == 1) {
            total++;
        } else if (H == 1){
            total++;
        }
        if(G <= 1){
            for(int j = i+3; j < n;j++) {
                if(cows[j] == 'G') {
                    G++;
                }
                if(G == 1) {
                    total++;
                }else if (G > 1) {
                    break;
                }
            }
        } else if(H <= 1) {
            for(int j = i+3; j < n;j++) {
                if(cows[j] == 'H') {
                    H++;
                }
                if(H == 1) {
                    total++;
                }else if (H > 1) {
                    break;
                }
            }
        }
        // cout << total << endl;
    }
    cout << total;
}