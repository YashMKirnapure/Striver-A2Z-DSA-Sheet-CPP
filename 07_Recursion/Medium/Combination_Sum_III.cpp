#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void func(vector<int> &res, vector<vector<int>> &ans, int idx, int sum, vector<int> &temp, int k, int target)
{
    if (sum > target)
        return;

    if (idx >= temp.size())
    {
        if (res.size() == k)
        {
            if (sum == target)
            {
                ans.push_back(res);
                return;
            }
        }
        return;
    }

    // Pick case
    res.push_back(temp[idx]);
    func(res, ans, idx + 1, sum + temp[idx], temp, k, target);

    res.pop_back();
    // Not Pick case
    func(res, ans, idx + 1, sum, temp, k, target);
}

vector<vector<int>> combinationSum3(int k, int target)
{
    vector<int> res;
    vector<vector<int>> ans;
    vector<int> temp(9);

    for (int i = 0; i < temp.size(); i++)
        temp[i] = i + 1;

    int idx = 0;
    int sum = 0;

    func(res, ans, idx, sum, temp, k, target);
    return ans;
}

/*
1. Prepare numbers (1–9):
    Store numbers 1 to 9 in a helper array temp. These are the only candidates allowed.

2. Backtracking function (func):
    At each step, we decide whether to pick or skip the current number at index idx.
      Base Case:
        If idx goes past the last number (i.e., >= 9), check:
        Does res (current subset) contain exactly k numbers?
        Does their sum equal target?
        If yes → push res into the answer list.
        Else → ignore.

      Pick case:
        Add temp[idx] to res, update sum, and recurse to the next index.

    Not Pick case:
        Don’t add the current number, just move to the next index.
    Pruning:
        If at any point sum > target, return immediately (no need to explore further).

3. Result: After recursion finishes, ans contains all valid combinations.
*/