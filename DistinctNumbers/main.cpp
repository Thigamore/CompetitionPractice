#include <fstream>
#include <iostream>
#include <map>

using namespace std;

ofstream fout("distinct.out");
ifstream fin("distinct.in");

int main()
{
    map<int, bool> m;
    int in;
    while(fin.peek() != EOF) {
        fin >> in;
        m[in] = true;
    }
    cout << m.size() << endl;
}
