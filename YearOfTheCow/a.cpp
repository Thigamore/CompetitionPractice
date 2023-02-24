#include <iostream>
#include <map>
using namespace std;

typedef enum {
    Ox,
    Tiger,
    Rabbit,
    Dragon,
    Snake,
    Horse,
    Goat,
    Monkey,
    Rooster,
    Dog,
    Pig,
    Rat
} Year;

int main() {
    int n; cin >> n;
    map<string, pair<Year, int>> years = {};
    map<string, Year> yearMap = {
        {"Ox", Ox},
        {"Tiger", Tiger},
        {"Dragon", Dragon}, 
        {"Snake", Snake}, 
        {"Horse", Horse},
        {"Goat", Goat},
        {"Monkey", Monkey},
        {"Rooster", Rooster},
        {"Dog", Dog},
        {"Pig", Pig},
        {"Rat", Rat}
    };
    years["Bessie"] = make_pair(Ox, 0);
    for(int i = 0; i < n; i++) {
        string empty;
        string name;
        cin >> name;
        cin >> empty;
        cin >> empty;
        string time;
        cin >> time;
        string yearStr;
        cin >> yearStr;
        Year yearNum = yearMap[yearStr];
        cin >> empty; 
        cin >> empty;
        string prevName;
        cin >> prevName;
        // cout << name << " " << time << " " << yearStr << " " << prevName << endl;
        pair<Year,int> prevCow = years[prevName];
        pair<Year,int> curCow = {yearNum, 0};
        if(time == "previous") {
            // cout << "Prev " << prevCow.first << " " << curCow.first << endl;
            if(prevCow.first < curCow.first) {
                // cout << "first" << endl;
                int dif = (12 - curCow.first) + prevCow.first;
                curCow.second = prevCow.second - dif;
            } else if(prevCow.first > curCow.first) {
                // cout << "second" << endl;
                int dif = prevCow.first - curCow.first;
                curCow.second = prevCow.second - dif;
            } else {
                int dif = 12;
                curCow.second = prevCow.second - dif;
            }
        } else {
            // cout << "Next" << endl;
            if(curCow.first > prevCow.first) {
                int dif = curCow.first - prevCow.first;
                curCow.second = prevCow.second + dif;
            } else if (curCow.first < prevCow.first) {
                int dif = (12-prevCow.first) + curCow.first;
                curCow.second = prevCow.second + dif;
            } else {
                int dif = 12;
                curCow.second = prevCow.second + dif;
            }
        }
        if(name == "Elsie") {
            cout << abs(curCow.second);
            exit(0);
        }
        // cout << "Name: " << name << ", years from Bessie: " << curCow.second << endl;
        years[name] = curCow;
    }
    cout << "No Elsie";
}