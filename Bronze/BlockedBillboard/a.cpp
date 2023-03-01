#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("billboard.in");
ofstream fout("billboard.out");

typedef struct {
    int x;
    int y;
} Coordinate;

int main() {
    Coordinate feedBot;
    Coordinate feedTop;
    Coordinate lawnBot;
    Coordinate lawnTop;
    fin >> lawnBot.x;
    fin >> lawnBot.y;
    fin >> lawnTop.x;
    fin >> lawnTop.y;
    fin >> feedBot.x;
    fin >> feedBot.y;
    fin >> feedTop.x;
    fin >> feedTop.y;
    
    int heightTop = lawnTop.y - feedTop.y;
    int heightBot = feedBot.y - lawnBot.y;
    int widthR = lawnBot.x - feedBot.x;
    int widthL = feedTop.x - lawnTop.x;
    int widthTotal = lawnBot.x - lawnTop.x;
    int heightTotal = lawnTop.y - lawnBot.y;
    

    if(heightTop <= 0 && heightBot <= 0 && widthR <= 0) {
        widthTotal = widthL;
    }else if(heightTop <= 0 && heightBot <= 0 && widthL <= 0) {
        widthTotal = widthR;
    }else if(heightTop <= 0 && widthL <= 0 && widthR <= 0) {
        heightTotal = heightBot;
    }else if(heightBot <= 0 && widthL <= 0 && widthR <= 0) {
        heightTotal = heightTop;
    }
    cout << abs(widthTotal * heightTotal) << endl;

}
