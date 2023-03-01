#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("tttt.in");
ofstream fout("tttt.out");

int main()
{
    char board[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            fin >> board[i][j];
        }
    }
    int sinWins = 0;
    int doubWins = 0;
    // horizontals
    for (int i = 0; i < 3; i++)
    {
        int names[26] = {};
        int totalNames = 0;
        for (int j = 0; j < 3; j++)
        {
            if (names[((int)board[i][j]) - 65] == 0)
            {
                totalNames += 1;
                names[((int)board[i][j]) - 65] = 1;
            }
        }

        if (totalNames == 1)
        {
            sinWins++;
        }
        else if (totalNames == 2)
        {
            doubWins++;
        }
    }
    // verticals
    for (int i = 0; i < 3; i++)
    {
        int names[26] = {};
        int totalNames = 0;
        for (int j = 0; j < 3; j++)
        {
            if (names[((int)board[j][i]) - 65] == 0)
            {
                totalNames += 1;
                names[((int)board[j][i]) - 65] = 1;
            }
        }
        if (totalNames == 1)
        {
            sinWins++;
        }
        else if (totalNames == 2)
        {
            doubWins++;
        }
    }
    // Diagonal 0,5,9
    int names[26] = {};
    int totalNames = 1;
    names[(int)board[0][0] - 65] = 1;
    if (names[(int)board[1][1] - 65] == 0)
    {
        totalNames += 1;
        names[(int)board[1][1] - 65] = 1;
    }
    if (names[(int)board[2][2] - 65] == 0)
    {
        totalNames += 1;
        names[(int)board[2][2] - 65] = 1;
    }
    if (totalNames == 1)
    {
        sinWins++;
    }
    else if (totalNames == 2)
    {
        doubWins++;
    }
    // Diagonal 2,5,7
    int names2[26] = {};
    totalNames = 1;
    names2[(int)board[0][2] - 65] = 1;
    if (names2[(int)board[1][1] - 65] == 0)
    {
        totalNames += 1;
        names2[(int)board[1][1] - 65] = 1;
    }
    if (names2[(int)board[2][0] - 65] == 0)
    {
        totalNames += 1;
        names2[(int)board[2][0] - 65] = 1;
    }
    if (totalNames == 1)
    {
        sinWins++;
    }
    else if (totalNames == 2)
    {
        doubWins++;
    }
    fout << sinWins << endl
         << doubWins;
}