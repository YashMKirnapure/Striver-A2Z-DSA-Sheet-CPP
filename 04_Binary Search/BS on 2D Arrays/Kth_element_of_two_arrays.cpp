#include <bits/stdc++.h>
using namespace std;

int kthElement(vector<int> &a, vector<int> &b, int k)
{
    int n1 = a.size();
    int n2 = b.size();

    if (n1 > n2)
        return kthElement(b, a, k);

    int low = max(0, k - n2);
    int high = min(k, n1);
    int left = k;

    int n = n1 + n2;

    while (low <= high)
    {
        int mid1 = (low + high) / 2;
        int mid2 = left - mid1;
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;

        if (mid1 < n1)
            r1 = a[mid1];
        if (mid2 < n2)
            r2 = b[mid2];
        if (mid1 - 1 >= 0)
            l1 = a[mid1 - 1];
        if (mid2 - 1 >= 0)
            l2 = b[mid2 - 1];
        if (l1 <= r2 && l2 <= r1)
        {
            return max(l1, l2);
        }
        else if (l1 > r2)
            high = mid1 - 1;
        else
            low = mid1 + 1;
    }
}

int kthElement(vector<int> &a, vector<int> &b, int k)
{
    for (int i = 0; i < b.size(); i++)
        a.push_back(b[i]);
    sort(a.begin(), a.end());
    return a[k - 1];
}

/*
Binary search on the smaller array (a)
If a is bigger, swap arrays to reduce search space.

Partitioning

We want exactly k elements on the left side (from a and b combined).

If mid1 elements are taken from a, then mid2 = k - mid1 must come from b.

Boundaries

l1 = a[mid1 - 1], r1 = a[mid1] → left and right neighbors of the partition in a.

l2 = b[mid2 - 1], r2 = b[mid2] → same for b.

If out of bounds, use INT_MIN/INT_MAX (to avoid edge case crashes).

Check valid partition

if (l1 <= r2 && l2 <= r1)
    return max(l1, l2);

This ensures all elements in the left half ≤ all elements in the right half.

Since we only need the k-th element, the answer is the max of left side.

Adjust search

If l1 > r2 → too many elements taken from a, move high left.

Else → take more from a, move low right.
*/