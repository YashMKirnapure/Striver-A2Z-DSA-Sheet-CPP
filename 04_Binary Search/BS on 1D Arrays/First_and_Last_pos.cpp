#include <iostream>
#include <vector>
using namespace std;

vector<int> searchRange(vector<int> &arr, int target)
{
    int n = arr.size();
    int low = 0;
    int high = n - 1;

    int first = -1;
    int last = -1;

    // Find first occurence
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == target)
        {
            first = mid;
            high = mid - 1;
        }
        else if (arr[mid] > target)
            high = mid - 1;
        else
            low = mid + 1;
    }

    // Find last occurence
    low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == target)
        {
            last = mid;
            low = mid + 1;
        }
        else if (arr[mid] > target)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return {first, last};
}

/*
Use binary search twice.

For first occurrence: when arr[mid] == target, record first = mid and keep searching left.

For last occurrence: when arr[mid] == target, record last = mid and keep searching right.

Return {first, last} (or {-1, -1} if not found).
*/