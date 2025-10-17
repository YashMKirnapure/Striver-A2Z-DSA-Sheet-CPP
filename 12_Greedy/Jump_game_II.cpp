#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int jump(vector<int> &nums)
{
    int n = nums.size();
    int jumps = 0;
    int left = 0;
    int right = 0;

    while (right < n - 1)
    {
        int farthest = 0;
        for (int ind = left; ind <= right; ind++)
        {
            farthest = max(ind + nums[ind], farthest);
        }
        left = right + 1;
        right = farthest;
        jumps++;
    }
    return jumps;
}