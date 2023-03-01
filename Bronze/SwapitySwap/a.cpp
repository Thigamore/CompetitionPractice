#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("swap.in");
ofstream fout("swap.out");

int swapGroup(int arr[], int start, int end) {
    int len = (end-start)/2 + ((end-start) %2);
    for(int i = 0; i < len; i++) {
        swap(arr[start + i - 1], arr[end-i-1]);
    }
}

int main() {
    int n; fin >> n;
    int k; fin >> k;
    int pos[n];
    int A[2];
    int B[2];
    for(int i = 0; i < n; i++) {
        pos[i] = i+1;
    }
    fin >> A[0];
    fin >> A[1];
    fin >> B[0];
    fin >> B[1];
    for(int i = 0; i < k; i++) {
        swapGroup(pos, A[0], A[1]);
        // for(int i = 0; i < sizeof(pos)/sizeof(int); i++) {
        //     cout << pos[i] << ", ";
        // }
        // cout << endl;
        swapGroup(pos, B[0], B[1]);
        // for(int i = 0; i < sizeof(pos)/sizeof(int); i++) {
        //     cout << pos[i] << ", ";
        // }
        // cout << endl;
        // cout << endl;
    }
    for(int i = 0; i < (sizeof(pos) / sizeof(int)); i++) {
        fout << pos[i] << endl;
    }
}