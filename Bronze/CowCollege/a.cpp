#include <fstream>
#include <iostream>
#include <map>

using namespace std;

int main()
{
    int cNum;
    long long in;
    cin >> cNum;
    map<long long, int> m;
    for(int i = 0; i < cNum; i++) {
        cin >> in;
        m[in] += 1;
    }
    long long cPrice = 0;
    long long tuition = 0;
    long long bestTuition = -1;
    long long bestPrice;
    auto curPtr = m.begin();
    while(curPtr != m.end()) {
        tuition = 0;
        cPrice = curPtr->first;
        for(auto tempPtr = curPtr; tempPtr != m.end(); tempPtr++) {
            tuition += cPrice * tempPtr->second;
        }
        if( tuition > bestTuition) {
            bestTuition = tuition;
            bestPrice = cPrice;
        }
        curPtr++;
    }
    cout <<  bestTuition << " " << bestPrice;
}
