#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    char cows[n];
    for (int i = 0; i < n; i++)
    {
        cin >> cows[i];
    }
    bool change = true;
    int total = -1;
    int prev = 0;
    while (change)
    {
        total++;
        change = false;
        int odd = 0;
        int even = 0;
        int biggest = 0;
        for (int i = 1; i < n; i += 2)
        {
            if (cows[i] == 'G')
            {
                even++;
            }
            if (cows[i - 1] == 'G')
            {
                odd++;
                if (odd > even)
                {
                    biggest = i;
                    change = true;
                }
            }
        }
        if(prev == biggest) {
            biggest = 0;
            change = false;
        }
        for (int i = 0; i <= (biggest / 2); i++)
        {
            int temp = cows[i];
            cows[i] = cows[biggest - i];
            cows[biggest - i] = temp;
        }
        // cout << biggest << ": ";
        // for (int i = 0; i < n; i++)
        // {
        //     cout << cows[i] << ", ";
        // }
        // cout << endl;
    }
    std::cout << total;

    return 0;
}