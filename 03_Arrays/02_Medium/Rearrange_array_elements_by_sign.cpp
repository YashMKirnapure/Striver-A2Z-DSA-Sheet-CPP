#include <bits/stdc++.h>
using namespace std;

vector<int> rearrangeArray(vector<int>& nums) 
    {
        int n = nums.size();
        vector <int> res(n);

        int k = 0;
        int g = 1;

        for(int i=0 ;i<n ;i++)
        {
            if(nums[i] < 0)
            {
                res[g] = nums[i];
                g = g+2;
            }
            if(nums[i] >= 0)
            {
                res[k] = nums[i];
                k = k+2;
            }
        }
        return res;
    }