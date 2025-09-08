#include <bits/stdc++.h>
using namespace std;

bool canPlace(vector<int> &stalls, int k, int dist)
{
    int cntCows = 1;
    int last = stalls[0];
    int n = stalls.size();

    for (int i = 1; i < n; i++)
    {
        if (stalls[i] - last >= dist)
        {
            cntCows++;
            last = stalls[i];
        }
    }
    return cntCows >= k;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    int n = stalls.size();
    int ans = -1;

    sort(stalls.begin(), stalls.end());

    int low = 0;
    int high = (stalls[n - 1] - stalls[0]);

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (canPlace(stalls, k, mid))
        {
            ans = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return ans;
}

/*
🔹canPlace(stalls, k, dist)

Place the first cow at stalls[0].

Greedily try placing the next cows at the earliest stall possible such that the distance from the last placed cow is at least dist.

Count how many cows can be placed.

If cntCows >= k → possible to place all cows with dist apart.

🔹aggressiveCows(stalls, k)

Sort the stall positions (important for greedy placement).

Define search space for answer:

low = 0 (minimum distance).

high = stalls[n-1] - stalls[0] (maximum possible distance).

Binary Search:

Pick mid = (low+high)/2.

If canPlace(stalls, k, mid) → we can place cows → try for a bigger distance (ans = mid, low = mid+1).

Else → distance too large, reduce (high = mid-1).

Return ans = largest minimum distance possible.
*/