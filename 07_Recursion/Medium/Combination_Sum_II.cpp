#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void func(vector<int> &candidates, vector<vector<int>> &ans, vector<int> &res, int idx, int target, int n)
{
    if (target == 0)
    {
        ans.push_back(res);
        return;
    }

    for (int i = idx; i < n; i++)
    {
        if (i > idx && candidates[i] == candidates[i - 1])
            continue;
        if (candidates[i] > target)
            break;
        // Pick condition
        res.push_back(candidates[i]);
        func(candidates, ans, res, i + 1, target - candidates[i], n);

        // Backtrack & remove
        res.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    int n = candidates.size();
    sort(candidates.begin(), candidates.end());
    vector<int> res;
    vector<vector<int>> ans;
    int idx = 0;

    func(candidates, ans, res, idx, target, n);
    return ans;
}

/*
1. Unlike Combination Sum I, each element can only be used once.

2. We loop through the array starting from the current index (i = idx to n).

3. At each step:
    Skip duplicates: If candidates[i] == candidates[i-1] and we are not at the starting index, we continue. This ensures we don’t generate the same combination multiple times.
    Stop early: If candidates[i] > target, no need to continue (array is sorted, so all further numbers will also be too big).
    Pick the current number: push it into res and call recursion with i+1 (move to next index, because reuse is not allowed).
    After recursion, backtrack by removing the last element.

4. Base case: If target == 0, we found a valid combination → add res to ans.

⭐Key differences from Combination Sum I:

No reuse of elements → move to i+1 in recursion.

Duplicates handled → skip equal numbers at the same recursion level.

Sorting helps both with duplicate-skipping and pruning.
*/