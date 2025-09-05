#include <iostream>
#include <vector>
using namespace std;

int missingNumber(vector<int> &nums)
{
    int n = nums.size();
    int sum = 0;
    int exp = 0;

    for (int i = 0; i < n; i++)
        sum = sum + nums[i];
    for (int i = 1; i <= n; i++)
        exp = exp + i;

    return (exp - sum);
}

/*
Logic:

1. Calculate actual sum - Add up all the numbers that are actually present in the given array and store in sum.
2. Calculate expected sum - Calculate what the sum should be if no numbers were missing:
The array should contain numbers from 0 to n (where n is the array size)
So we need sum of 1 + 2 + 3 + ... + n (note: 0 doesn't contribute to sum)
Store this expected sum in exp
3. Find the difference - The missing number is simply expected sum - actual sum.

Mathematical insight: If one number is missing from a complete sequence, the difference between the expected total and actual total will be exactly that missing number.

Example:
Input: [3,0,1] (missing 2 from sequence 0,1,2,3)
Actual sum: 3 + 0 + 1 = 4
Expected sum: 1 + 2 + 3 = 6 (sum from 1 to n where n=3)
Missing number: 6 - 4 = 2 ✓

Alternative approach: This could also be solved using XOR operations or the formula n*(n+1)/2 for calculating expected sum.
*/