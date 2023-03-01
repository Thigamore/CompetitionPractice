#include <iostream>
#include <map>
using namespace std;

// true if 1 is sooner than 2
bool isBeforeAlphabet(string name1, string name2) {
    int minLen = min(name1.length(), name2.length());
    for(int i = 0; i < minLen; i++) {
        if(name1.at(i) < name2.at(i)) {
            return true;
        } else if( name1.at(i) > name2.at(i)) {
            return false;
        }
    }
    return false;
}

int main() {
    int k; cin >> k;
    int n; cin >> n;
    map<string, int> seniority = {};
    string cows[n];
    string temp;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        seniority[temp] = 0;
        cows[i] = temp;
        // cout << temp << ": " << seniority[temp] << endl;
    }

    for(int i = 0; i < k; i++) {
        int count = 1;
        string temp;
        string prev;
        cin >> temp;
        seniority[temp] += count;
        prev = temp;
        for(int j = 1; j < n; j++) {
            cin >> temp;
            if(isBeforeAlphabet(temp, prev)) {
                count++;
            }
            seniority[temp] += count;
        }
    }
    // cout << endl;
    // for(auto ptr = seniority.begin(); ptr != seniority.end(); ++ptr) {
    //     cout << ptr->first << ": " << ptr->second << endl;
    // }
    // cout << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(seniority[cows[i]] == seniority[cows[j]]) {
                cout << "?";
            } else if(seniority[cows[i]] > seniority[cows[j]]) {
                cout << "1";
            } else {
                cout << "0";
            }
        }
        cout << "B";
        for(int j = i+1; j < n; j++) {
            if(seniority[cows[i]] == seniority[cows[j]]) {
                cout << "?";
            } else if(seniority[cows[i]] > seniority[cows[j]]) {
                cout << "1";
            } else {
                cout << "0";
            }
        }
        cout << endl;
    }
}