#include <bits/stdc++.h>
using namespace std;

    int min_ele(vector<int>& nums) 
    {
        int miny = INT_MAX;

        for (int x : nums)
            miny = min(miny, x);
        return miny;
    }

    int max_ele(vector<int>& nums) 
    {
        int maxy = INT_MIN;

        for (int x : nums)
            maxy = max(maxy, x);
        return maxy;
    }

    bool func(vector<int>& nums, int threshold, int mid) 
    {
        int n = nums.size();
        int sum = 0;

        for (int i = 0; i < n; i++) 
            sum = sum + (nums[i] + mid - 1) /mid;
        return sum <= threshold;
    }

    int smallestDivisor(vector<int>& nums, int threshold) 
    {
        int n = nums.size();
        int low = 1;
        int high = max_ele(nums);
        int ans = -1;

        while (low <= high) 
        {
            int mid = low + (high - low) / 2;
            if(func(nums,threshold,mid)==true) 
            {
                ans = mid;
                high = mid - 1;
            } 
            else 
            {
                low = mid + 1;
            }
        }
        return ans;
    }