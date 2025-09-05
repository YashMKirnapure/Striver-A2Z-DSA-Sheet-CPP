#include <bits/stdc++.h>
using namespace std;

vector<int> rearrangeArray(vector<int>& nums) 
    {
        int n = nums.size();
        vector <int> res(n);

        int k = 0;
        int g = 1;

        for(int i=0 ;i<n ;i++)
        {
            if(nums[i] < 0)
            {
                res[g] = nums[i];
                g = g+2;
            }
            if(nums[i] >= 0)
            {
                res[k] = nums[i];
                k = k+2;
            }
        }
        return res;
    }

    /*
    Logic:

Create result array - Make a new array res of the same size to store the rearranged elements.
Use two pointers for positioning:

k = 0 → tracks even indices (0, 2, 4, ...) for positive numbers
g = 1 → tracks odd indices (1, 3, 5, ...) for negative numbers


Process each element:

If negative (nums[i] < 0): Place it at the next odd position (res[g]) and move g forward by 2
If positive (nums[i] >= 0): Place it at the next even position (res[k]) and move k forward by 2


Result pattern: Creates alternating positive-negative pattern: [+, -, +, -, +, -, ...]

Example:

Input: [3,1,-2,-5,2,-4]
Process:

3 (positive): res[0]=3, k=2
1 (positive): res[2]=1, k=4
-2 (negative): res[1]=-2, g=3
-5 (negative): res[3]=-5, g=5
2 (positive): res[4]=2, k=6
-4 (negative): res[5]=-4, g=7


Result: [3,-2,1,-5,2,-4]

Key insight: By using separate pointers that jump by 2, we ensure positive numbers occupy even positions and negative numbers occupy odd positions, creating the desired alternating pattern.
Time Complexity: O(n) - single pass
Space Complexity: O(n) - for result array
Assumption: The problem assumes equal number of positive and negative elements for perfect alternation.
    */