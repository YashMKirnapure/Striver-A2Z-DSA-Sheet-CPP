#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int> &nums)
{
    // next_permutation(nums.begin(),nums.end());    // Short Cut

    int n = nums.size();
    int idx = -1;

    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            idx = i;
            break;
        }
    }

    if (idx == -1)
    {
        reverse(nums.begin(), nums.end());
        return;
    }

    for (int i = n - 1; i > idx; i--)
    {
        if (nums[i] > nums[idx])
        {
            swap(nums[i], nums[idx]);
            break;
        }
    }

    reverse(nums.begin() + idx + 1, nums.end());
}

/*
Step-by-step explanation:

Find the "dip" index (idx)

Traverse from right to left, find the first index i such that nums[i] < nums[i+1].

This i is where the increasing order breaks.

Example: [1, 3, 5, 4, 2] → idx = 1 because 3 < 5.

If no such index exists (idx == -1), it means the array is in descending order (like [5,4,3,2,1]).
→ Just reverse the array to get the smallest permutation ([1,2,3,4,5]).
→ Done.

Find the smallest number greater than nums[idx] on the right

Scan from the end towards idx.

Find the first element greater than nums[idx].

Swap them.

Example: [1, 3, 5, 4, 2] → idx = 1 (nums[idx] = 3), the number just bigger is 4. Swap → [1, 4, 5, 3, 2].

Reverse the suffix after idx

After the swap, the part to the right of idx is still in descending order.

Reverse it to make it the smallest possible increasing sequence.

Example: [1, 4, 5, 3, 2] → reverse after 4: [1, 4, 2, 3, 5].

That’s the next permutation
*/