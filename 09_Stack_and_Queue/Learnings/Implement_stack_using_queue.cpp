#include <iostream>
#include <queue>
using namespace std;

class MyStack 
{
public:
    
    queue <int> q1;
    queue <int> q2;

    MyStack() 
    {
        
    }
    
    void push(int x) 
    {
        while(!q2.empty())
        {
            int x = q2.front();
            q2.pop();
            q1.push(x);
        }
        q2.push(x);
        while(!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
    }
    
    int pop() 
    {
        if(q2.empty())
            return 0;
        int x = q2.front();
        q2.pop();
        return x;
    }
    
    int top() 
    {
        return q2.front();
    }
    
    bool empty() 
    {
        return q2.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

/* Logic:
1. Push(x):
    First move everything from q2 → q1.
    Put the new element x into q2 (this makes sure the newest element is always at the front).
    Then move everything back from q1 → q2.
        Ensures the newest element stays at the front of q2 (so it behaves like stack top).

2. Pop():
    Just remove the front of q2 (since that’s the "top" of the stack).

3. Top():
    Look at the front of q2.

4. Empty():
    Check if q2 is empty.
*/