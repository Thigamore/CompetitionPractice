#include <iostream>

using namespace std;

int main() {
    int n; cin >> n;
    int q; cin >> q;

    int nums[n];
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    for(int i = 0; i < q; i++) {
        int l,r;
        cin >> l;
        cin >> r;
        int total = 0;

        for(;l < r; l++) {
            total += nums[l];
        }
        cout << total << endl;
    }
}