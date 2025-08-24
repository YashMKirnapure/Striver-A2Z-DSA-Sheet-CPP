#include <bits/stdc++.h>
using namespace std;

void sortColors(vector<int>& nums) 
    {
        int n = nums.size();
        int c0 = 0;    
        int c1 = 0;    
        int c2 = 0;    

        for(int i=0 ;i<n ;i++)
        {
            if(nums[i] == 0)
                c0++;
            if(nums[i] == 1)
                c1++;
            if(nums[i] == 2)
                c2++;
        }

        int k = 0;
        
        for(int i=0 ;i<c0 ;i++)
            nums[k++] = 0;

        for(int i=0 ;i<c1 ;i++)
            nums[k++] = 1;

        for(int i=0 ;i<c2 ;i++)
            nums[k++] = 2;
            
    }