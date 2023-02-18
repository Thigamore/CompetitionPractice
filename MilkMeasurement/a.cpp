#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ifstream fin("measurement.in");
ofstream fout("measurement.out");

void swapArr(int arr[][3], int pos1, int pos2) {
    int temp[3];
    for(int i = 0; i < 3; i++) {
        temp[i] = arr[pos1][i];
    }
    for(int i = 0; i < 3; i++) {
        arr[pos1][i] = arr[pos2][i];
    }
    for(int i = 0; i < 3; i++) {
        arr[pos2][i] = temp[i];
    }
}
void sortArr(int arr[][3], int len) {
    bool changes = true;
    while(changes) {
        changes = false;
        for(int i = 1; i < len; i++ ) {
            if(arr[i-1][0] > arr[i][0]) {
                swapArr(arr, i-1, i);
                changes = true;
            } 
        }
    }
}

void printArr(int arr[][3], int len) {
    cout <<sizeof(arr) << endl;
    for(int i = 0; i < len; i++) {
        cout << i << ": " << arr[i][0] << " " << arr[i][1] << " " << arr[i][2] << endl;
    }
    cout << "End" << endl;
}

int main() {
    int n; fin >> n;
    //Bessie, Elsie, Mildred
    int cowTotal[3] = {7,7,7};
    bool isHighest[3] = {true, true, true};
    
    int highestNum = 7;
    int changes [n][3] = {};
    int totalChanges = 0;
    for(int i = 0; i < n; i++) {
        fin >> changes[i][0];
        string temp;
        fin >> temp;
        if(temp == "Bessie") {
            changes[i][1] = 0;
        } else if (temp == "Elsie") {
            changes[i][1] = 1;
        } else {
            changes[i][1] = 2;
        }
        fin >> changes[i][2];
    }
    sortArr(changes,n);
    int len = sizeof(changes) / sizeof(changes[0]);
    for(int i = 0; i < len; i++) {
        cowTotal[changes[i][1]] += changes[i][2];
        int tempHigh = 0;
        bool tempHighest[3] = {false, false, false};
        bool isChanges = false;
        for(int j = 0; j < 3; j++) {
            if(cowTotal[j] > tempHigh) {
                tempHigh = cowTotal[j];
                for(int k = 0; k < j; k++) {
                    tempHighest[k] = false;
                }
                for(int k = j+1; k < 3; k++) {
                    tempHighest[k] = false;
                }
                tempHighest[j] = true;
            }else if(cowTotal[j] == tempHigh) {
                tempHighest[j] = true;
            }
        }
        for(int j = 0; j < 3; j++) {
            if(tempHighest[j] != isHighest[j]) {
                isChanges = true;
            }
            isHighest[j] = tempHighest[j];
        }
        if(isChanges) {
            totalChanges++;
        }
    }
    fout << totalChanges;
}


