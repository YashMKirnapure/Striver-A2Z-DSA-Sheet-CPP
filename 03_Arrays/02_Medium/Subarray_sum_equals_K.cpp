#include <bits/stdc++.h>
using namespace std;

int subarraySum(vector<int> &nums, int k)
{
    int n = nums.size();
    int preSum = 0;
    int cnt = 0;
    unordered_map<int, int> mp;
    mp[0] = 1;

    for (int i = 0; i < n; i++)
    {
        preSum = preSum + nums[i];
        int remove = preSum - k;
        cnt += mp[remove];
        mp[preSum] = mp[preSum] + 1;
    }
    return cnt;
}

/*
Step-by-step explanation:

Keep a running prefix sum

preSum stores the sum of elements from the start up to the current index.

Use a hashmap (mp) to store frequencies of prefix sums

mp[sum] = how many times this prefix sum has occurred so far.

Initialize with mp[0] = 1 (base case: empty prefix, so if a subarray itself equals k, it gets counted).

Iterate through the array
For each element nums[i]:

Update running sum: preSum += nums[i].

Calculate: remove = preSum - k.

Why? If there exists an earlier prefix sum equal to remove, then the subarray between that point and current index has sum k.

Example: if preSum = 12 and k = 5, we check if 12 - 5 = 7 appeared before.
If yes → subarray sum = k.

Add the count of such occurrences: cnt += mp[remove].

Record the current prefix sum: mp[preSum]++.

Return result

After scanning the array, cnt holds the number of subarrays with sum k.

Example Walkthrough:

nums = [1, 2, 3], k = 3

Start: preSum = 0, mp = {0: 1}, cnt = 0.

i = 0, num = 1 → preSum = 1
remove = -2 → not in map.
cnt = 0, update mp = {0:1, 1:1}.

i = 1, num = 2 → preSum = 3
remove = 0 → found mp[0] = 1.
cnt = 1, update mp = {0:1, 1:1, 3:1}.

i = 2, num = 3 → preSum = 6
remove = 3 → found mp[3] = 1.
cnt = 2, update mp = {0:1, 1:1, 3:1, 6:1}.

Answer = 2 ([1,2], [3]).
*/