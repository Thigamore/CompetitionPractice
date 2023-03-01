#include <iostream>
#include <string>
using namespace std;


int main() {
    char cowphabet[26];
    string in;
    getline(cin, in);
    for(int i = 0; i < 26; i++) {
        cowphabet[i] = in.at(i);
    }
    getline(cin, in);
    auto ptr = in.begin();
    int total = 1;
    while(true) {
        for(int i = 0; i < 26; i++) {
            if(cowphabet[i] == (*ptr)) {
                ++ptr;
                if(ptr == in.end()) {
                    cout << total;
                    exit(0);
                }
            }
        }
        total++;
    }
}