#include <bits/stdc++.h>
using namespace std;

int findPeakElement(vector<int> &nums)
{
    int n = nums.size();
    int low = 0;
    int high = n - 1;

    if (n == 1)
        return 0;

    if (nums[0] > nums[1])
        return 0;

    if (nums[n - 1] > nums[n - 2])
        return n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
            return mid;
        if (nums[mid] > nums[mid + 1])
            high = mid;
        else
            low = mid+1;
    }
    return low;
}

/*
Handle edge cases:

If there’s only one element → that’s the peak (return 0).

If the first element is greater than the second → return 0.

If the last element is greater than the second last → return n-1.

Otherwise, do binary search:

Compute mid.

If nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1] → peak found, return mid.

Else if nums[mid] > nums[mid+1] → peak must be on the left side → move high = mid.

Else → peak must be on the right side → move low = mid+1.
*/