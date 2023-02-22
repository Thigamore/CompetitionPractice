#include <iostream>
using namespace std;

int main()
{
    long long nums[7];
    for (int i = 0; i < 7; i++)
    {
        cin >> nums[i];
    }

    long long smallest = 1000000001;
    long long smallPos = 0;
    long long secSmallest = 1000000001;
    long long biggest = nums[0];
    for (int i = 0; i < 7; i++)
    {
        if (nums[i] < smallest)
        {
            smallest = nums[i];
            smallPos = i;
        }
        if( nums[i] > biggest) {
            biggest = nums[i];
        }
    }
    for(int i = 0; i < 7; i++) {
        if(nums[i] < secSmallest && i != smallPos) {
            secSmallest = nums[i];
        }
    }

    cout << smallest << " " << secSmallest << " " << biggest - smallest - secSmallest;
}