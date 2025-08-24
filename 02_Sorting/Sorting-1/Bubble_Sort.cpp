#include <iostream>
#include <vector>
using namespace std;

vector<int> bubbleSort(vector<int>& nums) 
{
    int n = nums.size();
    
    for(int i=n-1 ;i>=0 ;i--)
    {
        for(int j=0 ;j<=i-1 ;j++)
        {
            if(nums[j] > nums[j+1])
                swap(nums[j],nums[j+1]);
        }
    }
    return nums;    
}