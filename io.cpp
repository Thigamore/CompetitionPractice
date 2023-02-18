#include <fstream>
#include <iostream>

using namespace std;

ofstream fout("a.out");
ifstream fin("a.in");

int main(int argc, char const *argv[])
{
    int integer;
    fin >> integer;
    cout << integer << endl;
    /* code */
    return 0;
}

