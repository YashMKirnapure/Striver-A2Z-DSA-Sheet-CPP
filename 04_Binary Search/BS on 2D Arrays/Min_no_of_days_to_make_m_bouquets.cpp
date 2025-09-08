#include <bits/stdc++.h>
using namespace std;

int max_ele(vector<int> &bloomDay)
{
    int maxy = INT_MIN;
    int n = bloomDay.size();

    for (int x : bloomDay)
        maxy = max(maxy, x);
    return maxy;
}

bool canMake(vector<int> &bloomDay, int m, int k, int mid)
{
    int bouquets = 0;
    int flowers = 0;
    int n = bloomDay.size();

    for (int i = 0; i < n; i++)
    {
        if (bloomDay[i] <= mid)
        {
            flowers++;
            if (flowers == k)
            {
                bouquets++;
                flowers = 0;
            }
        }
        else
        {
            flowers = 0;
        }
    }
    return bouquets >= m;
}

int minDays(vector<int> &bloomDay, int m, int k)
{
    int n = bloomDay.size();
    long long totalFlowers = 1LL * m * k;

    if (totalFlowers > n)
        return -1;

    int low = 1;
    int high = max_ele(bloomDay);
    int ans = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (canMake(bloomDay, m, k, mid))
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}

/*
-----Logic of canMake-----

Input:

bloomDay[i] = day flower i blooms

m = bouquets required

k = flowers per bouquet

mid = candidate day

Initialize counters:

bouquets = 0 → how many bouquets we’ve made so far

flowers = 0 → current streak of consecutive bloomed flowers

Traverse the array:

If bloomDay[i] <= mid, that flower is bloomed by mid.

Add it to the streak (flowers++).

If streak reaches k, one bouquet is formed:

bouquets++

reset streak (flowers = 0).

If bloomDay[i] > mid, flower hasn’t bloomed → streak is broken (flowers = 0).

At the end, check if bouquets >= m.

true → possible to make m bouquets by day mid.

false → not enough flowers bloomed in sequence.

-----Logic of minDays-----

Constraints check: If m * k > n (total flowers needed > total flowers available), return -1.

The answer (min days) lies between:

low = 1 (earliest possible bloom day)

high = max bloom day (latest possible bloom).

Use binary search:

For a given mid (days), check if we can make at least m bouquets of size k using canMake().

If yes → try smaller days (high = mid - 1).

If no → need more days (low = mid + 1).

Return the smallest mid that works (ans).
*/