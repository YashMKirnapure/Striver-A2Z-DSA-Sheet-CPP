#include <iostream>
#include <vector>
using namespace std;

void moveZeroes(vector<int> &nums)
{
    int n = nums.size();
    int k = 0;
    vector<int> res(n);

    for (int i = 0; i < n; i++)
    {
        if (nums[i] != 0)
        {
            res[k] = nums[i];
            k++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 0)
        {
            res[k] = nums[i];
            k++;
        }
    }
    nums = res;
}

/* 
Logic:
1. Create a temporary array - Make a new array res of the same size to store the rearranged elements.

2. First pass - collect non-zeros - Go through the original array and copy all non-zero elements to the beginning of the result array:
Use k as a pointer to track where to place the next non-zero element
Only increment k when a non-zero element is found and placed

3. Second pass - collect zeros - Go through the original array again and copy all zero elements to the remaining positions in the result array:
Continue using k from where it left off (after all non-zeros)
This fills the rest of the array with zeros

4. Copy back - Replace the original array with the rearranged result.

Example:

Input: [0,1,0,3,12]
First pass: res = [1,3,12,_,_] and k = 3
Second pass: res = [1,3,12,0,0] and k = 5
Result: [1,3,12,0,0] (all non-zeros first, then all zeros)
*/