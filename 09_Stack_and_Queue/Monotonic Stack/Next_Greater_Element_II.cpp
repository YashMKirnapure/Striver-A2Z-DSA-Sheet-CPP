#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

vector<int> nextGreaterElements(vector<int> &nums)
{
    int n = nums.size();
    stack<int> st;
    vector<int> res(n, -1);

    for (int i = 2 * n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= nums[i % n])
            st.pop();
        if (!st.empty() && i < n)
            res[i] = st.top();
        st.push(nums[i % n]);
    }
    return res;
}

/*
1. Goal:
    For every element in the array, find the next greater element (NGE) — the first element to its right that’s larger.
    If no such element exists, return -1.

2. Why 2×n loop?
    Because the array is circular — after the last element, you “wrap around” to the first again.
    Hence, we iterate from 2n - 1 down to 0.

3. Stack stores potential NGEs.
    The stack holds elements in decreasing order (monotonic decreasing stack).
    If the current element is greater or equal to the stack’s top, that top can’t be an NGE for anyone — so we pop it.

4. Main loop (right → left):
    Pop all smaller/equal elements from the stack.
    If the stack isn’t empty and i < n, the top of the stack is the next greater element for nums[i].
    Push nums[i] onto the stack.

5. At the end:
res[i] holds the next greater number for every nums[i]; if none exists, it remains -1.
*/