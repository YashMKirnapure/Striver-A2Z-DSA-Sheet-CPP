#include <iostream>
#include <vector>
using namespace std;

// Method 1 : Iterative BS
int search(vector<int> &nums, int target)
{
    int n = nums.size();
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] > target)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

// Method 2 : Recursion BS
int func(vector<int> &nums, int n, int target, int low, int high)
{
    int mid = (low + high) / 2;
    if (low > high)
        return -1;
    if (nums[mid] == target)
        return mid;
    else if (nums[mid] > target)
        return func(nums, n, target, low, mid - 1);
    else
        return func(nums, n, target, mid + 1, high);
}

int search(vector<int> &nums, int target)
{
    int n = nums.size();
    int low = 0;
    int high = n - 1;

    return func(nums, n, target, low, high);
}