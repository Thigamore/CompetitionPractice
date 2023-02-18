#include <iostream>
#include <string>
#include <fstream>

using namespace std;

ofstream fout("traffic.out");
ifstream fin("traffic.in");

int main()
{
    int n;
    fin >> n;
    string ramps[n];
    int rangesIn[n][2];
    int rangesFlow[n][2];
    int low = INT8_MIN;
    int high = INT8_MAX;
    int changes[2] = {0,0};
    for (int i = 0; i < n; i++)
    {
        fin >> ramps[i];
        fin >> rangesIn[i][0];
        fin >> rangesIn[i][1];
        if (ramps[i] == "none")
        {
            if ((rangesIn[i][0] - changes[0]) > low)
            {
                low = rangesIn[i][0] - changes[0];
            }
            if ((rangesIn[i][1] - changes[1]) < high)
            {
                high = rangesIn[i][1] - changes[1];
            }
        } else if(ramps[i] == "on") {
            changes[0] += rangesIn[i][0];
            changes[1] += rangesIn[i][1];
        } else if(ramps[i] == "off") {
            changes[0] -= rangesIn[i][1];
            changes[1] -= rangesIn[i][0];
        }
        cout <<"Low: " << low << " " << "High: " << high << endl;
        cout << "Change Low: " << changes[0] << "; Change High: " << changes[1] << endl << endl;
    }
    cout << low << " " << high <<endl;
    cout << low + changes[0] << " " << high + changes[1];
    fout << low << " " << high <<endl;
    fout << low + changes[0] << " " << high + changes[1];
    
}