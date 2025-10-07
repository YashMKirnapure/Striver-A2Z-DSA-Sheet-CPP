#include <bits/stdc++.h>
using namespace std;

int lastStoneWeight(vector<int> &stones)
{
    int n = stones.size();
    priority_queue<int> pq;

    if (n == 1)
        return stones[0];

    for (int x : stones)
        pq.push(x);

    while (pq.size() != 1)
    {
        int p1 = pq.top();
        pq.pop();
        int p2 = pq.top();
        pq.pop();

        pq.push(p1 - p2);
    }
    return pq.top();
}