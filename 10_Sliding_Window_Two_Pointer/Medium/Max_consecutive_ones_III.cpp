#include <bits/stdc++.h>
using namespace std;

//M-1
int longestOnes(vector<int> &nums, int k)
{
    int maxy = 0;
    int zeros = 0;
    int n = nums.size();
    int left = 0;
    int right = 0;

    while (right < n)
    {
        if (nums[right] == 0)
            zeros++;
        if (zeros > k)
        {
            if (nums[left] == 0)
                zeros--;
            left++;
        }
        if (zeros <= k)
        {
            int len = right - left + 1;
            maxy = max(maxy, len);
        }
        right++;
    }
    return maxy;
}

//M-2
int longestOnes(vector<int> &nums, int k)
{
    int maxy = 0;
    int zeros = 0;
    int n = nums.size();
    int left = 0;
    int right = 0;

    while (right < n)
    {
        if (nums[right] == 0)
            zeros++;
        while (zeros > k)
        {
            if (nums[left] == 0)
                zeros--;
            left++;
        }
        if (zeros <= k)
        {
            int len = right - left + 1;
            maxy = max(maxy, len);
        }
        right++;
    }
    return maxy;
}