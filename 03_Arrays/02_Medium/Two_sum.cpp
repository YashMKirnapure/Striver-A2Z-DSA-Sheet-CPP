#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    int n = nums.size();
    set<int> st;
    vector<int> res;

    for (int i = 0; i < n; i++)
    {
        if (st.find(target - nums[i]) != st.end())
            st.insert(nums[i]);
        else
            res.push_back(i);
    }
    return res;
}