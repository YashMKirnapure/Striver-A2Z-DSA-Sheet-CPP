#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void func(vector<vector<int>> &ans, vector<int> &res, int idx, vector<int> &nums, int n)
{
    ans.push_back(res);

    for (int i = idx; i < n; i++)
    {
        if (i > idx && nums[i] == nums[i - 1])
            continue;

        res.push_back(nums[i]);
        func(ans, res, i + 1, nums, n);
        res.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    int n = nums.size();
    int idx = 0;
    vector<int> res;
    vector<vector<int>> ans;

    sort(nums.begin(), nums.end());

    func(ans, res, idx, nums, n);
    return ans;
}

/*
1. First, sort the array so that duplicates come next to each other.
(This makes it easier to skip repeating subsets).

2. Start with an empty subset res = {} and push it into ans (because the empty subset is always valid).

3. At each index i, loop through the elements from idx to n-1:
    If the current number is the same as the previous one (nums[i] == nums[i-1]) and we’re not at the very first pick in this level (i > idx), then skip it.
    This prevents duplicate subsets.
    
    Otherwise, pick the number, add it to the current subset res, and recurse forward (i+1).
    
    After recursion, backtrack (remove the last element) to explore the "not pick" option.

4. Keep repeating until you’ve explored all combinations.
*/