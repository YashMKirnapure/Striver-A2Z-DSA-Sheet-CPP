#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int sumDivisibleByK(vector<int> &nums, int k)
{
    int n = nums.size();
    unordered_map<int, int> mp;
    int total = 0;

    for (int x : nums)
        mp[x]++;

    for (auto x : mp)
    {
        int key = x.first;
        int freq = x.second;

        if (freq % k == 0)
            total += key * freq;
    }
    return total;
}