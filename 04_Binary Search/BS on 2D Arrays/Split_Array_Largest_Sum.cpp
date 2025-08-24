#include <bits/stdc++.h>
using namespace std;


    bool isPossible(vector<int>&nums,int k,int mid)
    {
        int cnt = 1;
        int sum = 0;
        int n = nums.size();

        for(int i=0 ;i<n ;i++)
        {
            if(sum + nums[i] > mid)
            {
                sum = nums[i];
                cnt++;
            }
            else
            {
                sum += nums[i];
            }
        }
        return cnt <= k;
    }

    int splitArray(vector<int>& nums, int k) 
    {
        int n = nums.size();
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);
        int ans = -1;

        if(k == 1)
            return high;

        while(low <= high)
        {
            int mid = low + (high-low)/2;
            if(isPossible(nums,k,mid))
            {
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return ans;
    }