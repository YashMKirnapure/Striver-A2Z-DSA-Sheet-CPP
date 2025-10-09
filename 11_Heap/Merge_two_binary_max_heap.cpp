#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//M-1
vector<int> mergeHeaps(vector<int> &a, vector<int> &b,int n, int m)
{
    priority_queue<int> pq;

    for (int x : a)
        pq.push(x);
    for (int x : b)
        pq.push(x);

    vector<int> res;
    while (!pq.empty())
    {
        res.push_back(pq.top());
        pq.pop();
    }
    return res;
}

//M-2
void heapify(vector<int>&res,int index,int n)
{
    int largest = index;
    int left = 2*index + 1;
    int right = 2*index + 2;

    if(left<n && res[largest] < res[left])
        largest = left;
    if(right<n && res[largest] < res[right])
        largest = right;
    
    if(largest!=index)
    {
        swap(res[largest],res[index]);
        heapify(res,largest,n);
    }
}

vector<int> mergeHeaps(vector<int> &a, vector<int> &b,int n, int m)
{
    vector<int>res;

    for(int x : a)
        res.push_back(x);
    for(int x : b)
        res.push_back(x);
    
    int sz = res.size();
    for(int i=sz/2-1 ;i>=0 ;i--)
        heapify(res,i,sz);
    
    return res;
}