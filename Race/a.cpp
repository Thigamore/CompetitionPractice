#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("race.in");
ofstream fout("race.out");

int calcDistance(int fina, int cur) {
    return (abs(fina-cur) * abs(min(fina,cur) -1+  max(fina,cur)))/2;
}

int main() {
    int k; fin >> k;
    int n; fin >> n;
    int speeds[n];
    for(int i = 0; i < n; i++) {
        fin >> speeds[i];
    }
    for(int i = 0; i < n; i++) {
        int fSpeed = speeds[i];
        int moves = 0;
        int dLeft = k;
        int cSpeed = 0;
        while(true) {
            int curDist = calcDistance(fSpeed, cSpeed);
            cout << "Cur: " << curDist << ", End: " <<  dLeft << endl;
            if(dLeft == curDist) {
                cout << "done" << endl;
                cout << moves + abs(fSpeed - cSpeed) << endl;
                break;
            } else if((curDist + cSpeed) >= dLeft) {
                cSpeed--;
            } else if(curDist < dLeft) {
                cout << "see fast" << endl;
                int futureDist = cSpeed + calcDistance(fSpeed, cSpeed + 1);
                cout << "\tFuture: " << futureDist <<endl;
                if(futureDist < dLeft) {
                    cout << "\tIncrease Speed" << endl;
                    cSpeed++;
                } 
            } 
            dLeft -= cSpeed;
            moves++;
        }
    }

    return 0;
}