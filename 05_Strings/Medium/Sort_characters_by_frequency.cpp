#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

static bool cmp(pair<char, int> &p1, pair<char, int> &p2)
{
    return p1.second > p2.second;
}

string frequencySort(string str)
{
    int n = str.size();
    map<char, int> mp;

    for (int i = 0; i < n; i++)
        mp[str[i]]++;

    vector<pair<char, int>> res(mp.begin(), mp.end());

    sort(res.begin(), res.end(), cmp);

    string ans;

    for (auto x : res)
        ans.append(x.second, x.first);

    return ans;
}