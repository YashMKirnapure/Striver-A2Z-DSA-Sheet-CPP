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