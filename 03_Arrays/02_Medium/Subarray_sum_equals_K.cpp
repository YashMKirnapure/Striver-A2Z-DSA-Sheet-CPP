#include <bits/stdc++.h>
using namespace std;

int subarraySum(vector<int> &nums, int k)
{
    int n = nums.size();
    int preSum = 0;
    int cnt = 0;
    unordered_map<int, int> mp;
    mp[0] = 1;

    for (int i = 0; i < n; i++)
    {
        preSum = preSum + nums[i];
        int remove = preSum - k;
        cnt += mp[remove];
        mp[preSum] = mp[preSum] + 1;
    }
    return cnt;
}