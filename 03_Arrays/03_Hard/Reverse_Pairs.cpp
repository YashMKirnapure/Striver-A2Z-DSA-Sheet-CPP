#include <bits/stdc++.h>
using namespace std;

int reversePairs(vector<int> &nums)
{
    return mergeSort(nums, 0, nums.size() - 1);
}

int mergeSort(vector<int> &nums, int left, int right)
{
    if (left >= right)
        return 0;

    int mid = (left + right) / 2;
    int count = mergeSort(nums, left, mid) + mergeSort(nums, mid + 1, right);

    int j = mid + 1;
    for (int i = left; i <= mid; i++)
    {
        while (j <= right && (long long)nums[i] > 2LL * nums[j])
        {
            j++;
        }
        count += (j - (mid + 1));
    }

    vector<int> temp;
    int i = left;
    j = mid + 1;

    while (i <= mid && j <= right)
    {
        if (nums[i] <= nums[j])
            temp.push_back(nums[i++]);
        else
            temp.push_back(nums[j++]);
    }

    while (i <= mid)
        temp.push_back(nums[i++]);
    while (j <= right)
        temp.push_back(nums[j++]);

    for (int k = 0; k < temp.size(); k++)
    {
        nums[left + k] = temp[k];
    }

    return count;
}

/*
we use divide and conquer (merge sort):

Split the array into two halves.

Count reverse pairs within each half (recursively).

Count reverse pairs across halves (this is the tricky part).

Merge the halves while maintaining sorted order.

Step 1: Recursive Divide
int mid = (left + right) / 2;
int count = mergeSort(nums, left, mid) + mergeSort(nums, mid + 1, right);


This ensures we count all pairs inside [left, mid] and [mid+1, right].

Step 2: Count Cross-Half Pairs
int j = mid + 1;
for (int i = left; i <= mid; i++)
{
    while (j <= right && (long long)nums[i] > 2LL * nums[j])
    {
        j++;
    }
    count += (j - (mid + 1));
}


For each element in the left half (nums[i]), we find how many elements in the right half (nums[j]) satisfy:

nums[i]>2×nums[j]

Since the halves are sorted, we can just move j forward once (two-pointer technique).

Step 3: Merge Halves

Standard merge step to keep the array sorted:

vector<int> temp;
int i = left, j = mid + 1;
while (i <= mid && j <= right) {
    if (nums[i] <= nums[j]) temp.push_back(nums[i++]);
    else temp.push_back(nums[j++]);
}

This ensures future recursive calls work correctly.
*/