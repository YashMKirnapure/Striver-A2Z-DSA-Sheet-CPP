#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int> &nums)
{
    int n = nums.size();
    int miny = INT_MAX;
    int low = 0;
    int high = n - 1;

    while (low < high)
    {
        int mid = (low + high) / 2;

        if (nums[mid] > nums[high])
            low = mid + 1;
        else
            high = mid;
    }
    return nums[low];
}

/*
Logic of findMin:

Start with low = 0, high = n-1.

While low < high:

Compute mid = (low + high) / 2.

If nums[mid] > nums[high]:

The minimum must lie in the right half → low = mid + 1.

Else:

The minimum is in the left half or at mid → high = mid.

When the loop ends, low == high, pointing to the minimum element.

Return nums[low].
*/