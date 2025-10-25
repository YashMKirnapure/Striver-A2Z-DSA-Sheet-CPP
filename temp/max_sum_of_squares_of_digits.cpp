#include <bits/stdc++.h>
using namespace std;

bool sumOfDigits(string temp, int sum)
{
    int total = 0;
    for (int i = 0; i < temp.size(); i++)
        total += (temp[i] - '0');
    return total == sum;
}

void findNums(vector<string> &nums, string temp, int num, int sum)
{
    if (temp.size() > num)
        return;

    if (temp.size() == num)
    {
        if (sumOfDigits(temp, sum))
            nums.push_back(temp);
        return;
    }

    for (int i = 0; i <= 9; i++)
    {
        char addDig = i + '0';
        findNums(nums, temp + addDig, num, sum);
    }
}

int maxOfAll(vector<string> &nums)
{
    int maxy = -1;

    for (int i = 0; i < nums.size(); i++)
        maxy = max(maxy, stoi(nums[i]));

    return maxy;
}

string maxSumOfSquares(int num, int sum)
{
    vector<string> nums;
    string temp;
    findNums(nums, temp, num, sum);

    int ans = maxOfAll(nums);
    return ans == -1 ? "" : to_string(ans);
}