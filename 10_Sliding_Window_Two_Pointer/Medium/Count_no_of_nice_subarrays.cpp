#include <bits/stdc++.h>
using namespace std;

int func(vector<int> &nums, int k)
{
    int n = nums.size();
    int cnt = 0;
    int left = 0;
    int right = 0;
    int sum = 0;

    if (k < 0)
        return 0;

    while (right < n)
    {
        sum = sum + (nums[right] % 2);
        while (sum > k)
        {
            sum = sum - (nums[left] % 2);
            left++;
        }
        cnt = cnt + (right - left + 1);
        right++;
    }
    return cnt;
}

int numberOfSubarrays(vector<int> &nums, int k)
{
    return func(nums, k) - func(nums, k - 1);
}