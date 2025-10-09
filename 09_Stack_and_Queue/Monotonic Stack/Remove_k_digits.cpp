#include <iostream>
#include <vector>
#include <stack>
using namespace std;

string removeKdigits(string num, int k)
{
    int n = num.size();
    stack<char> st;
    string res;

    if (n <= k)
        return "0";
    if (k == 0)
        return num;

    st.push(num[0]);

    for (int i = 1; i < n; i++)
    {
        while (k > 0 && !st.empty() && num[i] < st.top())
        {
            st.pop();
            k--;
        }
        st.push(num[i]);

        if (st.size() == 1 && num[i] == '0')
            st.pop();
    }

    while (k && !st.empty())
    {
        st.pop();
        k--;
    }

    while (!st.empty())
    {
        res.push_back(st.top());
        st.pop();
    }
    reverse(res.begin(), res.end());

    if (res.size() == 0)
        return "0";
    return res;
}

/*
Use a stack to build the smallest number.

For each digit:
    Pop larger digits from stack while k > 0 to keep number minimal.
    Push current digit.
    Skip leading zeros (don’t push if stack empty and digit = '0').

If digits still need removal after traversal, pop from end.

Reverse stack to get final result; return "0" if empty.
*/