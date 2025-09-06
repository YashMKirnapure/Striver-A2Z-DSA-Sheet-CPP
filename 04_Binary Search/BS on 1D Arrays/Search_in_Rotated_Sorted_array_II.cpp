#include <bits/stdc++.h>
using namespace std;

bool search(vector<int> &arr, int target)
{
    int n = arr.size();
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == target)
            return true;

        if (arr[low] == arr[mid] && arr[mid] == arr[high])
        {
            low++;
            high--;
            continue;
        }

        if (arr[mid] >= arr[low])
        {
            if (target >= arr[low] && target <= arr[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        else
        {
            if (target >= arr[mid] && target <= arr[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return false;
}

/*
Standard binary search loop with low, high, mid.

If arr[mid] == target → return true.

If the values at low, mid, and high are all equal, you can’t decide which half is sorted.

So just shrink the search space → low++ and high--.

Otherwise, decide which half is sorted:

If left half (arr[low] … arr[mid]) is sorted:

If target lies in this range → high = mid - 1.

Else → low = mid + 1.

Else (right half is sorted):

If target lies in this range → low = mid + 1.

Else → high = mid - 1.

If loop finishes without finding target, return false.
*/