#include <iostream>
using namespace std;

int main() {
    long long n; cin >> n;
    long long t; cin >> t;
    // long long days[n];
    // long long bales[n];
    // for(int i = 0; i < n; i++) {
    //     cin >> days[i];
    //     cin >> bales[i];
    // }
    long long bales;
    long long prevDay;
    cin >> prevDay;
    cin >> bales;
    long long total = 0;
    for(int i = 1; i < n; i++) {
        long long temp; cin >> temp;
        long long dif = temp - prevDay;
        if(dif >= bales) {
            total += bales;
            bales = 0;
        } else {
            total += dif;
            bales -= dif;
        }
        prevDay = temp;
        cin >> temp;
        bales += temp;
        // cout << "Total: " << total << endl;
    }
    long long dif = t - prevDay + 1;
    if(dif >= bales) {
        total += bales;
        bales = 0;
    } else {
        total += dif;
        bales -= dif;
    }
    cout << total;
}