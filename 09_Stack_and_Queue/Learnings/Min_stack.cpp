#include <iostream>
#include <stack>
using namespace std;

class MinStack
{
public:
    stack<pair<int, int>> st;

    MinStack()
    {
    }

    void push(int val)
    {
        int miny;
        if (st.empty())
        {
            miny = val;
        }
        else
        {
            miny = min(st.top().second, val);
        }
        st.push({val, miny});
    }

    void pop()
    {
        st.pop();
    }

    int top()
    {
        return st.top().first;
    }

    int getMin()
    {
        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

/*
1. Use a stack of pairs (value, current_min)
   value → the actual element pushed
   current_min → the minimum element in the stack up to this point

2. Push(val):
   If the stack is empty, the minimum is val.
   Otherwise, take the minimum of val and the current minimum (st.top().second) and push it as the second element of the pair.
   This ensures the top of the stack always knows the minimum so far.

3. Pop():
   Simply remove the top pair.

4. Top():
   Return the first element of the top pair (the actual value).

5. getMin():
   Return the second element of the top pair (the current minimum).
*/