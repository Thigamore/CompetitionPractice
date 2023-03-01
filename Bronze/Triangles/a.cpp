#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

ifstream fin("triangles.in");
ofstream fout("triangles.out");

int area(pair<int,int> triangle[3]) {
    int h = abs(triangle[0].first - triangle[0].first);
    int w = abs(triangle[0].second - triangle[2].second);
    return (h*w)/2;
}

int main() {
    int n; fin >> n;
    pair<int,int> coords[n];
    vector<pair<int,int>[3]> triangles;
    for(int i = 0; i < n; i++) {
        int x; fin >> x;
        int y; fin >> y;
        coords[i] = make_pair(x,y);
    }
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j<n ;j++) {
            if(coords[i].first == coords[j].first) {
                for(int k = 0; k < i; k++) {
                    if(coords[i].second == coords[k].second) {
                        triangles.push_back({coords[i], coords[j], coords[k]});
                    }
                }
                for(int k = i+1; k < n; k++) {
                    if(coords[i].second == coords[k].second) {
                        triangles.push_back({coords[i], coords[j], coords[k]});
                    }
                }
            }
        }
    }
    int biggest = 0;
    int size = triangles.size();
    for(int i = 0; i < size; i++) {
        int triArea = area(triangles[i]);
        if(triArea > biggest) {
            biggest = triArea;
        }
    }
    cout << biggest;
    fout << biggest;
}