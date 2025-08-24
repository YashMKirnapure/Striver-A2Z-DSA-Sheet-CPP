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