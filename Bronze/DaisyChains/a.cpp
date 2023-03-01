#include <iostream>

using namespace std;

int main() {
    int n; cin >> n;
    int flowers[n];
    for(int i = 0 ; i < n; i++) {
        cin >> flowers[i];
    }
    int total = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            int avg = 0;
            for(int k = i; k <= j; k++) {
                avg += flowers[k];
            }
            // cout << "avg: " << avg << endl;
            for(int k = i; k <= j; k++) {
                if((flowers[k] * (j-i+1))  == avg) {
                    total++;
                    break;
                }
            }
        }
    }
    cout << total;
}