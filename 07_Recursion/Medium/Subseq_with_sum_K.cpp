#include <bits/stdc++.h>
using namespace std;

bool func(int idx, vector<int> &arr, int sum, int k, int n)
{
    if (sum > k)
        return false;
    if (idx == n)
    {
        if (sum == k)
            return true;
        else
            return false;
    }

    // pick condition
    bool pick = func(idx + 1, arr, sum + arr[idx], k, n);

    // not pick condition
    bool notPick = func(idx + 1, arr, sum, k, n);

    return pick || notPick;
}

bool checkSubsequenceSum(int n, vector<int> &arr, int k)
{
    int idx = 0;
    int sum = 0;
    return func(idx, arr, sum, k, n);
}

/*
1. Start from index 0 with sum = 0.

2. For each element at position idx, you have two choices:
    Pick it → add arr[idx] to sum and move to the next index.
    Don’t pick it → keep sum as is and move to the next index.

3. Base cases:
    If sum > k, stop and return false (pruning).
    If we’ve checked all elements (idx == n):
        Return true if sum == k.
        Else return false.

4. Final result is true if either the pick path or the not-pick path leads to a subsequence with sum k.    
*/