#include <iostream>
using namespace std;

int nthRoot(int n, int m)
{
    int low = 0;
    int high = m;

    if (n == 1)
        return m;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int prod = 1;
        int dummy = n;

        while (n--)
            prod = prod * mid;
        n = dummy;

        if (prod == m)
            return mid;
        else if (prod > m)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

/*
Use binary search in range [1, m].

At each step, compute mid^n.

If mid^n == m → return mid.

If mid^n < m → root lies to the right → low = mid + 1.

If mid^n > m → root lies to the left → high = mid - 1.

If no mid^n == m found → return -1.
*/