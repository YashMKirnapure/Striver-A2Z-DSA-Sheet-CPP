#include <bits/stdc++.h>
using namespace std;

static bool mycomp(pair<int, int> &a, pair<int, int> &b)
{
    return a.second < b.second;
}

int maxMeetings(vector<int> &start, vector<int> &end)
{
    int n = start.size();
    vector<pair<int, int>> res;

    for (int i = 0; i < n; i++)
        res.push_back({start[i], end[i]});

    sort(res.begin(), res.end(), mycomp);

    int cnt = 1;
    int prev = 0;

    for (int curr = 1; curr < n; curr++)
    {
        if (res[curr].first > res[prev].second)
        {
            prev = curr;
            cnt++;
        }
    }
    return cnt;
}