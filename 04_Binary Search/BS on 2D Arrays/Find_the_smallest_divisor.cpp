#include <bits/stdc++.h>
using namespace std;

int max_ele(vector<int> &nums)
{
    int maxy = INT_MIN;

    for (int x : nums)
        maxy = max(maxy, x);
    return maxy;
}

bool func(vector<int> &nums, int threshold, int mid)
{
    int n = nums.size();
    int sum = 0;

    for (int i = 0; i < n; i++)
        sum = sum + (nums[i] + mid - 1) / mid;
    return sum <= threshold;
}

int smallestDivisor(vector<int> &nums, int threshold)
{
    int n = nums.size();
    int low = 1;
    int high = max_ele(nums);
    int ans = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (func(nums, threshold, mid) == true)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

/*
func(nums, threshold, mid)

Treat mid as the divisor.

For each nums[i], compute ceil(nums[i] / mid) → done as (nums[i] + mid - 1) / mid (clever integer math).

Add them all up = sum.

If sum <= threshold, return true (divisor is valid).

smallestDivisor(nums, threshold)

The divisor must be between 1 and max(nums).

1 → biggest possible sum.

max(nums) → smallest possible sum.

Use binary search in this range:

Pick mid as candidate divisor.

If func(mid) returns true → this divisor works, but maybe there’s a smaller one → search left (high = mid - 1).

Else → too small (sum > threshold) → need a larger divisor → search right (low = mid + 1).

Return the smallest valid divisor (ans).
*/