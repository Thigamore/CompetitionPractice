#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("bcount.in");
ofstream fout("bcount.out");

int main() {
    int n; fin >> n;
    int q; fin >> q;
    int h[n+1] = {};
    int g[n+1] = {};
    int j[n+1] = {};
    for(int i = 1; i < n+1; i++) {
        int temp; fin >> temp;
        switch(temp) {
            case 1:
                h[i]++;
                break;
            case 2:
                g[i]++;
                break;
            case 3:
                j[i]++;
                break;
        }
        h[i] += h[i-1];
        g[i] += g[i-1];
        j[i] += j[i-1];
        // cout << h[i] << " " << g[i] << " " << j[i] << endl;
    }
    // cout << endl;
    for(int i = 0; i < q; i++) {
        int a; fin >> a;
        int b; fin >> b;
        fout << h[b] - h[a-1] << " " << g[b] - g[a-1] << " " << j[b] - j[a-1] << endl;
    }
}