#include <bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int> &arr)
{
    int n = arr.size();
    int low = 0;
    int high = n - 1;

    if (n == 1)
        return arr[0];

    while (low < high)
    {
        int mid = (low + high) / 2;
        if (arr[low] != arr[low + 1])
            return arr[low];
        else if (arr[high] != arr[high - 1])
            return arr[high];
        else if (arr[mid] != arr[mid + 1] && arr[mid] != arr[mid - 1])
            return arr[mid];
        else
        {
            low = low + 2;
            high = high - 2;
        }
    }
    return 1;
}

// Single element in a sorted array (O(log n) solution)
int singleNonDuplicate(vector<int> &arr)
{
    int n = arr.size();
    int low = 0, high = n - 1;

    while (low < high)
    {
        int mid = (low + high) / 2;

        // Ensure mid is even (points to first in a pair)
        if (mid % 2 == 1)
            mid--;

        if (arr[mid] == arr[mid + 1])
            low = mid + 2; // single is in right half
        else
            high = mid; // single is in left half or at mid
    }

    return arr[low]; // low == high, pointing to single
}

/*
Use index parity to guide the binary search:

Find mid = (low + high)/2.

Ensure mid is even (so it points to the first element of a pair). If not, make it even.

If arr[mid] == arr[mid+1], the single lies in the right half → low = mid + 2.

Else, the single lies in the **left half (including mid)→high = mid`.

Loop until low == high, that’s your single element.
*/