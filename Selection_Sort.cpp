#include <iostream>
#include <vector>
using namespace std;

vector<int> selectionSort(vector<int>& nums) 
{
    int n = nums.size();

    for(int i=0 ;i<n-1 ;i++)
    {
        int miny = i;
        for(int j=i+1 ;j<n ;j++)
        {
            if(nums[j] < nums[miny])
                miny = j;
        }
        swap(nums[miny],nums[i]);
    }
    return nums;
}

