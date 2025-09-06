#include <iostream>
#include <vector>
using namespace std;

int searchInsert(vector<int> &nums, int target)
{
    int n = nums.size();
    int low = 0;
    int high = n - 1;
    int ans = n;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] >= target)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

/*
You’re given a sorted array and a target.

The task:

If target exists in the array → return its index.

If it doesn’t exist → return the index where target should be inserted so the array stays sorted.

Variables:

low = 0 → start of array.

high = n-1 → end of array.

ans = n → default answer (meaning “insert at the end” if nothing else fits).

While low <= high:

Find mid = (low + high) / 2.

If nums[mid] >= target:

This could be a valid position for the target.

Save it → ans = mid.

But since there could be an earlier valid index, move left → high = mid - 1.

Else (nums[mid] < target):

Target must be on the right side → low = mid + 1.

After the loop, return ans.
*/
