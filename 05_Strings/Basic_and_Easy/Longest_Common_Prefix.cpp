#include <iostream>
#include <vector>
using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
    int n = strs.size();
    string res = strs[0];

    if (n == 0)
        return "";

    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 1; j < strs.size(); j++)
        {
            if (i >= strs[j].size() || strs[j][i] != res[i])
            {
                return res.substr(0, i);
            }
        }
    }
    return res;
}

/*
1. Take the first string as a “baseline” prefix.

2. For each character position i in that baseline string:
    Compare it with the ith character of all other strings.
    If they all match → continue.
    If any mismatch (or a string ends) → stop, and return the prefix built so far.

3. If we get through the whole first string without mismatches → the whole string is the LCP.
*/