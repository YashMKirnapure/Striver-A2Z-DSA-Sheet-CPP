#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

//M-1
vector<int> topKFrequent(vector<int> &nums, int k)
{
    vector<int> ans;
    unordered_map<int, int> mp;
    for (auto x : nums)
    {
        mp[x]++;
    }
    priority_queue<pair<int, int>> p;
    for (auto it : mp)
    {
        p.push({it.second, it.first});
    }
    while (k--)
    {
        ans.push_back(p.top().second);
        p.pop();
    }
    return ans;
}

//M-2
struct Compare
{
    bool operator()(pair<int,int>&a,pair<int,int>&b) const
    {
        return a.second < b.second;
    }
};


vector<int> topKFrequent(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<int> res;
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
    unordered_map<int, int> mp;

    for (int x : nums)
        mp[x]++;

    for (auto x : mp)
        pq.push({x.first, x.second});

    while (k--)
    {
        res.push_back(pq.top().first);
        pq.pop();
    }
    return res;
}