#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <array>

using namespace std;

ifstream fin("rut.in");

enum Direction
{
    east,
    north
};

void printVec(vector<array<int, 3>> vec)
{
    for (auto ptr = vec.begin(); ptr != vec.end(); ++ptr)
    {
        cout << (*ptr)[0] << ":" << (*ptr)[1] << ":" << (*ptr)[2] << endl;
    }
}

void sortVecN(vector<array<int, 3>> *vec)
{
    bool isChange = true;
    int len = vec->size();
    while (isChange)
    {
        isChange = false;
        for (int i = 1; i < len; i++)
        {
            if (vec->at(i - 1)[0] > vec->at(i)[0])
            {
                swap(vec->at(i - 1), vec->at(i));
                isChange = true;
            }
        }
    }
}

void sortVecE(vector<array<int, 3>> *vec)
{
    bool isChange = true;
    int len = vec->size();
    while (isChange)
    {
        isChange = false;
        for (int i = 1; i < len; i++)
        {
            if (vec->at(i - 1)[1] > vec->at(i)[1])
            {
                swap(vec->at(i - 1), vec->at(i));
                isChange = true;
            }
        }
    }
}

void printArr(string arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << endl;
    }
}

int main()
{
    int n;
    fin >> n;
    vector<array<int, 3>> cowN;
    vector<array<int, 3>> cowE;
    for (int i = 0; i < n; i++)
    {
        char temp;
        fin >> temp;
        array<int, 3> tempPos;
        fin >> tempPos[0];
        fin >> tempPos[1];
        tempPos[2] = i;
        if (temp == 'E')
        {
            cowE.push_back(tempPos);
        }
        else
        {
            cowN.push_back(tempPos);
        }
    }
    sortVecN(&cowN);
    sortVecE(&cowE);

    cout << "North" << endl;
    printVec(cowN);
    cout << "East" << endl;
    printVec(cowE);

    string cowOut[n] = {};
    // north cows
    for (int i = 0; i < cowN.size(); i++)
    {
        int j = 0;
        while (cowE[j][1] <= cowN[i][1])
        {
            j++;
        }
        while (j < cowE.size())
        {
            if (cowE[j][0] < cowN[i][0])
            {
                int time = cowN[i][0] - cowE[j][0];
                if ((cowN[i][1] + time) < cowE[j][1])
                {
                    cowOut[cowN[i][2]] = to_string(cowE[j][1] - cowN[i][1]);
                    break;
                }
            }
            j++;
        }
        if (cowOut[cowN[i][2]] == "")
        {
            cowOut[cowN[i][2]] = "Infinity";
        }
    }

    cout <<endl << "East" << endl;
    //East
    for (int i = 0; i < cowE.size(); i++)
    {
        cout << endl << "I: " << i << endl;
        int j = 0;
        while (cowE[i][0] <= cowN[j][0])
        {
            j++;
        }
        while (j < cowN.size())
        {
            if (cowN[j][1] < cowE[i][1])
            {
                cout << "J: " << j << endl;
                int time = cowN[j][1] - cowE[i][1];
                cout << "time: " << time << endl;
                if ((cowE[i][0] + time) < cowN[j][0])
                {
                    cout << i << ":" << j << endl;
                    cowOut[cowE[i][2]] = to_string(cowN[j][0] - cowE[i][0]);
                    break;
                }
            }
            j++;
            cout << endl;
        }
        if (cowOut[cowE[i][2]] == "")
        {
            cowOut[cowE[i][2]] = "Infinity";
        }
    }
    printArr(cowOut, n);
}

//  get input
//  put cows in their direction
//  sort directions
//  for each cow:
//      look at cows more north/east
//      start from most west/south cow
//      if they reach a point before the cow:
//          cow eats x grass between point and cow
//      if no cow blocks them, infinity