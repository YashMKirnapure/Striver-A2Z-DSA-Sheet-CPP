#include <iostream>
#include <vector>
using namespace std;

// Method 1
void func(vector<int>&nums,int i,int j,int n)
{
    if(j > i-1)
        return;
    if(nums[j] > nums[j+1])
        swap(nums[j],nums[j+1]);
        func(nums,i,j+1,n);
    }

vector <int> recBubbleSort(vector<int>&nums)
{
    int n = nums.size();
    int j = 0;
    
    for(int i=n-1 ;i>=0 ;i--)
        func(nums,i,j,n);
    
    return nums;
}

// Method 2
void func(vector<int>&nums,int n)
{
    if(n == 1)
        return;
        
    bool didSwap = false;
    
    for(int i=0 ;i<n-1 ;i++)
    {
        if(nums[i] > nums[i+1])
        {
            swap(nums[i],nums[i+1]);
            didSwap = true;
        }
    }
    
    if(didSwap == false)
        return;
    
    func(nums,n-1);
}

vector <int> recBubbleSort(vector<int>&nums)
{
    int n = nums.size();
    func(nums,n);
    return nums;
}


