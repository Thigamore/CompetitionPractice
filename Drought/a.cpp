#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        int cows[n];
        for (int j = 0; j < n; j++)
        {
            cin >> cows[j];
        }
        int moves = 0;

        int biggest = cows[0];
        int biggestPos = 0;
        int secBiggest = -1;
        int secBiggestPos = -1;
        bool same = true;
        for (int j = 1; j < n; j++)
        {
            if (cows[j] != cows[j - 1])
            {
                same = false;
            }
            if (cows[j] > biggest)
            {
                biggest = cows[j];
                biggestPos = j;
            }else if (cows[j] > secBiggest)
            {
                secBiggest = cows[j];
                secBiggestPos = j;
            }
        }
        if (same)
        {
            cout << moves << endl;
            break;
        }

        while (true)
        {
            if (biggest <= secBiggest)
            {
                bool same = true;
                for (int j = 1; j < n; j++)
                {
                    if (cows[j] != cows[j - 1])
                    {
                        same = false;
                    }
                    if (cows[j] > biggest)
                    {
                        biggest = cows[j];
                        biggestPos = j;
                    }
                    if (cows[j] > secBiggest)
                    {
                        secBiggest = cows[j];
                        secBiggest = j;
                    }
                }
                if (same)
                {
                    cout << moves << endl;
                    break;
                }
            }
            if (biggestPos == 0)
            {
                if (cows[1] == 0)
                {
                    cout << -1 << endl;
                    break;
                }
                cows[0]--;
                cows[1]--;
            }
            else if (biggestPos == (n - 1))
            {
                if (cows[n - 2] == 0)
                {
                    cout << -1 << endl;
                    break;
                }
                cows[n - 2]--;
                cows[n - 1]--;
            }
            else
            {
                if (cows[biggestPos - 1] >= cows[biggestPos + 1])
                {
                    if (cows[biggestPos - 1] == 0)
                    {
                        cout << -1 << endl;
                        break;
                    }
                    cows[biggestPos]--;
                    cows[biggestPos - 1]--;
                }
                else
                {
                    cows[biggestPos]--;
                    cows[biggestPos + 1]--;
                }
            }
            moves += 2;
            biggest--;
            // for (int j = 0; j < n; j++)
            // {
            //     cout << cows[j] << ", ";
            // }
            // cout << endl;
            // cout << "Moves: " << moves << ", Biggest: " << biggest << ", second Biggest: " << secBiggest << endl;
        }
    }
}