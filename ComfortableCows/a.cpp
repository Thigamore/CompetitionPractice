#include <iostream>
#include <map>
#include <string>
using namespace std;

bool isComf(pair<int,int> coord, map<pair<int,int>, bool> farm) {
    int total = 0;
    if(farm[make_pair(coord.first + 1, coord.second)]) {
        total++;
    }
    if(farm[make_pair(coord.first - 1, coord.second)]) {
        total++;
    }
    if(farm[make_pair(coord.first, coord.second + 1)]) {
        total++;
    }
    if(farm[make_pair(coord.first, coord.second - 1)]) {
        total++;
    }
    return total == 3;
}

int main() {
    int n; cin >> n;
    map<pair<int,int>, bool> farm = {};
    map<pair<int,int>, bool> comfortable = {};
    farm[make_pair(0,0)] = true;
    int comfTotal = 0;
    string out = "";
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        int y; cin >> y;
        // cout << "(" << x << ", " << y << ")" << endl;
        pair<int, int> coord = make_pair(x,y);
        pair<int,int> curCoord = make_pair(x+1,y);
        farm[coord] = true;
        // cout << "Empty: " << comfortable.empty() << endl;
        for(auto ptr = comfortable.begin(); ptr != comfortable.end(); ++ptr) {
            if(!isComf(ptr->first, farm)) {
                comfTotal--;
                comfortable.erase(ptr->first);
            }
            // cout << "go" << endl;
        }
        if(isComf(make_pair(coord.first + 1, coord.second), farm) && (!comfortable[make_pair(coord.first + 1, coord.second)])) {
            // cout << "first" << endl;
            comfTotal++;
            comfortable[make_pair(coord.first + 1, coord.second)] = true;
        }
        if(isComf(make_pair(coord.first - 1, coord.second), farm) && (!comfortable[make_pair(coord.first - 1, coord.second)])) {
            // cout << "second" << endl;
            comfTotal++;
            comfortable[make_pair(coord.first - 1, coord.second)] = true;
        }
        if(isComf(make_pair(coord.first, coord.second + 1), farm) && (!comfortable[make_pair(coord.first, coord.second + 1)])) {
            // cout << "third" << endl;
            comfTotal++;
            comfortable[make_pair(coord.first, coord.second + 1)] = true;
        }
        if(isComf(make_pair(coord.first, coord.second - 1), farm) && (!comfortable[make_pair(coord.first, coord.second - 1)])) {
            // cout << "fourth" << endl;
            comfTotal++;
            comfortable[make_pair(coord.first, coord.second - 1)] = true;
        }
        if(isComf(coord, farm)) {
            // cout << "fifth" << endl;
            comfTotal++;
            comfortable[make_pair(coord.first, coord.second)] = true;
        }
        out += to_string(comfTotal) + "\n";
        // cout << "Coord: (" << coord.first << ", " << coord.second << ")" << endl;
    }
    cout << out;
}