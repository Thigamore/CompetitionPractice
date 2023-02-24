#include <iostream>
using namespace std;

int main() {
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        char dir; cin >> dir;
        char prevDir = dir;
        int cw = 0;
        int ccw = 0;
        pair<int, int> pos = make_pair(0,0);
        do {
            if(dir == 'N') {
                pos.second++;
            } else if(dir == 'S') {
                pos.second--;
            } else if(dir == 'E') {
                pos.first++;
            } else {
                pos.first--;
            }
            if(prevDir != dir) {
                if(prevDir == 'N') {
                    if(dir == 'E') {
                        cw++;
                    } else {
                        ccw++;
                    }
                } else if(prevDir == 'S') {
                    if(dir == 'E') {
                        ccw++;
                    } else {
                        cw++;
                    }
                } else if(prevDir == 'E') {
                    if(dir == 'N') {
                        ccw++;
                    } else {
                        cw++;
                    }
                } else {
                    if(dir == 'N') {
                        cw++;
                    } else {
                        ccw++;
                    }
                }
            }
            cout << "CW: " << cw << ", CCW: " << ccw << endl;
            prevDir = dir;
            cin >> dir;
            cout << "current: " << dir << endl;
        } while(!(pos.first == 0 && pos.second == 0));
        if(cw > ccw) {
            cout << "\tCW" << endl;
        } else {
            cout << "\tCCW" << endl;
        }
    }
}