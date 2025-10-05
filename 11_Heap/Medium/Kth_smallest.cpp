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
