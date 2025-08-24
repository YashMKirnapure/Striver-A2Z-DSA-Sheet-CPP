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