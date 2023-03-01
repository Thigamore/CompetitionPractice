#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

ifstream fin("square.in");
ofstream fout("square.out");

int main() {
    int rect1[2][2];
    int rect2[2][2];
    fin >> rect1[0][0];
    fin >> rect1[0][1];
    fin >> rect1[1][0];
    fin >> rect1[1][1];
    fin >> rect2[0][0];
    fin >> rect2[0][1];
    fin >> rect2[1][0];
    fin >> rect2[1][1];
    int topL[2];
    int botR[2];
    topL[0] = min(rect1[0][0], rect2[0][0]);
    topL[1] = max(rect1[1][1], rect2[1][1]);
    botR[0] = max(rect1[1][0], rect2[1][0]);
    botR[1] = min(rect1[0][1], rect2[0][1]);
    int width = (botR[0] - topL[0]);
    int height =(topL[1] - botR[1]);
    int big = max(width, height);
    fout << (big * big);
}