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