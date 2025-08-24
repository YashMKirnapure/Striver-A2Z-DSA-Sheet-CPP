#include <bits/stdc++.h>
using namespace std;

int mostFrequentElement(vector<int> &nums)
{
    int maxy = -1;
    int ans;
    int n = nums.size();
    map<int, int> mp;

    for (int i = 0; i < n; i++)
        mp[nums[i]]++;

    for (auto x : mp)
    {
        if (x.second > maxy)
        {
            maxy = x.second;
            ans = x.first;
        }
    }
    return ans;
}