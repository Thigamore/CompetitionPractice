#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("ac.in");

// go through each

int main() {
    int n; cin >> n;
    int cowsCur[n];
    int cowsExp[n];
    for(int i = 0; i < n; i++) {
        cin >> cowsExp[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> cowsCur[i];
    }
    int diff = 0;
}