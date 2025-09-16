#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int findMaxLength(vector<int> &nums)
{
    int n = nums.size();
    unordered_map<int, int> mp;
    mp[0] = -1;

    int ans = 0;
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 1)
            sum = sum + 1;
        else
            sum = sum - 1;

        if (mp.count(sum))
            ans = max(ans, i - mp[sum]);
        else
            mp[sum] = i;
    }
    return ans;
}