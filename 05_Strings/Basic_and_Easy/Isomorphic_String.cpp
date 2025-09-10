#include <iostream>
#include <unordered_map>
using namespace std;

bool isIsomorphic(string s1, string s2)
{
    int n1 = s1.size();
    int n2 = s2.size();

    unordered_map<char, char> mp;

    for (int i = 0; i < n1; i++)
    {
        if (mp.count(s1[i]) == 1)
        {
            if (mp[s1[i]] != s2[i])
                return false;
        }
        else
        {
            for (auto x : mp)
            {
                if (x.second == s2[i])
                    return false;
            }
            mp[s1[i]] = s2[i];
        }
    }
    return true;
}

/*
1. Check lengths first
    If two strings have different lengths, they can’t be isomorphic (but in this code, since we iterate over s1.size(), it implicitly assumes lengths match).

2. Use a mapping (dictionary)
    Create a map mp to store the mapping of characters from s1 → s2.
    Example: if s1 = "egg" and s2 = "add", then 'e' → 'a', 'g' → 'd'.

3. Iterate over characters
    For each position i, check:
        If s1[i] is already mapped in mp:
            Verify it maps to the same s2[i].
            If not, return false (conflict).
        If s1[i] is not mapped yet:
            Make sure no other character in s1 is already mapped to s2[i] (to avoid two-to-one mapping).
            Then add the mapping s1[i] → s2[i].

4. If the loop completes without conflicts → return true.
*/