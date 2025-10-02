#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int func(vector<int> &nums, int k)
{
    int n = nums.size();
    int left = 0;
    int right = 0;
    int cnt = 0;
    unordered_map<int, int> mp;

    if (k < 0)
        return 0;

    while (right < n)
    {
        mp[nums[right]]++;
        while (mp.size() > k)
        {
            mp[nums[left]]--;
            if (mp[nums[left]] == 0)
                mp.erase(nums[left]);
            left++;
        }
        cnt = cnt + (right - left);
        right++;
    }
    return cnt;
}

int subarraysWithKDistinct(vector<int> &nums, int k)
{
    return func(nums, k) - func(nums, k - 1);
}