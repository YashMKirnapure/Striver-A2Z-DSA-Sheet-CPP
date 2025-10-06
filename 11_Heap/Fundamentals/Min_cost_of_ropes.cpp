#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int minCost(vector<int> &arr)
{
    int n = arr.size();
    priority_queue<int, vector<int>, greater<int>> pq;
    int minCost = 0;

    if (n == 1)
        return 0;

    for (int x : arr)
        pq.push(x);

    while (pq.size() != 1)
    {
        int x1 = pq.top();
        pq.pop();

        int x2 = pq.top();
        pq.pop();

        int sum = x1 + x2;
        minCost += sum;

        pq.push(sum);
    }
    return minCost;
}