#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    vector<vector<int>> res;
    int n = nums.size();
    sort(nums.begin(), nums.end());

    for (int p1 = 0; p1 < n - 1; p1++)
    {
        if (p1 > 0 && nums[p1] == nums[p1 - 1])
            continue;
        for (int p2 = p1 + 1; p2 < n; p2++)
        {
            if (p2 != p1 + 1 && nums[p2] == nums[p2 - 1])
                continue;

            int p3 = p2 + 1;
            int p4 = n - 1;

            while (p3 < p4)
            {

                long long sum = nums[p1] + nums[p2];
                sum += nums[p3];
                sum += nums[p4];

                if (sum == target)
                {
                    vector<int> ans = {nums[p1], nums[p2], nums[p3], nums[p4]};
                    res.push_back(ans);
                    p3++;
                    p4--;

                    while (p3 < p4 && nums[p3] == nums[p3 - 1])
                        p3++;
                    while (p3 < p4 && nums[p4] == nums[p4 + 1])
                        p4--;
                }

                else if (sum > target)
                    p4--;

                else
                    p3++;
            }
        }
    }
    return res;
}

/*
🔎 Logic Breakdown

Sort the array
Sorting is crucial for two reasons:

Enables the two-pointer approach.

Makes it easier to skip duplicates and avoid repeated quadruplets.

Fix two numbers (p1 and p2)

Outer loop: pick nums[p1].

Inner loop: pick nums[p2] (just after p1).

You skip duplicates for both p1 and p2.

Two pointers (p3 and p4) for the remaining two numbers

Start with p3 = p2 + 1 and p4 = n - 1.

Compute sum = nums[p1] + nums[p2] + nums[p3] + nums[p4].

Compare with target

If sum == target → store quadruplet.

If sum > target → decrease p4.

If sum < target → increase p3.

Skip duplicates at each step

After finding a valid quadruplet, move p3 and p4 inward while skipping same values.

Complexity

Sorting: O(n log n)

Outer two loops (p1, p2) → O(n²)

Two-pointer scan (p3, p4) → O(n)

Overall: O(n³)

This is the optimal solution for 4Sum.
*/