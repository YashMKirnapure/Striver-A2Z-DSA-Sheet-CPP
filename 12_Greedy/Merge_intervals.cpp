#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    int n = intervals.size();
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> res;
    vector<int> temp = intervals[0];

    if (n == 0)
        return res;

    for (int i = 1; i < n; i++)
    {
        if (temp[1] < intervals[i][0])
        {
            res.push_back(temp);
            temp = intervals[i];
        }
        else
        {
            temp[1] = max(intervals[i][1], temp[1]);
        }
    }
    res.push_back(temp);
    return res;
}