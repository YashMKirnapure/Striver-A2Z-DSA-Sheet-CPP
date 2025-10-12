#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> topKSumPairs(vector<int> &a, vector<int> &b, int k)
{
    int n1 = a.size();
    int n2 = b.size();
    vector<int> res;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    priority_queue<pair<int, pair<int, int>>> pq;

    for (int i = 0; i < n1; i++)
        pq.push({a[i] + b[n1 - 1], {i, n1 - 1}});

    while (k--)
    {
        auto it = pq.top();
        res.push_back(it.first);
        pq.pop();

        int i = it.second.first;
        int j = it.second.second - 1;

        while (j >= 0 && (a[i] + b[j]) >= (pq.top().first) && k > 0)
        {
            res.push_back(a[i] + b[j]);
            j--;
            k--;
        }
        if (j >= 0)
            pq.push({a[i] + b[j], {i, j}});
    }
    return res;
}