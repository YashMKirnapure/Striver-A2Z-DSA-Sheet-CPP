#include <bits/stdc++.h>
using namespace std;

int majorityElement_1(vector<int> &nums)
{
    int n = nums.size();
    int maxy = -1;
    int cnt = 0;

    sort(nums.begin(), nums.end());

    return nums[(n / 2)];
}

int majorityElement_2(vector<int> &nums)
{
    int n = nums.size();
    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++)
        mp[nums[i]]++;

    for (auto x : mp)
    {
        if (x.second > n / 2)
            return x.first;
    }
    return 1;
}