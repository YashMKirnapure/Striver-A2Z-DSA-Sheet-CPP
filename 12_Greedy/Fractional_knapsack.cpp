#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static bool mycomp(pair<int, int> &p1, pair<int, int> &p2)
{
    return (double)p1.first / p1.second > (double)p2.first / p2.second;
}

double fractionalKnapsack(vector<int> &val, vector<int> &wt, int capacity)
{
    double total = 0.0;
    int n = val.size();

    vector<pair<int, int>> res;

    for (int i = 0; i < n; i++)
        res.push_back({val[i], wt[i]});

    sort(res.begin(), res.end(), mycomp);

    for (int i = 0; i < n; i++)
    {
        if (capacity >= res[i].second)
        {
            total += res[i].first;
            capacity = capacity - res[i].second;
        }
        else
        {
            total += (double)res[i].first / res[i].second * capacity;
            break;
        }
    }
    return total;
}