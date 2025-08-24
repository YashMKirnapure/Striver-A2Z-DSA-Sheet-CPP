#include <bits/stdc++.h> 
using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) 
    {
        int n = nums.size();
        int maxy = 0;
        int cnt = 0;

        for(int i=0 ;i<n ;i++)
        {
            if(nums[i]==0)
                cnt = 0;
            else
                cnt++;
            maxy = max(maxy,cnt);
        }
    return maxy;
    }