#include <iostream>
#include <vector>
using namespace std;

void func(vector<int> &nums, int idx, vector<vector<int>> &ans, vector<int> &res)
{
    if (idx == nums.size())
    {
        ans.push_back(res);
        return;
    }
    res.push_back(nums[idx]);
    func(nums, idx + 1, ans, res);
    res.pop_back();
    func(nums, idx + 1, ans, res);
}

vector<vector<int>> subsets(vector<int> &nums)
{
    vector<int> res;
    vector<vector<int>> ans;
    int idx = 0;
    func(nums, idx, ans, res);
    return ans;
}

/*
1. Start with an index pointing to the first element of the array.
At every index, we have two choices:
    Include the current element in our subset.
    Exclude the current element and move on.

2. Each time we include the element, we add it to our temporary list (res), move to the next index, and continue.
After exploring that path, we backtrack (remove the last element) and explore the "exclude" path.

3. When the index reaches the end of the array, that means we’ve made a complete choice (either included or excluded every element). At this point, we save the current subset in the answer list.

4. This way, recursion explores all combinations step by step.
*/