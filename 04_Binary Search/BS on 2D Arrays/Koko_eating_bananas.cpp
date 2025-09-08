#include <bits/stdc++.h>
using namespace std;

int findMax(vector<int> &piles)
{
    int n = piles.size();
    int maxy = INT_MIN;

    for (int i = 0; i < n; i++)
        maxy = max(maxy, piles[i]);
    return maxy;
}

long long calculateTotalHours(vector<int> &piles, int hourly)
{
    long long total = 0;
    int n = piles.size();
    for (int i = 0; i < n; i++)
    {
        total += ceil((double)(piles[i]) / (double)(hourly));
    }
    return total;
}

int minEatingSpeed(vector<int> &piles, int h)
{
    int low = 1;
    int high = findMax(piles);

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        long long totalHours = calculateTotalHours(piles, mid);
        if (totalHours <= h)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;
}

/*
The minimum speed Koko can eat is 1 banana/hour.

The maximum speed is the largest pile size (if she eats a whole pile in one hour).

Use binary search on this range [1, maxPile]:

Pick a mid-speed mid.

Compute total hours needed if Koko eats at speed mid using ceil(piles[i] / mid).

If hours ≤ h → she can finish faster or at time → try smaller speed (high = mid - 1).

Else → she’s too slow → increase speed (low = mid + 1).

Return low (smallest valid speed).
*/