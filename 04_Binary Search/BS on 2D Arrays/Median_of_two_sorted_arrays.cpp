#include <bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    int n1 = nums1.size();
    int n2 = nums2.size();

    if (n1 > n2)
        return findMedianSortedArrays(nums2, nums1);

    int low = 0;
    int high = n1;
    int left = (n1 + n2 + 1) / 2;
    int n = n1 + n2;

    while (low <= high)
    {
        int mid1 = (low + high) / 2;
        int mid2 = left - mid1;
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;

        if (mid1 < n1)
            r1 = nums1[mid1];
        if (mid2 < n2)
            r2 = nums2[mid2];
        if (mid1 - 1 >= 0)
            l1 = nums1[mid1 - 1];
        if (mid2 - 1 >= 0)
            l2 = nums2[mid2 - 1];
        if (l1 <= r2 && l2 <= r1)
        {
            if (n % 2 == 1)
                return max(l1, l2);
            return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
        }
        else if (l1 > r2)
            high = mid1 - 1;
        else
            low = mid1 + 1;
    }
    return 0;
}

/*
Ensure nums1 is the smaller array (so binary search runs on the shorter one → better efficiency).

Partition both arrays into left half and right half such that:

Total elements in left = (n1 + n2 + 1) / 2 (to balance even/odd cases).

So if mid1 elements are taken from nums1, then mid2 = left - mid1 elements must come from nums2.

Track four boundaries:

l1 = nums1[mid1 - 1] (left of partition in nums1)

r1 = nums1[mid1] (right of partition in nums1)

l2 = nums2[mid2 - 1] (left of partition in nums2)

r2 = nums2[mid2] (right of partition in nums2)

(Handle out-of-bound cases with INT_MIN and INT_MAX).

Valid partition condition:

l1 <= r2 && l2 <= r1

→ means all left elements ≤ all right elements. 

If valid:

If (n1 + n2) is odd → median is max(l1, l2) (the extra left element).

If even → median is (max(l1, l2) + min(r1, r2)) / 2.0.

If not valid:

If l1 > r2 → move high left.

Else (l2 > r1) → move low right.
*/