#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main() {
    int n; cin >> n;
    int cows[n];
    int cowPoss[n];
    int barn[n];
    for(int i = 0; i < n; i++) {
        cin >> cows[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> barn[i];
    }
    for(int i = 0; i < n; i++) {
        int total = 0;
        for(int j = 0; j < n; j++) {
            if(cows[i] <= barn[j]) {
                total++;
            }
        }
        cowPoss[i] = total;
    }
    sort(cowPoss, cowPoss + n);
    long long total = 1;
    for(int i  = 0; i < n; i++) {
        // cout << cowPoss[i] << endl;
        total *= cowPoss[i] - i;
    }
    cout << total;
}