#include <bits/stdc++.h>
using namespace std;

//Method 1
void func(vector<int> &arr, int idx, vector<int> &res, int n)
{
    if (idx == n - 1)
    {
        res.push_back(arr[idx]);
        return;
    }
    
    func(arr, idx + 1, res, n);
    
    if (arr[idx] >= res.back())
    res.push_back(arr[idx]);
}

vector<int> leaders(vector<int> &arr)
{
    int n = arr.size();
    vector<int> res;
    func(arr, 0, res, n);
    reverse(res.begin(), res.end());
    return res;
}

//Method 2
vector<int> leaders(vector<int> &arr)
{
    int n = arr.size();
    vector<int> res;

    int curr = arr[n - 1];
    res.push_back(curr);

    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] >= curr)
        {
            curr = arr[i];
            res.push_back(curr);
        }
    }
    reverse(res.begin(), res.end());
    return res;
}