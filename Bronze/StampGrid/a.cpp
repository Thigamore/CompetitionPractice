#include <iostream>
using namespace std;

int main()
{
    // int k = 4;
    // char stamp[k][k] = {{'.','.','.','*'}, {'*','.','*','.'}, {'.','*','.','*'}, {'.','*','.','.'}};
    // // 0
    // for(int y1 = 0; y1 < k; y1++) {
    //     for(int x1 = 0; x1 < k; x1++) {
    //         cout << stamp[y1][x1] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    // //90
    // for(int y1 = 0; y1 < k; y1++) {
    //     for(int x1 = 0; x1 < k; x1++) {
    //         cout << stamp[x1][k-y1-1] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    // //180
    // for(int y1 = 0; y1 < k; y1++) {
    //     for(int x1 = 0; x1 < k; x1++) {
    //         cout << stamp[k-y1-1][k-x1-1] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    // //270
    // for(int y1 = 0; y1 < k; y1++) {
    //     for(int x1 = 0; x1 < k; x1++) {
    //         cout << stamp[k-x1-1][y1] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        char canvas[n][n];
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                cin >> canvas[j][k];
            }
        }
        int k;
        cin >> k;
        char stamp[k][k];
        for (int j = 0; j < k; j++)
        {
            for (int l = 0; l < k; l++)
            {
                cin >> stamp[j][l];
            }
        }
        bool covered[n][n] = {};
        for (int y = 0; y <= n - k; y++)
        {
            for (int x = 0; x <= n - k; x++)
            {
                // rotate 0
                bool good = true;
                for (int y1 = 0; y1 < k; y1++)
                {
                    for (int x1 = 0; x1 < k; x1++)
                    {
                        if (canvas[y + y1][x + x1] != stamp[y1][x1] && stamp[y1][x1] != '.')
                        {
                            good = false;
                            break;
                        } 
                    }
                    if (!good)
                    {
                        break;
                    }
                }
                if (good)
                {
                    for (int y1 = 0; y1 < k; y1++)
                    {
                        for (int x1 = 0; x1 < k; x1++)
                        {
                            if (canvas[y + y1][x + x1] == '*' && stamp[y1][x1] == '*')
                            {
                                covered[y + y1][x + x1] = true;
                            }
                        }
                    }
                }
                // cout << "0" << endl;
                // for(int y = 0; y < n; y++) {
                //     for(int x = 0; x < n; x++) {
                //         cout << covered[y][x] << " ";
                //     }
                //     cout << endl;
                // }
                // cout << endl;
                // rotate 90
                good = true;
                for (int y1 = 0; y1 < k; y1++)
                {
                    for (int x1 = 0; x1 < k; x1++)
                    {
                        if (canvas[y + y1][x + x1] != stamp[k-x1-1][y1] && stamp[k-x1-1][y1] != '.')
                        {
                            good = false;
                            break;
                        }
                    }
                    if (!good)
                    {
                        break;
                    }
                }
                if (good)
                {
                    for (int y1 = 0; y1 < k; y1++)
                    {
                        for (int x1 = 0; x1 < k; x1++)
                        {
                            if (canvas[y + y1][x + x1] == '*'&& stamp[k-x1-1][y1] == '*')
                            {
                                covered[y + y1][x + x1] = true;
                            }
                        }
                    }
                }
                // cout << "90" << endl;
                // for(int y = 0; y < n; y++) {
                //     for(int x = 0; x < n; x++) {
                //         cout << covered[y][x] << " ";
                //     }
                //     cout << endl;
                // }
                // cout << endl;
                // rotate 180
                good = true;
                for (int y1 = 0; y1 < k; y1++)
                {
                    for (int x1 = 0; x1 < k; x1++)
                    {
                        if (canvas[y + y1][x + x1] != stamp[k-y1-1][k-x1-1] && stamp[k-y1-1][k-x1-1] != '.')
                        {
                            good = false;
                            break;
                        }
                    }
                    if (!good)
                    {
                        break;
                    }
                }
                if (good)
                {
                    for (int y1 = 0; y1 < k; y1++)
                    {
                        for (int x1 = 0; x1 < k; x1++)
                        {
                            if (canvas[y + y1][x + x1] == '*' && stamp[k-y1-1][k-x1-1] == '*')
                            {
                                covered[y + y1][x + x1] = true;
                            }
                        }
                    }
                }
                // cout << "180" << endl;
                // for(int y = 0; y < n; y++) {
                //     for(int x = 0; x < n; x++) {
                //         cout << covered[y][x] << " ";
                //     }
                //     cout << endl;
                // }
                // cout << endl;
                // rotate 270
                good = true;
                for (int y1 = 0; y1 < k; y1++)
                {
                    for (int x1 = 0; x1 < k; x1++)
                    {
                        if (canvas[y + y1][x + x1] != stamp[x1][k-y1-1] && stamp[x1][k-y1-1] != '.')
                        {
                            good = false;
                            break;
                        }
                    }
                    if (!good)
                    {
                        break;
                    }
                }
                if (good)
                {
                    for (int y1 = 0; y1 < k; y1++)
                    {
                        for (int x1 = 0; x1 < k; x1++)
                        {
                            if (canvas[y + y1][x + x1] == '*' && stamp[x1][k-y1-1] == '*')
                            {
                                covered[y + y1][x + x1] = true;
                            }
                        }
                    }
                }
                // cout << "270" << endl;
                // for(int y = 0; y < n; y++) {
                //     for(int x = 0; x < n; x++) {
                //         cout << covered[y][x] << " ";
                //     }
                //     cout << endl;
                // }
                // cout << endl;
            }
        }
        bool good = true;
        for (int y = 0; y < n; y++)
        {
            for (int x = 0; x < n; x++)
            {
                if (canvas[y][x] == '*' && covered[y][x] == false)
                {
                    cout << "NO" << endl;
                    // cout << "--------------------" << endl;
                    good = false;
                    break;
                }
            }
            if (!good)
            {
                break;
            }
        }
        if (good)
        {
            cout << "YES" << endl;
            // cout << "--------------------" << endl;
        }
    }
}