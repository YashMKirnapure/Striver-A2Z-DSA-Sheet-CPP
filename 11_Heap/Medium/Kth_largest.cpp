#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int findKthLargest(vector<int> &nums, int k)
{
    int n = nums.size();
    priority_queue<int> pq;

    for (int x : nums)
        pq.push(x);

    while (k != 1)
    {
        pq.pop();
        k--;
    }
    return pq.top();
}