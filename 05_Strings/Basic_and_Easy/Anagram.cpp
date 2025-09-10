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

/*
1. Check lengths first
    If two strings s and t don’t have the same length → they can’t be anagrams → return false immediately.

2. Count characters
    Use a map mp (character → frequency).
    For each index i:
        Increment count of s[i] (mp[s[i]]++).
        Decrement count of t[i] (mp[t[i]]--).
    This way, if s and t contain the same characters with the same frequency, all counts will balance out to 0.

3. Verify the counts
    Traverse the map.
    If any character count is not 0 → strings differ → return false.
    Otherwise → return true (valid anagram).
*/