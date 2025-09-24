#include <bits/stdc++.h>
using namespace std;

void func(vector<vector<int>> &temp, vector<int> &res, int idx, vector<int> &candidates, int sum, int target, int n)
{
    if (sum > target)
        return;
    if (idx == n)
    {
        if (sum == target)
        {
            temp.push_back(res);
        }
        return;
    }

    // pick
    res.push_back(candidates[idx]);
    func(temp, res, idx, candidates, sum + candidates[idx], target, n);

    res.pop_back();
    
    // not pick
    func(temp, res, idx + 1, candidates, sum, target, n);
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> temp;
    vector<int> res;
    int idx = 0;
    int n = candidates.size();
    int sum = 0;
    func(temp, res, idx, candidates, sum, target, n);
    return temp;
}

/*
1. We try to build combinations step by step from the given candidates array.

2. At every index, we have two choices:
    Pick the current element → add it to res and call the function again without moving to the next index (because elements can be reused).
    Don’t pick the current element → move to the next index without adding anything.

3. Base cases:
If the running sum becomes greater than target, stop (pruning).
If we reach the end (idx == n), check:
    If sum == target, we found a valid combination → add it to the result list.
    Else discard.
*/