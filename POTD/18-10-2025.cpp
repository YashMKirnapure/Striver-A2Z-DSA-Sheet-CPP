#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxDistinctElements(vector<int> &nums, int k)
{
    int n = nums.size();

    if (n == 0)
        return 0;

    sort(nums.begin(), nums.end());
    int prev = -1e9;
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        int left = nums[i] - k;
        int right = nums[i] + k;
        int num = prev + 1;

        if (num < left)
            num = left;
        if (num <= right)
        {
            prev = num;
            cnt++;
        }
    }
    return cnt;
}