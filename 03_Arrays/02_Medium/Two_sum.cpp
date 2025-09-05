#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &nums, int k)
{
    int n = nums.size();
    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        if (mp.find(k - nums[i]) != mp.end())
            return {i, mp[k - nums[i]]};
        else
            mp[nums[i]] = i;
    }
    return {0, 0};
}

/*
Logic:

1. Use a hash map for fast lookup - Store each number with its index as we process the array (mp[number] = index).
2. For each element, check for complement - For current element nums[i], calculate what number we need to reach the target: k - nums[i].
3. Search in previously seen numbers - Check if this required complement exists in the hash map.
4. Handle two cases:
If complement is found: We found our pair! Return the current index and the stored index of the complement: {i, mp[k - nums[i]]}
If complement is NOT found: Store the current number and its index in the map for future lookups: mp[nums[i]] = i
5. Default return - Return {0,0} if no valid pair is found (though the problem typically guarantees a solution exists).

Example:
Input: [2,7,11,15] with k = 9
At index 0 (value 2): complement = 7, not found yet, store 2→0
At index 1 (value 7): complement = 2, found at index 0, return {1,0}
Result: {1,0} (indices of values 7 and 2 that sum to 9)

Key insight: By storing numbers as we encounter them, we can find the complement in O(1) time using hash map lookup, making this an efficient O(n) solution with O(n) space.
*/