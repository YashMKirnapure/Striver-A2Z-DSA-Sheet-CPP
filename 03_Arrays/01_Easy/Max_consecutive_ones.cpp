#include <bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(vector<int> &nums)
{
    int n = nums.size();
    int maxy = 0;
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 0)
            cnt = 0;
        else
            cnt++;
        maxy = max(maxy, cnt);
    }
    return maxy;
}

/*
Logic:

1. Initialize tracking variables - Use cnt to track current consecutive 1s and maxy to track the maximum seen so far.
2. Scan through the array - For each element in the array:
If it's a 0: Reset the current consecutive count (cnt = 0) because the streak is broken
If it's a 1: Increment the current consecutive count (cnt++) to extend the current streak
3. Update maximum - After processing each element, update maxy with the maximum value between the current maximum and current consecutive count.
4. Return result - maxy contains the length of the longest consecutive sequence of 1s.

Example:
Input: [1,1,0,1,1,1,0,1]
Process:

At 1,1: cnt=2, maxy=2
At 0: cnt=0, maxy=2
At 1,1,1: cnt=3, maxy=3
At 0: cnt=0, maxy=3
At 1: cnt=1, maxy=3

Result: 3 (longest consecutive 1s)
*/