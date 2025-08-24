#include <bits/stdc++.h>
using namespace std;

// Method 1
vector<int> majorityElement(vector<int> &nums)
{
    int n = nums.size();
    vector<int> res;
    map<int, int> mp;

    for (int i = 0; i < n; i++)
        mp[nums[i]]++;

    for (auto x : mp)
    {
        if (x.second > n / 3)
            res.push_back(x.first);
    }
    return res;
}

// Method 2
vector<int> majorityElement(vector<int> &nums)
{
    int n = nums.size();
    vector<int> res;
    int cnt1 = 0;
    int cnt2 = 0;
    int el1 = 0;
    int el2 = 0;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] == el1)
            cnt1++;
        else if (nums[i] == el2)
            cnt2++;
        else if (cnt1 == 0)
        {
            cnt1 = 1;
            el1 = nums[i];
        }
        else if (cnt2 == 0)
        {
            cnt2 = 1;
            el2 = nums[i];
        }
        else
        {
            cnt1--;
            cnt2--;
        }
    }

    cnt1 = 0;
    cnt2 = 0;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] == el1)
            cnt1++;
        else if (nums[i] == el2)
            cnt2++;
    }
    if (cnt1 > n / 3)
        res.push_back(el1);
    if (cnt2 > n / 3)
        res.push_back(el2);
    return res;
}