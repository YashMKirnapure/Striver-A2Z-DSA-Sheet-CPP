#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int kthSmallest(vector<int> &arr, int k)
{
    int n = arr.size();
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int x : arr)
        pq.push(x);

    while (k != 1)
    {
        pq.pop();
        k--;
    }
    return pq.top();
}

int kthSmallest(vector<int> &arr, int k)
{
    int n = arr.size();
    priority_queue<int> pq;

    for (int i = 0; i < k; i++)
        pq.push(arr[i]);

    for (int i = k; i < n; i++)
    {
        if (arr[i] <= pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    return pq.top();
}