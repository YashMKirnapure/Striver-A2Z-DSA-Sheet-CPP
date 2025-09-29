#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string str)
{
    int n = str.size();
    int ans = 0;

    int left = 0;
    int right = 0;

    unordered_map<char, int> mp;

    while (right < n)
    {
        mp[str[right]]++;
        int window = right - left + 1;

        if (mp.size() == window)
        {
            ans = max(ans, window);
        }
        else
        {
            while (window > mp.size())
            {
                mp[str[left]]--;
                if (mp[str[left]] == 0)
                    mp.erase(str[left]);
                left++;
                window = right - left + 1;
            }
        }
        right++;
    }
    return ans;
}