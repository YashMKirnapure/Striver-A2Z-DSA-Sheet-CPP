#include <bits/stdc++.h>
using namespace std;

long long pickGifts(vector<int> &gifts, int k)
{
    long long res = 0;
    priority_queue<int> pq;
    int count = gifts.size();
    for (int i = 0; i < count; i++)
        pq.push(gifts[i]);
    while (k != 0)
    {
        int x = floor(sqrt(pq.top()));
        pq.pop();
        pq.push(x);
        k--;
    }
    while (pq.empty() == false)
    {
        res = res + pq.top();
        pq.pop();
    }
    return res;
}