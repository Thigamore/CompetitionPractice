#include <fstream>
#include <iostream>

using namespace std;

ifstream fin("paint.in");
ofstream fout("paint.out");

int main()
{
    int a,b,c,d = 0;
    fin >> a;
    fin >> b;
    fin >> c;
    fin >> d;

    int totalDist = 0;
    totalDist = (b-a) + (d-c);
    if (a >= c && a <= d && b >= c && b <= d) {
        totalDist -= b-a;
    }
    else if (c >= a && c <= b && d >= a && d <= b) {
        totalDist -= d-c;
    }
    else if(c > a && c < b) {
        totalDist -= b-c;
    } else if (d > a && d < b) {
        totalDist -= d-a;
    }

    fout << totalDist;
    cout << totalDist << endl;

    return 0;
}
