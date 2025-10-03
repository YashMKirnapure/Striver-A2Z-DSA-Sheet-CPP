#include <iostream>
#include <unordered_map>
using namespace std;

string minWindow(string str1, string str2)
{
    int minLen = INT_MAX;
    int n1 = str1.size();
    int n2 = str2.size();
    int left = 0;
    int right = 0;
    int start = -1;
    int cnt = 0;
    unordered_map<char, int> mp;

    for (int i = 0; i < n2; i++)
        mp[str2[i]]++;

    while (right < n1)
    {
        if (mp.count(str1[right]))
        {
            if (mp[str1[right]] > 0)
                cnt++;
            mp[str1[right]]--;
        }

        while (cnt == n2)
        {
            if (right - left + 1 < minLen)
            {
                minLen = right - left + 1;
                start = left;
            }
            if (mp.count(str1[left]))
            {
                mp[str1[left]]++;
                if (mp[str1[left]] > 0)
                    cnt--;
            }
            left++;
        }
        right++;
    }
    return (minLen == INT_MAX) ? "" : str1.substr(start, minLen);
}