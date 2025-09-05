#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) 
{
        int n = nums.size();
        int cnt = 1;

        for(int i=1 ;i<n ;i++)
        {
            if(nums[i]!=nums[i-1])
            {
                nums[cnt] = nums[i];
                cnt++;
            }
        }
        return cnt;
}

/* 
Logic:

1.Initialize counter - Start with cnt = 1 because the first element is always unique (assuming array is non-empty).

2.Two-pointer approach - Use i to scan through the array from position 1, and cnt as a "write pointer" to track where to place the next unique element.

3. Compare adjacent elements - For each element, compare it with the previous element (nums[i] vs nums[i-1]).

4.Handle unique elements - When you find an element that's different from the previous one:
Place this unique element at position cnt
Increment cnt to prepare for the next unique element

5.Skip duplicates - When elements are the same, just move to the next element without updating the array.

6. Return count - cnt represents both the count of unique elements and the length of the modified array.

Example:

Input: [1,1,2,2,3]
Process: Keep 1 at pos 0, place 2 at pos 1, place 3 at pos 2
Result: [1,2,3,2,3] with return value 3 (first 3 elements are the answer)
*/