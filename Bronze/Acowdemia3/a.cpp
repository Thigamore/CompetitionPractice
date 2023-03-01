#include <iostream>
using namespace std;

int main() {
    int n; cin >> n;
    int m; cin >> m;
    char field[n][m];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> field[i][j];
        }
    }
    int total = 0;
    for(int i = 0; i < 1; i++) {
        for(int j = 0; j < 1; j++) {
            if(field[i][j] != 'G') {
                continue;
            }
            int found = 0;
            if(field[0][1] == 'C') {
                found++;
            }
            if(field[1][0] == 'C') {
                found++;
            }
            if(found >= 2) {
                total++;
            }
        }
        for(int j = 1; j < m-1; j++) {
            if(field[i][j] != 'G') {
                continue;
            }
            int found = 0;
            if(field[0][j-1] == 'C') {
                found++;
            }
            if(field[0][j+1] == 'C') {
                found++;
            }
            if(field[1][j] == 'C') {
                found++;
            }
            if(found >= 2) {
                total++;
            }
        }
        for(int j = m-1; j < m; j++) {
            if(field[i][j] !='G') {
                continue;
            }
            int found = 0;
            if(field[0][m-2] == 'C') {
                found++;
            }
            if(field[1][m-1] == 'C') {
                found++;
            }
            if(found >= 2) {
                total++;
            }
        }
    }
    cout << total << endl;
    for(int i = 1; i < n-1; i++) {
        for(int j = 0; j < 1; j++) {
            if(field[i][j] != 'G') {
                continue;
            }
            int found = 0;
            if(field[i][1] == 'C') {
                found++;
            }
            if(field[i+1][0] == 'C') {
                found++;
            }
            if(field[i-1][0] == 'C') {
                found++;
            }
            if(found >= 2) {
                total++;
            }
        }
        for(int j = 1; j < m-1; j++) {
            if(field[i][j] != 'G') {
                continue;
            }
            int found = 0;
            if(field[i][j-1] == 'C') {
                found++;
            }
            if(field[i][j+1] == 'C') {
                found++;
            }
            if(field[i+1][j] == 'C') {
                found++;
            }
            if(field[i-1][j] == 'C') {
                found++;
            }
            if(found >= 2) {
                total++;
            }
        }
        for(int j = m-1; j < m; j++) {
            if(field[i][j] != 'G') {
                continue;
            }
            int found = 0;
            if(field[i][m-2] == 'C') {
                found++;
            }
            if(field[i+1][m-1] == 'C') {
                found++;
            }
            if(field[i-1][m-1] == 'C') {
                found++;
            }
            if(found >= 2) {
                total++;
            }
        }
        cout << total << endl;
    }
    for(int i = n-1; i < n; i++) {
        for(int j = 0; j < 1; j++) {
            if(field[i][j] != 'G') {
                continue;
            }
            int found = 0;
            if(field[n-1][j+1] == 'C') {
                found++;
            }
            if(field[n-2][j] == 'C') {
                found++;
            }
            if(found >= 2) {
                total++;
            }
        }
        for(int j = 1; j < m-1; j++) {
            if(field[i][j] != 'G') {
                continue;
            }
            int found = 0;
            if(field[n-1][j-1] == 'C') {
                found++;
            }
            if(field[n-1][j+1] == 'C') {
                found++;
            }
            if(field[n-1][j] == 'C') {
                found++;
            }
            if(found >= 2) {
                total++;
            }
        }
        for(int j = m-1; j < m; j++) {
            if(field[i][j] != 'G') {
                continue;
            }
            int found = 0;
            if(field[n-1][m-2] == 'C') {
                found++;
            }
            if(field[n-2][m-1] == 'C') {
                found++;
            }
            if(found >= 2) {
                total++;
            }
        }
    }
    cout << total;
}