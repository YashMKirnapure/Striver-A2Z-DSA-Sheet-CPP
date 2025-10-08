#include <iostream>
#include <vector>
#include <queue>
using namespace std;

long long sumBetweenTwoKth(long long A[], long long N, long long K1, long long K2)
{
    priority_queue<long long> pq1;
    priority_queue<long long> pq2;
    long long sum1 = 0;
    long long sum2 = 0;

    for (int i = 0; i < K1; i++)
        pq1.push(A[i]);

    for (int i = K1; i < N; i++)
    {
        if (A[i] <= pq1.top())
        {
            pq1.pop();
            pq1.push(A[i]);
        }
    }

    while (!pq1.empty())
    {
        sum1 += pq1.top();
        pq1.pop();
    }

    for (int i = 0; i < K2 - 1; i++)
        pq2.push(A[i]);

    for (int i = K2 - 1; i < N; i++)
    {
        if (A[i] <= pq2.top())
        {
            pq2.pop();
            pq2.push(A[i]);
        }
    }

    while (!pq2.empty())
    {
        sum2 += pq2.top();
        pq2.pop();
    }

    return sum2 - sum1;
}