#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        int j = i + 1;
        int k = n - 1;

        while (j < k)
        {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum < 0)
            {
                j++;
            }
            else if (sum > 0)
            {
                k--;
            }
            else
            {
                vector<int> temp = {nums[i], nums[j], nums[k]};
                res.push_back(temp);
                j++;
                k--;
                while (j < k && nums[j] == nums[j - 1])
                    j++;
                while (j < k && nums[k] == nums[k + 1])
                    k--;
            }
        }
    }
    return res;
}

/*
Sort the array

Sorting helps us skip duplicates easily and allows the two-pointer technique.

Fix one element (nums[i])

For each element, we want to find two other elements (nums[j] and nums[k]) such that:

nums[i] + nums[j] + nums[k] = 0


Use two pointers (j, k)

Start j = i + 1 and k = n - 1.

If the sum is too small (< 0) → move j++ (increase sum).

If the sum is too large (> 0) → move k-- (decrease sum).

If the sum is exactly 0 → store it, then shift both j++ and k--.

Skip duplicates

Avoid repeating triplets by skipping same numbers for both i, j, and k.

Complexity

Sorting: O(n log n)

Two-pointer scan inside the loop: O(n²)

Overall: O(n²), which is optimal for 3Sum.
*/