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

int findKthLargest(vector<int> &nums, int k)
{
    int n = nums.size();
    priority_queue<int,vector<int>,greater<int>> pq;

    for(int i=0 ;i<k ;i++)
        pq.push(nums[i]);

    for(int i=k ;i<n ;i++)
    {
        if(nums[i] >= pq.top())
        {
            pq.pop();
            pq.push(nums[i]);
        }
    }
    return pq.top();
}
