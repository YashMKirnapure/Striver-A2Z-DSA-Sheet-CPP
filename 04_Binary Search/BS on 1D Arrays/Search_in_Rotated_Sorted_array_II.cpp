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