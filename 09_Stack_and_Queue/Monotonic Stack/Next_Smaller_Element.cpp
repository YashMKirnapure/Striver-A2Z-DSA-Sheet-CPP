#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> nextSmallerEle(vector<int> &arr)
{
    int n = arr.size();
    vector<int> res(n, -1);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() >= arr[i])
            st.pop();
        if (!st.empty())
            res[i] = st.top();
        st.push(arr[i]);
    }
    return res;
}

/*
1. Goal:
    For every element in the array, find the next smaller element that appears to its right.
    If there’s no smaller element, store -1.

2. We’ll scan from right → left because we want to know what’s coming after each element.

3. Stack stores potential candidates for “next smaller” in increasing order (monotonic increasing stack).
    If the current element is smaller than or equal to the top of the stack →
    the stack’s top can’t be the next smaller element for anyone → pop it.

4. After popping bigger ones:
    If the stack is not empty, its top is the next smaller element for arr[i].
    Then push arr[i] onto the stack (it might be the “next smaller” for future elements).

5. At the end:
    res[i] holds the next smaller element for every arr[i].
*/