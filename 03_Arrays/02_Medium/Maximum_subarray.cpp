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