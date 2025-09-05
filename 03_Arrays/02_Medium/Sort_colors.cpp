#include <bits/stdc++.h>
using namespace std;

void sortColors(vector<int> &nums)
{
    int n = nums.size();
    int c0 = 0;
    int c1 = 0;
    int c2 = 0;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 0)
            c0++;
        if (nums[i] == 1)
            c1++;
        if (nums[i] == 2)
            c2++;
    }

    int k = 0;

    for (int i = 0; i < c0; i++)
        nums[k++] = 0;

    for (int i = 0; i < c1; i++)
        nums[k++] = 1;

    for (int i = 0; i < c2; i++)
        nums[k++] = 2;
}

// Dutch National Flag Algorithm - Optimal approach
void sortColors(vector<int>& nums) {
    int n = nums.size();
    int low = 0;    // pointer for 0s region
    int mid = 0;    // current element pointer
    int high = n - 1; // pointer for 2s region
    
    while (mid <= high) {
        if (nums[mid] == 0) {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        }
        else if (nums[mid] == 1) {
            mid++;
        }
        else { // nums[mid] == 2
            swap(nums[mid], nums[high]);
            high--;
            // Don't increment mid here, need to check swapped element
        }
    }
}

/*
Logic:

1.Count each value - Make a first pass through the array to count how many 0s, 1s, and 2s are present:

c0 = count of 0s
c1 = count of 1s
c2 = count of 2s

2.Reconstruct the array in sorted order - Use a second pass to overwrite the original array:
Use k as a pointer to track the current position being filled

3.Place values in order:
First: Place all 0s at the beginning (c0 times)
Second: Place all 1s in the middle (c1 times)
Third: Place all 2s at the end (c2 times)

4.Result: The array is now sorted with all 0s first, then all 1s, then all 2s.

Example:
Input: [2,0,2,1,1,0]
After counting: c0=2, c1=2, c2=2
Reconstruction: Fill positions 0-1 with 0s, positions 2-3 with 1s, positions 4-5 with 2s
Result: [0,0,1,1,2,2]







Dutch National Flag Algorithm - Logic in Natural Language:
Purpose: Sort an array of 0s, 1s, and 2s in a single pass using three pointers.
Core Concept:
Divide the array into 4 regions:

[0 to low-1] → All 0s (sorted)
[low to mid-1] → All 1s (sorted)
[mid to high] → Unknown/unsorted elements
[high+1 to n-1] → All 2s (sorted)

Three Pointer Logic:

low pointer - Marks the boundary where next 0 should be placed
mid pointer - Current element being examined
high pointer - Marks the boundary where next 2 should be placed

Algorithm Steps:
While mid <= high:

If nums[mid] == 0:

Swap with element at low position
Increment both low and mid (we know swapped element from low region is 1)


If nums[mid] == 1:

It's in correct region, just move mid forward


If nums[mid] == 2:

Swap with element at high position
Decrement high but don't increment mid (need to check what we swapped)

Input: [2,0,2,1,1,0]
Initial: low=0, mid=0, high=5

Step 1: nums[0]=2, swap with high, array=[0,0,2,1,1,2], low=0,mid=0,high=4
Step 2: nums[0]=0, swap with low, array=[0,0,2,1,1,2], low=1,mid=1,high=4
Step 3: nums[1]=0, swap with low, array=[0,0,2,1,1,2], low=2,mid=2,high=4
Step 4: nums[2]=2, swap with high, array=[0,0,1,1,2,2], low=2,mid=2,high=3
Step 5: nums[2]=1, increment mid, low=2,mid=3,high=3
Step 6: nums[3]=1, increment mid, low=2,mid=4,high=3
Step 7: mid > high, stop

Final: [0,0,1,1,2,2]

*/