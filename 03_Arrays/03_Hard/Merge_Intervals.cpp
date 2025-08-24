#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    vector<vector<int>> res;
    int n = intervals.size();

    if (n == 0)
        return res;

    sort(intervals.begin(), intervals.end());

    vector<int> current = intervals[0];

    for (int i = 1; i < n; i++)
    {
        if (current[1] >= intervals[i][0])
            current[1] = max(current[1], intervals[i][1]);
        else
        {
            res.push_back(current);
            current = intervals[i];
        }
    }
    res.push_back(current);
    return res;
}