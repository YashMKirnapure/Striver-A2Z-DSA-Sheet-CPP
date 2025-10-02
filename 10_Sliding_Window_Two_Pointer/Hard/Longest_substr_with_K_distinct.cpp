#include <iostream>
#include <unordered_map>
using namespace std;

int longestKSubstr(string &str, int k)
{
    int n = str.size();
    unordered_map<char, int> mp;
    int left = 0;
    int right = 0;
    int maxLen = -1;

    while (right < n)
    {
        mp[str[right]]++;
        if (mp.size() == k)
        {
            int len = right - left + 1;
            maxLen = max(maxLen, len);
        }
        if (mp.size() > k)
        {
            mp[str[left]]--;
            if (mp[str[left]] == 0)
                mp.erase(str[left]);
            left++;
        }
        right++;
    }
    return maxLen;
}