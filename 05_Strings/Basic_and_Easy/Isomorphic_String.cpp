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