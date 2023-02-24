#include <iostream>
using namespace std;

int main() {
    int n; cin >> n;
    int odd = 0;
    int even = 0;
    int in;
    for(int i = 0; i < n; i++) {
        cin >> in;
        if(in%2 == 0) {
            even++;
        } else {
            odd++;
        }
    }
    if(even == odd || even == (odd+1)) {
        cout << even + odd;
    } else if (even > odd) {
        cout << (odd * 2) + 1;
    } else if (even < odd) {
        int total = even * 2;
        odd -= even;
        for(int i = 0;odd > 1; i++) {
            if(i % 2 == 1) {
                odd -= 1;
            } else {
                odd -= 2;
            }
            total++;
            // cout << "Odd: " << odd << endl;
        }
        total -= odd;
        cout << total;
    }
}