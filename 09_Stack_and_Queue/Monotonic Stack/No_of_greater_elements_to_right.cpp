#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices)
{
    // write your code here
    stack<int> asc;
    stack<int> desc;
    vector<int> v(n, 0);
    vector<int> ans;
    for (int i = n - 1; i >= 0; i--)
    {
        int ele = arr[i];
        while (!asc.empty() && ele >= asc.top())
        {
            desc.push(asc.top());
            asc.pop();
        }
        desc.push(ele);
        v[i] = asc.size();
        while (!desc.empty())
        {
            asc.push(desc.top());
            desc.pop();
        }
    }
    for (int i = 0; i < queries; i++)
    {
        ans.push_back(v[indices[i]]);
    }
    return ans;
}

/*
1. Initialize Two Stacks
    asc → Maintains a monotonic decreasing stack (stores elements in decreasing order).
    desc → Temporary stack used for rearranging elements.

2. Iterate Backwards from n-1 to 0
    This ensures that we process elements from right to left.
    We use a stack-based approach to track greater elements to the right.

3. Process Each Element (arr[i])
    Remove Smaller Elements:
        Pop all elements from asc that are less than or equal to arr[i] and push them into desc.
        This ensures only greater elements remain in asc.
    Store Count of Greater Elements:
        The remaining elements in asc are greater than arr[i], so asc.size() gives the NGE count for index i.
    Restore asc Stack:
        Move all elements from desc back to asc to maintain order.

4. Answer Queries Efficiently
    The result array v[] is precomputed, so for each query, we simply return v[indices[i]] in O(1) time.
*/
