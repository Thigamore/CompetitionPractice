#include <iostream>
using namespace std;

int main() {
    long long n; cin >> n;
    long long k; cin >> k;
    
    long long total = k + 1;
    long long prevDay;
    cin >> prevDay;
    // cout << "Total: " << total << endl;
    for(int i = 1; i < n; i++) {
        long long temp; cin >> temp;
        long long dif = temp - prevDay;
        if(dif > (k+1)) {
            total += k + 1;
        } else {
            total += dif;
        }
        prevDay = temp;
        // cout << "Total: " << total << endl;
    }
    cout << total;

}