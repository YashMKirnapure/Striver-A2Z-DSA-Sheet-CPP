#include <bits/stdc++.h>
using namespace std;

int findKthPositive(vector<int> &arr, int k)
{
    int n = arr.size();
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int missing = arr[mid] - (mid + 1);
        if (missing >= k)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low + k;
}

// M2
int findKthPositive(vector<int> &arr, int k)
{
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= k)
            k++;
        else
            break;
    }
    return k;
}

/*
At any index mid:

If no numbers were missing, the value should have been mid + 1.

But the actual value is arr[mid].

So, arr[mid] - (mid + 1) = how many numbers are missing up to index mid.

Use binary search:

If missing >= k → the k-th missing is before or at this index → move left (high = mid - 1).

Else → it’s after this index → move right (low = mid + 1).

After the loop, low points to the position where the k-th missing number belongs.

Formula: low + k gives the k-th missing number.
*/