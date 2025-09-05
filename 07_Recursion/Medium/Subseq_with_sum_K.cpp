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