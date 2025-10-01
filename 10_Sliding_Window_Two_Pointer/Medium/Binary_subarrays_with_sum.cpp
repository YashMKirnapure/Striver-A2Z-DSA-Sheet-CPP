#include <bits/stdc++.h>
using namespace std;

int func(vector<int> &nums, int goal)
{
    int n = nums.size();
    int sum = 0;
    int cnt = 0;
    int left = 0;
    int right = 0;

    if (goal < 0)
        return 0;

    while (right < n)
    {
        sum = sum + nums[right];

        while (sum > goal)
        {
            sum = sum - nums[left];
            left++;
        }

        cnt += (right - left + 1);
        right++;
    }
    return cnt;
}

int numSubarraysWithSum(vector<int> &nums, int goal)
{
    return func(nums, goal) - func(nums, goal - 1);
}