#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ofstream fout("blocks.out");
ifstream fin("blocks.in");

int main() {
    int n; fin >> n;
    //Set to n
    string blocks[n][2];
    for(int i = 0; i < n; i ++) {
        fin >> blocks[i][0];
        fin >> blocks[i][1];
        cout << blocks[i][0] << " : " << blocks[i][1] <<endl;
    }
    
    int totalLetters[26] = {};
    for(int i = 0; i < n; i++) {
        int letters1[26] = {}; 
        int letters2[26] = {};
        for(auto ptr = blocks[i][0].begin(); ptr != blocks[i][0].end(); ++ptr) {
            letters1[((int) (*ptr)) - 97] += 1;
        }
        for(auto ptr = blocks[i][1].begin(); ptr != blocks[i][1].end(); ++ptr) {
            letters2[((int) (*ptr)) - 97] += 1;
        }
        for(int i = 0; i < 26; i++) {
            totalLetters[i] += max(letters2[i], letters1[i]);
        }
        cout <<endl;
    }
    for(int i = 0; i < 26;i++) {
        fout << totalLetters[i] << endl;
    }
}