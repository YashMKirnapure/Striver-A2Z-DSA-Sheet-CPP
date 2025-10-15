#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findContentChildren(vector<int> &g, vector<int> &s)
{
    int n1 = g.size();
    int n2 = s.size();
    int l = 0;
    int r = 0;

    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int cnt = 0;

    while (l < n1 && r < n2)
    {
        if (g[l] <= s[r])
        {
            cnt++;
            l++;
        }
        r++;
    }
    return cnt;
}