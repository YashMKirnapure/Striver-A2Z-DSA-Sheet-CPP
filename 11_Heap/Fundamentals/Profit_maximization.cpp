#include <bits/stdc++.h>
using namespace std;

int Solution::solve(vector<int> &A, int B)
{
    priority_queue<int> pq;
    int n = A.size();
    int res = 0;

    for (int x : A)
        pq.push(x);

    while (B--)
    {
        int x = pq.top();
        res = res + x;
        pq.pop();
        if (x != 0)
            pq.push(x - 1);
    }
    return res;
}