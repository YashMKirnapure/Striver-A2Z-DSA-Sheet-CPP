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

/*
You start with a sorted array of numbers and a target number you want to find.

You keep two pointers:

low → the start of the array.

high → the end of the array.

While low is less than or equal to high:

Find the middle index → mid = (low + high) / 2.

Check the middle element:

If it’s exactly the target → found it → return mid.

If the middle element is bigger than the target → the target must be in the left half, so shift high = mid - 1.

If the middle element is smaller than the target → the target must be in the right half, so shift low = mid + 1.

If the loop ends without finding the target, return -1 (meaning “not present”).
*/