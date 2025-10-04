#include <iostream>
#include <stack>
using namespace std;

class MyQueue
{
public:
    stack<int> s1;
    stack<int> s2;

    MyQueue()
    {
    }

    void push(int x)
    {
        s1.push(x);
    }

    int pop()
    {
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int x = s2.top();
        s2.pop();
        return x;
    }

    int peek()
    {
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }

    bool empty()
    {
        return s1.empty() && s2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

/*
Logic : 

1. Push(x):
    Just push the element into s1. (All new elements go into s1.)

2. Pop():
    If s2 is empty, pour everything from s1 → s2 (this reverses order, so the oldest element ends up on top of s2).
    Pop from s2 (which is the actual front of the queue).

3. Peek():
    Same as pop, but instead of removing, just return the top of s2.

4. Empty():
    Queue is empty only if both stacks are empty.
*/