#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    int n1 = nums1.size();
    int n2 = nums2.size();

    unordered_map<int, int> next;
    stack<int> st;
    vector<int> res;

    for (int i = n2 - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= nums2[i])
            st.pop();
        if (st.empty())
            next[nums2[i]] = -1;
        else
            next[nums2[i]] = st.top();
        st.push(nums2[i]);
    }

    for (int x : nums1)
        res.push_back(next[x]);
    return res;
}

/*
1. Problem setup:
    You have two arrays:
    nums1: a subset of nums2
    For every element in nums1, you need to find the next greater element to its right in nums2.

2. Use a stack to process nums2 from right → left:
    The stack keeps potential next greater elements in monotonic decreasing order.
    If the current element nums2[i] is smaller than the stack’s top → the top is its next greater element.
    If it’s greater or equal, we pop until we find a taller element or the stack becomes empty.

3. Store results in a map (next):
    next[nums2[i]] = stack’s top (if any)
    If no greater element exists → -1
    Then, push the current element onto the stack.

4. Now build the final result for nums1:
    For every element x in nums1, just look up next[x] from the map.
*/