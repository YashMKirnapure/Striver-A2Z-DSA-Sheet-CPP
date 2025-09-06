#include <bits/stdc++.h>
using namespace std;

// LS Method
int search(vector<int> &nums, int target)
{
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == target)
            return i;
    }
    return -1;
}

// BS Method
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

        if (nums[mid] >= nums[low])
        {
            if (target >= nums[low] && target <= nums[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }

        else
        {
            if (target >= nums[mid] && target <= nums[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return -1;
}

/*
Standard binary search loop (low, high, mid).

If nums[mid] == target → return mid.

Otherwise, check which half is sorted:

If left half (nums[low] … nums[mid]) is sorted:

If target lies in that range → move high = mid - 1.

Else → move low = mid + 1.

Else (right half is sorted):

If target lies in that range → move low = mid + 1.

Else → move high = mid - 1.

If not found → return -1.
*/