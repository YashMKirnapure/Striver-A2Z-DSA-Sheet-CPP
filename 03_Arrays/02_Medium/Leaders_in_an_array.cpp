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

/*
Logic:

Start from the end - The rightmost element is always a leader (nothing to its right), so add it to result and set it as current maximum.
Traverse from right to left - Process elements from second-last to first:

Compare each element with the current maximum from its right side
If current element is greater than or equal to the maximum on its right, it's a leader


Update and collect leaders:

If arr[i] >= curr: This element is a leader, add to result and update curr to this new maximum
If arr[i] < curr: Skip this element (not a leader)


Reverse the result - Since we processed from right to left, reverse the result to get leaders in their original left-to-right order.

Example:

Input: [16,17,4,3,5,2]
Process (right to left):

Start: curr=2, res=[2]
At 5: 5≥2, curr=5, res=[2,5]
At 3: 3<5, skip
At 4: 4<5, skip
At 17: 17≥5, curr=17, res=[2,5,17]
At 16: 16<17, skip


After reverse: [17,5,2]

Key insight: By traversing right-to-left, we can efficiently track the maximum element seen so far from the right, eliminating the need to check all elements to the right for each position.
*/