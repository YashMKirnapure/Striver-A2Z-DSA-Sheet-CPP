#include <bits/stdc++.h>
using namespace std;

int maxLength(vector<int> &arr)
{
    int n = arr.size();
    unordered_map<int, int> mp;
    int sum = 0;
    int maxLen = 0;

    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
        if (sum == 0)
            maxLen = i + 1;
        if (mp.find(sum) != mp.end())
            maxLen = max(maxLen, i - mp[sum]);
        else
            mp[sum] = i;
    }
    return maxLen;
}

/*
sum → keeps track of prefix sum.

mp → stores the first index where a particular sum occurs.

If sum == 0 at index i, then [0..i] is a zero-sum subarray.

If the same sum occurs again at index i, then the subarray between (mp[sum] + 1 .. i) has sum zero.

Keep updating maxLen accordingly.
*/