#include <iostream>
#include <map>
using namespace std;

bool isAnagram(string s, string t)
{
    map<char, int> mp;

    if (s.size() != t.size())
        return false;

    for (int i = 0; i < s.size(); i++)
    {
        mp[s[i]]++;
        mp[t[i]]--;
    }

    for (auto x : mp)
    {
        if (x.second != 0)
            return false;
    }
    return true;
}