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