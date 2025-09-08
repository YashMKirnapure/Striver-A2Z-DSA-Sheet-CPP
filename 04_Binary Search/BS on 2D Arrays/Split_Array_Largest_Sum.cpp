#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &nums, int k, int mid)
{
    int cnt = 1;
    int sum = 0;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        if (sum + nums[i] > mid)
        {
            sum = nums[i];
            cnt++;
        }
        else
        {
            sum += nums[i];
        }
    }
    return cnt <= k;
}

int splitArray(vector<int> &nums, int k)
{
    int n = nums.size();
    int low = *max_element(nums.begin(), nums.end());
    int high = accumulate(nums.begin(), nums.end(), 0);
    int ans = -1;

    if (k == 1)
        return high;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (isPossible(nums, k, mid))
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
🔹 isPossible(nums, k, mid)

Simulates splitting nums into subarrays where no subarray sum exceeds mid.

Traverse through array:

Add element to current subarray sum.

If it exceeds mid, start a new subarray (cnt++), and reset sum.

Return true if number of subarrays ≤ k (i.e., splitting is possible with mid as max sum).

🔹 splitArray(nums, k)

Search space:

low = max(nums) (because at least one subarray will hold the largest element).

high = sum(nums) (all elements in one subarray).

Binary search:

mid = (low + high)/2.

If isPossible(nums, k, mid) → valid, try smaller max sum (ans = mid, high = mid - 1).

Else → increase limit (low = mid + 1).

Return ans → the minimum possible largest subarray sum when split into k subarrays.
*/