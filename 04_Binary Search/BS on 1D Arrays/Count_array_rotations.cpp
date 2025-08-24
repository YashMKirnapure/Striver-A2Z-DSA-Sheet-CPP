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
