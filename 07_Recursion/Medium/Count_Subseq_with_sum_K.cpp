#include <bits/stdc++.h>
using namespace std;

int func(vector<int> &arr, int idx, int sum, int target, int n)
{
    if (sum > target)
        return 0;
    if (idx == n)
    {
        if (sum == target)
            return 1;
        else
            return 0;
    }

    int pick = func(arr, idx + 1, sum + arr[idx], target, n);
    int notPick = func(arr, idx + 1, sum, target, n);

    return pick + notPick;
}

int perfectSum(vector<int> &arr, int target)
{
    int n = arr.size();
    int sum = 0;
    int idx = 0;
    return func(arr, idx, sum, target, n);
}

/*
1. We’re asked to count how many subsequences of an array have a sum equal to a target (K).
A subsequence can be formed by either including or excluding each element.

2. The recursive function func explores two choices for each element at index idx:
    Pick the element: Add its value to the current sum.
    Don’t pick the element: Leave the sum unchanged.

3. Base cases:
    If the current sum exceeds the target, stop exploring (pruning).
    If we’ve reached the end of the array (idx == n):
        If the current sum equals the target, count this subsequence as valid → return 1.
        Otherwise, return 0.
        
4.Finally, add up counts from the pick and not pick cases.
*/