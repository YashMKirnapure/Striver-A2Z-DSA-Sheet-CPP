#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) 
    {
        int n = nums.size();
        int cnt = 1;

        for(int i=1 ;i<n ;i++)
        {
            if(nums[i]!=nums[i-1])
            {
                nums[cnt] = nums[i];
                cnt++;
            }
        }
        return cnt;
    }