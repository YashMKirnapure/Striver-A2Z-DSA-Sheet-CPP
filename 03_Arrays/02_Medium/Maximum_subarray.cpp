#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int> &nums)
{
    int n = nums.size();
    int maxy = INT_MIN;
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum = sum + nums[i];
        maxy = max(sum, maxy);
        if (sum < 0)
            sum = 0;
    }
    return maxy;
}

/*
Logic:

Initialize variables - Start with maxy = INT_MIN (to handle all negative arrays) and sum = 0 to track current subarray sum.
Core insight - At each position, decide whether to:

Extend the current subarray by adding current element, OR
Start fresh from current element if previous sum was dragging us down

Process each element:

Add current element to running sum: sum += nums[i]
Update maximum seen so far: maxy = max(sum, maxy)
Reset if negative - If current sum becomes negative, reset to 0 (start fresh from next element)

Key principle - A negative prefix sum can never help maximize a future subarray, so we abandon it and start over.
Return result - maxy contains the maximum subarray sum found.
*/
