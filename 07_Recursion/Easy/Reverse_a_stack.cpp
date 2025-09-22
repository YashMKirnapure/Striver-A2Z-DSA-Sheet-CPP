#include <iostream>
#include <stack>
using namespace std;

void func(stack<int> &st, int x)
{
    if (st.empty())
        st.push(x);
    else
    {
        int temp = st.top();
        st.pop();
        func(st, x);
        st.push(temp);
    }
}

void reverse(stack<int> &st)
{
    if (!st.empty())
    {
        int x = st.top();
        st.pop();
        reverse(st);
        func(st, x);
    }
}

/*
Step 1: Helper func(st, x)
This function inserts an element x at the bottom of the stack:
    If stack is empty → directly push x (base case).
    Otherwise:
        Pop the top element.
        Recursively call func to push x at the bottom.
        Push the popped element back.

Step 2: Main reverse(st)
This reverses the whole stack:
1. If stack is not empty:
    Pop the top element x.
    Recursively reverse the remaining stack.
    Use func to insert x at the bottom of the reversed smaller stack.

Effect:
    First popped element goes deepest.
    Last popped element stays at the top.
    => Stack is reversed.
*/