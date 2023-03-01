#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n; cin >> n;
    int l; cin >> l;
    int papers[n];
    for(int i = 0; i < n; i++) {
        cin >> papers[i];
    }
    sort(papers, papers + n);
    int h = 0;
    for(; h < n; h++) {
        // cout << papers[n-1-h] << ", ";
        if(papers[n-1-h] < (h+1)) {
            if(papers[n-1-h] == h && l != 0) {
                l--;
                //check previous
            } else {
                cout << h;
                exit(0);
            }
        } 
    }
    cout << h;

}