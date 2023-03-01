#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("teleport.in");
ofstream fout("teleport.out");

int main() {
    int a; fin >> a;
    int b; fin >> b;
    int x; fin >> x;
    int y; fin >> y;
    if(a > b) {
        swap(a,b);
    }
    if(x > y) {
        swap(x,y);
    }
    int without = b - a;
    int before = abs(x-a);
    int after = abs(y-b);
    int total = before + after;
    fout << min(without, total);
}