#include <bits/stdc++.h>
using namespace std;

int totalFruit(vector<int> &fruits)
{
    int n = fruits.size();
    unordered_map<int, int> mp;
    int left = 0;
    int right = 0;
    int maxlen = 0;
    int len = 0;

    while (right < n)
    {
        mp[fruits[right]]++;
        if (mp.size() <= 2)
        {
            len = right - left + 1;
            maxlen = max(maxlen, len);
        }
        else
        {
            mp[fruits[left]]--;
            if (mp[fruits[left]] == 0)
                mp.erase(fruits[left]);
            left++;
        }
        right++;
    }
    return maxlen;
}