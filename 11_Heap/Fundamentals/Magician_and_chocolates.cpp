#include <bits/stdc++.h>
using namespace std;

int Solution::nchoc(int A, vector<int> &B)
{
    long long mod = 1e9 + 7;
    long long maxChocs = 0;
    priority_queue<int> pq;

    for (int i = 0; i < B.size(); i++)
        pq.push(B[i]);

    while (A && (!pq.empty()))
    {
        maxChocs += pq.top();
        if (pq.top() / 2)
            pq.push(pq.top() / 2);
        pq.pop();
        A--;
    }
    return maxChocs % mod;
}