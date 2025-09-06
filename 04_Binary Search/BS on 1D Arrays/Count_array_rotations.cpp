#include <bits/stdc++.h>
using namespace std;

int findKRotation(vector<int> &arr)
{
    int low = 0, high = arr.size() - 1;

    while (low <= high)
    {
        // If subarray is already sorted,
        // smallest is at low
        if (arr[low] <= arr[high])
            return low;

        int mid = (low + high) / 2;

        // Minimum is in the right half
        if (arr[mid] > arr[high])
            low = mid + 1;
        // Minimum is in the left half (could be mid)
        else
            high = mid;
    }

    return low;
}

/*
Use binary search with low = 0, high = n-1.

If the current subarray is already sorted (arr[low] <= arr[high]), then the smallest element is at index low.

Since the index of the smallest element = number of rotations, return low.

Otherwise:

Compute mid = (low + high)/2.

If arr[mid] > arr[high] → the minimum lies in the right half → set low = mid + 1.

Else → the minimum lies in the left half (including mid) → set high = mid.

When loop ends, low points to the smallest element.

That index = number of rotations.
*/