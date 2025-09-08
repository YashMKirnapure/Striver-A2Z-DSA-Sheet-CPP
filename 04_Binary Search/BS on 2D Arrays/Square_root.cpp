#include <iostream>
using namespace std;

int floorSqrt(int n)
{
    int low = 0;
    int high = n;
    int ans = 0;

    if (n == 1)
        return 1;

    while (low <= high)
    {
        long long mid = (low + high) / 2;
        long long sq = mid * mid;

        if (sq == n)
            return mid;
        else if (sq > n)
            high = mid-1;
        else
        {
            ans = mid;
            low = mid+1;
        }
    }
    return ans;
}

/*
The square root of n always lies in the range [1, n].

For example, if n = 20, √20 is between 1 and 20.

We do a binary search on this range:

Pick mid = (low + high) / 2.

Compute mid * mid.

Now compare:

If mid * mid == n → mid is the exact square root.

If mid * mid < n → mid is a candidate, but maybe there’s a larger one, so move right (low = mid + 1).

If mid * mid > n → mid is too large, move left (high = mid - 1).
*/