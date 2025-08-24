#include <iostream>
using namespace std;

int floorSqrt(int n)
{
    int low = 0;
    int high = n;
    int mid = -1;

    if (n == 1)
        return 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int sq = mid * mid;

        if (sq == n)
            return mid;
        else if (low == mid || high == mid)
            return mid;
        else if (sq > n)
            high = mid;
        else
            low = mid;
    }
    return 1;
}