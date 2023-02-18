#include <iostream>
#include <fstream>
#include <array>

using namespace std;

ifstream fin("mowing.in");
ofstream fout("mowing.out");

int main()
{
    int n;
    fin >> n;
    int *field = new int[n*100+1][n*100+1];
    cout << sizeof(field) / sizeof(int) << endl;
    int pos[2] = {0, 0};
    field[0][0] = 0;
    int time = 1;
    int regrow = 2147483646;
    for (int i = 0; i < n; i++)
    {
        char dir;
        fin >> dir;
        int dist;
        fin >> dist;
        if (dir == 'N')
        {
            for (int j = 0; j < dist; j++)
            {
                if (field[(pos[0] + j) % (sizeof(field) / sizeof(field[0]))][pos[1]] != 0)
                {
                    if (!(time == 1))
                    {
                        int dif = time - field[(pos[0] + j) % (sizeof(field) / sizeof(field[0]))][pos[1]];
                        cout << "Dif: " << dif << endl;
                        if (regrow > dif)
                        {
                            regrow = dif;
                        }
                    }
                }
                field[(pos[0] + j) % (sizeof(field) / sizeof(field[0]))][pos[1]] = time;
                time++;
            }
            cout << (pos[0] + dist) % sizeof(field) / sizeof(field[0]);
            pos[0] = (pos[0] + dist) % (sizeof(field) / sizeof(field[0]));
        }
        else if (dir == 'S')
        {
            for (int j = 0; j < dist; j++)
            {
                if (field[(pos[0] - j) % (sizeof(field) / sizeof(field[0]))][pos[1]] != 0)
                {
                    int dif = time - field[(pos[0] - j) % (sizeof(field) / sizeof(field[0]))][pos[1]];
                    if (regrow > dif)
                    {
                        regrow = dif;
                    }
                }
                field[(pos[0] - j) % (sizeof(field) / sizeof(field[0]))][pos[1]] = time;
                time++;
            }
            pos[0] = (pos[0] - dist) % (sizeof(field) / sizeof(field[0]));
            cout << "S: " << pos[0] << " " << pos[1] << endl;
        }
        else if (dir == 'E')
        {
            for (int j = 0; j < dist; j++)
            {
                if (field[pos[0]][(pos[1] + j) % (sizeof(field) / sizeof(field[0]))] != 0)
                {
                    int dif = time - field[pos[0]][(pos[1] + j) % (sizeof(field) / sizeof(field[0]))];
                    if (regrow > dif)
                    {
                        regrow = dif;
                    }
                }
                field[pos[0]][(pos[1] + j) % (sizeof(field) / sizeof(field[0]))] = time;
                time++;
            }
            pos[1] = (pos[1] + dist) % (sizeof(field) / sizeof(field[0]));
            cout << "E: " << pos[0] << " " << pos[1] << endl;
        }
        else
        {
            // West
            for (int j = 0; j < dist; j++)
            {
                if (field[pos[0]][(pos[1] - j) % (sizeof(field) / sizeof(field[0]))] != 0)
                {
                    int dif = time - field[pos[0]][(pos[1] - j) % (sizeof(field) / sizeof(field[0]))];
                    if (regrow > dif)
                    {
                        regrow = dif;
                    }
                }
                field[pos[0]][(pos[1] - j) % (sizeof(field) / sizeof(field[0]))] = time;
                time++;
            }
            pos[1] = (pos[1] - dist) % (sizeof(field) / sizeof(field[0]));
            cout << "W: " << pos[0] << " " << pos[1] << endl;
        }
        cout << regrow << endl
             << endl;
    }
    if (regrow == 2147483646)
    {
        fout << -1;
    }
    else
    {
        fout << regrow;
    }
}