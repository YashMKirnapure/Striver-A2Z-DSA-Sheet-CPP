#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> &nums, int count, int i, int dir)
{
    int idx = i;
    vector<int> temp = nums;

    while (idx >= 0 && idx < temp.size() && count > 0)
    {
        if (temp[idx] > 0)
        {
            temp[idx]--;
            dir *= -1;
            if (temp[idx] == 0)
                count--;
        }
        idx += dir;
    }
    return count == 0;
}

int countValidSelections(vector<int> &nums)
{
    int n = nums.size();
    int res = 0;
    int count = 0; // count of nums[i] != 0

    for (int i = 0; i < n; i++)
    {
        if (nums[i] != 0)
            count++;
    }

    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 0)
        {
            if (check(nums, count, i, -1))
                res++;
            if (check(nums, count, i, 1))
                res++;
        }
    }
    return res;
}

// Optimal
int countValidSelections(vector<int> &nums)
{
    int n = nums.size();
    int total = 0;

    for (int i = 0; i < n; i++)
        total += nums[i];

    int cursum = 0;
    int res = 0;

    for (int i = 0; i < n; i++)
    {
        cursum += nums[i];
        if (nums[i] == 0)
        {
            int left = cursum;
            int right = total - cursum;
            if (left == right)
                res += 2;
            else if (abs(left - right) == 1)
                res += 1;
        }
    }
    return res;
}