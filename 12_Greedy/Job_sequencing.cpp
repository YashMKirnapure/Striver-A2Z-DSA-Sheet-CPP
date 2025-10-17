#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit)
{
    int n1 = deadline.size();
    int n2 = profit.size();
    vector<pair<int, int>> vp;
    int jobs = 0;
    int maxProfit = 0;

    for (int i = 0; i < n1; i++)
        vp.push_back({deadline[i], profit[i]});

    sort(vp.begin(), vp.end());

    priority_queue<int> pq;
    int ind = n1 - 1;

    for (int i = vp[n1 - 1].first; i >= 1; i--)
    {
        while (ind >= 0 && i == vp[ind].first)
        {
            pq.push(vp[ind].second);
            ind--;
        }
        if (!pq.empty())
        {
            jobs++;
            maxProfit += pq.top();
            pq.pop();
        }
    }
    return {jobs, maxProfit};
}