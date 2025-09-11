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

/*
1. Count character frequencies
    Use a map mp to count how many times each character appears in the string.
    Example: "tree" → {t:1, r:1, e:2}.
2. Convert to vector of pairs
    Store as (character, frequency) in a vector.
    Example: [ (t,1), (r,1), (e,2) ].
3. Sort by frequency
    Use a custom comparator cmp that sorts in descending order of frequency (p1.second > p2.second).
    After sorting: [ (e,2), (t,1), (r,1) ].
4. Build the result string
    For each (char, freq) in the sorted vector, append char repeated freq times.
*/