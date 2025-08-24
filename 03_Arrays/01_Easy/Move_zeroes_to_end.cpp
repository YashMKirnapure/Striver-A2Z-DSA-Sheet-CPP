#include <iostream>
#include <vector>
using namespace std;

void moveZeroes(vector<int> &nums)
{
    int n = nums.size();
    int k = 0;
    vector<int> res(n);

    for (int i = 0; i < n; i++)
    {
        if (nums[i] != 0)
        {
            res[k] = nums[i];
            k++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 0)
        {
            res[k] = nums[i];
            k++;
        }
    }
    nums = res;
}