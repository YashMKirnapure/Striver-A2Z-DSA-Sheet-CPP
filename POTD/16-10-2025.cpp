//LC 2598. Smallest Missing Non-negative Integer After Operations

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int findSmallestInteger(vector<int> &nums, int value)
{
    int n = nums.size();
    int MEX = 0;
    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        int rem = ((nums[i] % value) + value) % value;
        mp[rem]++;
    }

    while (mp[MEX % value] > 0)
    {
        mp[MEX % value]--;
        MEX++;
    }
    return MEX;
}

int main()
{
    vector<int>nums = {1,-10,7,13,6,8};
    int value = 5;
    cout<<findSmallestInteger(nums,value);
}