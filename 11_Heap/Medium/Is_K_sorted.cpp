#include <iostream>
#include <queue>
using namespace std;

string isKSortedArray(int arr[], int n, int k)
{
    priority_queue<pair<int, int>> pq;

    for (int i = 0; i < n; i++)
        pq.push({arr[i], i});

    int t = n - 1;
    bool found = true;

    while (!pq.empty())
    {
        int idx = pq.top().second;
        pq.pop();

        if (abs(idx - t) > k)
        {
            found = false;
            break;
        }
        t--;
    }
    return found == true ? "Yes" : "No";
}