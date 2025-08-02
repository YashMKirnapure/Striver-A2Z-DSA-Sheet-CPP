#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> countFrequencies(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> res;
    map<int, int> mp;

    for (int i = 0; i < n; i++)
        mp[nums[i]]++;

    for (auto x : mp)
        res.push_back({x.first, x.second});

    return res;
}