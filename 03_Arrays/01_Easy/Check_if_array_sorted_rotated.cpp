#include <iostream>
#include <vector>
using namespace std;

bool check(vector<int> &nums)
{
    int n = nums.size();
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] > nums[(i + 1) % n])
            cnt++;
    }
    return cnt <= 1;
}

/* 
Logic:

1.Count the "breaks" - Go through each element in the array and count how many times an element is greater than the next element (wrapping around to the first element when at the end).

2.The key insight - In a properly sorted and rotated array, there can be at most one "break" point where a larger number is followed by a smaller number. This break point represents where the rotation occurred.

3.Return the result - If there's 0 or 1 break, the array is valid (either already sorted or sorted+rotated). If there are 2 or more breaks, it's not a valid sorted and rotated array.

Examples:

[1,2,3,4,5] → 0 breaks (already sorted) ✓
[3,4,5,1,2] → 1 break (between 5 and 1) ✓
[2,1,3,4] → 2 breaks (between 2,1 and 4,2) ✗

The (i + 1) % n handles the wraparound comparison between the last element and the first element.
*/